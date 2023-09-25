#include "employee.h"
#include <string>

Employee ::Employee(int id, string name, int did)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = did;
}

void Employee::showInfo()
{
    cout << "id:" << this->m_Id
         << "\tname: " << this->m_Name
         << "\tdept: " << this->getDeptName()
         << "\tJob responsibilities: completing tasks given by manager " << endl;
}

string Employee::getDeptName()
{
    return string("employee");
}