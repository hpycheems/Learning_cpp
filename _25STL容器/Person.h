#pragma once
#include <iostream>
class Person {
private:
	int m_age;
	std::string m_name;
public:
	Person(int age, std::string name) :m_age(age), m_name(std::move(name)) {}
	int age()const { return m_age; }
	const std::string& name() const { return m_name; }
	void print() const { std::cout << m_age << " : " << m_name << "\n"; }
	void changeAge(int newAge) { m_age = newAge; }
	bool operator ==(Person const& rhs)const {
		return m_age == rhs.m_age && m_name == rhs.m_name;
	}
};