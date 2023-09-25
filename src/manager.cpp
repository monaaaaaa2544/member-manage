#include "manager.h"
#include <string>

Manager ::Manager(int id, string name, int did)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = did;
}

void Manager::showInfo()
{
    cout << "id:" << this->m_Id
         << "\tname: " << this->m_Name
         << "\tdept: " << this->getDeptName()
         << "\tJob responsibilities: completing tasks given by boss " << endl;
}

string Manager::getDeptName()
{
    return string("manager");
}