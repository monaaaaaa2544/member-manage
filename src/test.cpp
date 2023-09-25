#include "worker.h"
#include "employee.h"
#include "manager.h"
using namespace std;

int main()
{
    // 测试多态
    Worker *wk1 = new Employee(1, "lxy", 3);
    wk1->showInfo();
    delete wk1;

    Worker *wk2 = new Manager(2, "cyy", 2);
    wk2->showInfo();
    delete wk2;
    return 0;
}