#include <iostream>
using namespace std;
//��ͨ���еĳ�Ա����һ��ʼʱ�ʹ���
//��ģ���г�Ա�����ڵ���ʱ��ȥ����
class Person1 {
public:
	void func1() {

	}
};

class Person2 {
public :
	void func2() {

	}
};

template<class T>
class Person {
public:
	T obj;

	void func1() {
		obj.func1();
	}

	void func2() {
		obj.func2();
	}
};
void test9_1() {
	Person<Person2> p;
	//p.func1();
	p.func2();
}

int main9() {

	system("pause");
	return 0;
}