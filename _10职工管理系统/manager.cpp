#include "manager.h"

Manager::Manager(int id, string name, int dID)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dID;
}

void Manager::showInfo()
{
	cout << "ְ�����: " << m_Id
		<< "\t  ְ������: " << m_Name
		<< "\t  ��λ: " << getDeptName()
		<< "\t  ��λְ�� ����ϰ尲�ŵĹ����������·������Ա��" << endl;
}

string Manager::getDeptName()
{
	return string("����");
}
