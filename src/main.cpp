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
            break;
        case 2: // 显示职工
            break;
        case 3: // 删除职工
            break;
        case 4: //
            break;
        case 5: //
            break;
        case 6: //
            break;
        case 7: // 排序职工
            break;
        default: // 清空文件
            system("cls");
        }
    }

    system("pause");
    return 0;
}