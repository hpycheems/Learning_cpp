#include "manager.h"

Manager::Manager(int id, string name, int dID)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dID;
}

void Manager::showInfo()
{
	cout << "职工编号: " << m_Id
		<< "\t  职工姓名: " << m_Name
		<< "\t  岗位: " << getDeptName()
		<< "\t  岗位职责： 完成老板安排的工作，并且下发任务给员工" << endl;
}

string Manager::getDeptName()
{
	return string("经理");
}
