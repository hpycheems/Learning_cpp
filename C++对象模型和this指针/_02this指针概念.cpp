#include <iostream>
using namespace std;
#include<string>
//
// ÿһ���Ǿ�̬��Ա����ֻ�ᵮ��һ�ݺ���ʵ������ͬ���Ͷ���Ṳ��һ�����
// ���⣺��һ���������������ĸ���������Լ����أ�
// C++ͨ���ṩ����ָ������thisָ������������ ��
// thisָ�� ָ�� �����õĳ�Ա���� ��������

// thisָ����������ÿһ���Ǿ�̬��Ա�����ڵ�һ��ָ��
// thisָ�벻��Ҫ���壬ֱ��ʹ�ü���

//this ָ�����;��
// ���βκͳ�Ա����ͬ��ʱ������thisָ��������
// ����ķǾ�̬��Ա�����з��ض�������ʹ��return *this

class Person {
public:
	Person(int age) {
		this->age = age;
	}

	Person& PersonAddAge(const Person & p) {
		age += p.age;
		cout << this << endl;
		return *this;
	}

	int age;
};

// thisָ�������Ƴ�ͻ
void test2_1() {
	Person p(20);
	cout << "p������Ϊ��" << p.age << endl;
}
//���ض�������*this
void test2_2() {
	Person p1(10);
	Person p2(10);
	//��ʽ���˼��
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
	cout << "p2������:" << p2.age<<endl;
}
int main2() {
	//test2_1();

	test2_2();
	system("pause");
	return 0;
}