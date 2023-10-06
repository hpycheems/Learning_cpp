#include "Person.h"
#include"Student.h"//在Cpp文件中包含它的实现

Person::Person(Student* student)
{
	m_Student.push_back(student);
}

void Person::checkParent()
{
	for (auto child : m_Student) {

	}
}
