#pragma once

using namespace std;
#include <vector>

class Student;

class Person
{
public:
	Person(Student* student);
	void checkParent();
private:
	vector<Student*> m_Student;
};

