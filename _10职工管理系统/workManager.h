#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
#define FILENAME "empFile.txt"

class workManager {

public:
	int m_EmpNum;
	//Ա������ָ��
	WorKer** m_EmpArray;
	bool m_FileIsEmpty;

	workManager();

	void Show_Menu();
	
	void ExitSystem();
	void AddWorker();
	void save();
	int get_EmpNum();
	void init_Emp();
	void ShowEmp();
	int isExist(int id);
	void Del_Emp();
	void Mod_Emp();
	void Find_Emp();
	void Sort_Emp();
	void Clear_File();

	~workManager();
};