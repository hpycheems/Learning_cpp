#include "boss.h"
Boss::Boss(int id, string name, int dID)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dID;
}

void Boss::showInfo()
{
	cout << "ְ�����: " << m_Id
		<< "\t  ְ������: " << m_Name
		<< "\t  ��λ: " << getDeptName()
		<< "\t  ��λְ�� �������·�����" << endl;
}

string Boss::getDeptName()
{
	return string("�ϰ�");
}

