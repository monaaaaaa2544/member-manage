#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include <fstream>
#define FILENAME "empFile.txt"

WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    //====================================================== 初始化数据

    // 1. 文件不存在
    if (!ifs.is_open())
    {
        cout << "file is not create!" << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }

    // 2. 文件存在且内容为空
    char ch;
    ifs >> ch; // 先读一个末尾字符
    if (ifs.eof())
    {
        cout << "file is empty!" << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }

    // 3. 文件存在且获取职工人数
    int num = this->get_EmpNum();
    cout << "the people number is:" << num << endl;
    this->m_EmpNum = num;
    if (num > 0)
    {
        this->m_FileIsEmpty = false;
    }

    //=========================================根据职工数据初始化数组 m_EmpArray指针
    this->m_EmpArray = new Worker *[this->m_EmpNum]; // 开辟空间
    this->init_Emp();                                // 文件数据存入数组中

    // 测试代码
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        cout << "Id:" << this->m_EmpArray[i]->m_Id
             << "\tName:" << this->m_EmpArray[i]->m_Name
             << "\tDep:" << this->m_EmpArray[i]->m_DeptId
             << endl;
    }
}

// 显示菜单
void WorkerManager::Show_Menu()
{
    cout << "***************************************" << endl;
    cout << "*************0.exit system*************" << endl;
    cout << "*************1.add member*************" << endl;
    cout << "*************2.show member*************" << endl;
    cout << "*************3.delete member*************" << endl;
    cout << "*************4.alter member*************" << endl;
    cout << "*************5.search member*************" << endl;
    cout << "*************6.sort by number*************" << endl;
    cout << "*************7.clear document*************" << endl;
    cout << "***************************************" << endl;
    cout << endl;
}

void WorkerManager::exitSystem()
{
    cout << "bye bye" << endl;
    system("pause");
    exit(0);
}

void WorkerManager::Add_Emp()
{
    cout << "please input people number:" << endl;

    int addNum = 0;
    cin >> addNum;

    if (addNum > 0)
    {
        // 计算员工数组需要的空间大小
        int newSize = this->m_EmpNum + addNum; // 新空间人数=原来记录人数+新增人数

        // 开辟新空间
        Worker **newSpace = new Worker *[newSize];

        // 原空间内容拷贝道新空间下
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        // 输入新数据
        for (int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int dSelect;

            cout << "please input the " << i + 1 << " people's id:" << endl;
            cin >> id;
            cout << "please input the " << i + 1 << " people's name:" << endl;
            cin >> name;

            cout << "plase select department of the people:" << endl;
            cout << "1. employee" << endl;
            cout << "2. manager" << endl;
            cin >> dSelect;

            Worker *wk = NULL;
            switch (dSelect)
            {
            case 1:
                wk = new Employee(id, name, 1);
                break;
            case 2:
                wk = new Manager(id, name, 2);
                break;
            }

            newSpace[this->m_EmpNum + i] = wk;
        }
        // 释放原有空间
        delete[] this->m_EmpArray;

        // 更改新空间指向
        this->m_EmpArray = newSpace;

        this->m_EmpNum = newSize;

        this->save();

        // cout << **newSpace << endl;
        cout
            << "you add operation is success!" << endl;
    }
    else
    {
        cout << "input error" << endl;
    }

    system("pause");
    system("cls");
}

void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << " " << endl;
    }
    this->m_FileIsEmpty = false;

    ofs.close();
}

// 获取职工数量
int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    { // 一行一行的读
        num++;
    }
    return num;
}

// 初始化职工数组指针
void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker *wk = NULL;
        if (dId == 1)
        {
            wk = new Employee(id, name, dId);
        }
        else if (dId == 2)
        {
            wk = new Manager(id, name, dId);
        }
        this->m_EmpArray[index] = wk;
        index++;
    }

    ifs.close();
}

void WorkerManager::Show_Emp()
{
    if (this->get_EmpNum() == 0)
    {
        cout << "record is empty" << endl;
    }
    else
    {
        // 利用多态调用各自show_info接口
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::Del_Emp()
{
    if (this->get_EmpNum() == 0)
    {
        cout << "database is empty" << endl;
        return;
    }

    cout << "input id which you want to delete:" << endl;
    int id = 0;
    cin >> id; // 输入删除的职工的编号

    int wkIndex = this->IsExist(id);
    if (wkIndex == -1)
    { // 职工不存在
        cout << "the people is not in database!" << endl;
    }
    else
    { // 职工存在，删除职工，后面的职工数据前移
        for (int i = wkIndex; i < this->m_EmpNum - wkIndex; i++)
        {
            this->m_EmpArray[i] = this->m_EmpArray[i + 1];
        }
        this->m_EmpNum--;
        this->save();
        cout << "delete success!" << endl;
    }
    system("pause");
    system("cls");
}

int WorkerManager::IsExist(int id)
{
    int Index = -1;

    for (int i = 0; i < this->m_EmpNum; i++)
    {
        if (id == this->m_EmpArray[i]->m_Id)
        {
            // 找到职工
            Index = i;
            break;
        }
    }
    return Index;
}

void WorkerManager::Mod_Emp()
{
    if (this->get_EmpNum() == 0)
    {
        cout << "the record is empty" << endl;
    }
    else
    {
        cout << "please input id of the people:" << endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);
        if (ret != -1)
        {
            // 查找到编号的职工
            delete this->m_EmpArray[ret];

            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout << "find " << id << " th people, please input new id:" << endl;
            cin >> newId;

            cout << "please input new name:" << endl;
            cin >> newName;

            cout << "please input new dep:" << endl;
            cin >> dSelect;

            Worker *wk = NULL;
            switch (dSelect)
            {
            case 1:
                wk = new Employee(newId, newName, dSelect);
                break;
            case 2:
                wk = new Manager(newId, newName, dSelect);
                break;
            }

            this->m_EmpArray[ret] = wk;
            this->save();

            cout << "alter success!" << endl;
        }
        else
        {
            cout << "fail to alter, have no this people" << endl;
        }
    }
}

void WorkerManager::Find_Emp()
{
    if (this->get_EmpNum() == 0)
    {
        cout << "the database is empty" << endl;
        return;
    }

    cout << "which method do you want to use?" << endl;
    cout << "1. use Id" << endl;
    cout << "2. use Name" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    { // 按职工编号查找
        cout << "input id:" << endl;
        int id;
        cin >> id;

        int ret = IsExist(id);
        if (ret != -1)
        {
            cout << "search success!" << endl;
            this->m_EmpArray[ret]->showInfo();
        }
        else
        {
            cout << "search fail, no this id" << endl;
        }
    }
    else if (select == 2)
    { // 按职工姓名查找
        cout << "input name:" << endl;
        string name;
        cin >> name;

        bool isFinded = false;
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            if (this->m_EmpArray[i]->m_Name == name)
            {
                isFinded = true;
                cout << "search success!" << endl;
                this->m_EmpArray[i]->showInfo();
            }
        }
        if (isFinded == false)
            cout << "search fail,no this name" << endl;
    }
    else
    {
        cout << "input error" << endl;
    }
    system("pause");
    system("cls");
}

void WorkerManager::Sort_Emp()
{
    if (this->get_EmpNum() == 0)
    {
        cout << "the database is empty" << endl;
        return;
    }

    cout << "asc or desc?" << endl;
    cout << "1. asc" << endl;  // 升序
    cout << "2. desc" << endl; // 降序

    int select = 0;
    cin >> select;

    // 选择排序
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        int minOrMax = i;
        for (int j = i + 1; j < this->m_EmpNum; j++)
        {
            if (select == 1)
            { // 升序
                if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
                {
                    minOrMax = j;
                }
            }
            else if (select == 2)
            { // 降序
                if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
                {
                    minOrMax = j;
                }
            }
        }

        if (i != minOrMax)
        {
            // 交换
            Worker *temp = this->m_EmpArray[i];
            this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
            this->m_EmpArray[minOrMax] = temp;
        }
    }

    cout << "sort success" << endl;
    this->save();
    this->Show_Emp();
}

void WorkerManager::Clean_File()
{
    ofstream ofs(FILENAME, ios::trunc);
    ofs.close();

    if (this->m_EmpArray != NULL)
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            // 删除每一个职工
            delete this->m_EmpArray[i];
            this->m_EmpArray[i] = NULL;
        }
        // 删除堆区数组指针
        this->m_EmpNum = 0;
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
    this->m_FileIsEmpty = true;

    cout << "clean success" << endl;
}

WorkerManager::~WorkerManager()
{
    if (this->m_EmpArray != NULL)
    {
        delete[] this->m_EmpArray;
    }
}
