# member-manage
基于多态的职工管理系统


# 需求

管理职工信息

三种职工：
- 普通员工
- 经理
- 老板

职工：职工编号，职工姓名、岗位、职责

功能：
- 退出管理系统
- 新增职工信息
- 显示职工信息
- 删除离职职工：按编号删除
- 修改职工信息：按编号修改
- 查找职工信息：1. 按编号 2. 按姓名
- 按编号排序：排序规则由用户指定
- 清空所有文档：清空前需要再次确认，防止误操作


# 创建管理类
- 菜单界面
- 对职工增删改查
- 与文件的读写交互

# 菜单功能
- Show_Menu()函数，显示菜单

# 退出功能
- 菜单中选择0，exit(0)退出系统

# 创建职工类
- 创建职工类__抽象类
- 创建普通员工类
- 创建经理类
- 测试多态 virtual

测试多态：
```
#include "worker.h"
#include "employee.h"
#include "manager.h"
using namespace std;

int main()
{
    // 测试多态
    Worker *wk1 = new Employee(1, "lxy", 3);
    cout << wk1->getDeptName() << endl;
    delete wk1;

    Worker *wk2 = new Manager(2, "cyy", 2);
    cout << wk2->getDeptName() << endl;
    delete wk2;
    return 0;
}
```

# 添加职工功能
- 所有员工信息放到数组中，维护这个不定长数组，将数组创建到堆区，用worker的指针维护
-  
# 文件交互-写文件

# 文件交互-读文件

# 显示职工功能

# 删除职工功能

# 修改职工功能

# 查找职工功能

# 排序

# 清空文件