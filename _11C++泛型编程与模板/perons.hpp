#pragma once
template<class T1,class T2>
class Person {
public:

	Person(T1 name, T2 age);
	void func();
	T1 m_Name;
	T2 m_Age;
};

template<class T1, class T2>
Person<T1, T2>::Person(T1 name,T2 age) {

}

template<class T1, class T2>
void Person<T1, T2>::func() {

}