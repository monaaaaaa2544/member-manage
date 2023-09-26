#pragma once
#include <iostream>
#include "worker.h"

using namespace std;

class WorkerManager
{
public:
	int m_EmpNum; // 当前员工数
	bool m_FileIsEmpty = true;

	Worker **m_EmpArray; // 员工数组的指针
	WorkerManager();

	void Show_Menu();
	void exitSystem();
	void Add_Emp();
	void save();
	int get_EmpNum();
	void init_Emp();
	void Show_Emp();
	void Del_Emp();
	int IsExist(int Id);
	void Mod_Emp();
	void Find_Emp();
	void Sort_Emp();
	void Clean_File();

	~WorkerManager();
};
