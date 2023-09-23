#include "employee.h"

Employee::Employee(int id, string name, int dID)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dID;
}

void Employee::showInfo()
{
	cout << "职工编号: " << m_Id
		<< "\t  职工姓名: " << m_Name
		<< "\t  岗位: " << getDeptName()
		<< "\t  岗位职责： 完成经理安排的工作" << endl;
}

string Employee::getDeptName()
{
	return string("员工");
}
