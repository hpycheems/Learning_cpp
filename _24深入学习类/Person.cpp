#include "Person.h"
#include"Student.h"//��Cpp�ļ��а�������ʵ��

Person::Person(Student* student)
{
	m_Student.push_back(student);
}

void Person::checkParent()
{
	for (auto child : m_Student) {

	}
}
