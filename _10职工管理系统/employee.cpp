#include "employee.h"

Employee::Employee(int id, string name, int dID)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dID;
}

void Employee::showInfo()
{
	cout << "ְ�����: " << m_Id
		<< "\t  ְ������: " << m_Name
		<< "\t  ��λ: " << getDeptName()
		<< "\t  ��λְ�� ��ɾ����ŵĹ���" << endl;
}

string Employee::getDeptName()
{
	return string("Ա��");
}
