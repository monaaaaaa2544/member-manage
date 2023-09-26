#include <iostream>
#include "WorkerManager.h"

using namespace std;

int main()
{
    WorkerManager wm;

    int choice = 0;

    while (true)
    {
        wm.Show_Menu();
        cout << "input your choice:" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            wm.exitSystem();
            break;
        case 1: // 添加职工
            wm.Add_Emp();
            break;
        case 2: // 显示职工
            wm.Show_Emp();
            break;
        case 3: // 删除职工
            wm.Del_Emp();
            break;
        case 4: // 修改职工信息
            wm.Mod_Emp();
            break;
        case 5: // 查找职工
            wm.Find_Emp();
            break;
        case 6: // 排序职工
            wm.Sort_Emp();
            break;
        case 7: // 清空文件
            wm.Clean_File();
            break;
        default: //
            system("cls");
        }
    }

    system("pause");
    return 0;
}
