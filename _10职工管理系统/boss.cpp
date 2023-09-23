#include "boss.h"
Boss::Boss(int id, string name, int dID)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dID;
}

void Boss::showInfo()
{
	cout << "职工编号: " << m_Id
		<< "\t  职工姓名: " << m_Name
		<< "\t  岗位: " << getDeptName()
		<< "\t  岗位职责： 给经理下发任务" << endl;
}

string Boss::getDeptName()
{
	return string("老板");
}

