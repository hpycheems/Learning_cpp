#include <iostream>
using namespace std;
#include<string>
const double PI = 3.14;
//C++��������������������װ���̳С���̬
/* 
  ��װ
	���壺
	�����Ժ���Ϊ��Ϊһ�����壬���������е�����
	�����Ժ���Ϊ����Ȩ�޿���
	�������ʱ�����Ժ���Ϊд��һ�𣬱�������
	class ����{����Ȩ�ޣ�����/��Ϊ};
	�������
	�������ʱ�����԰����Ժ���Ϊ���ڲ�ͬ��Ȩ���£����Կ���
	����Ȩ�������֣�
		1 public ����		��Ա �����ڿɷ��ʣ�����Ҳ�ɷ���
		2 protected ����		��Ա ���ڿ��Է��ʣ����ⲻ�ɷ��� ����Ҳ�ɷ��ʸ��ౣ������
		3 private ˽��		��Ա ���ڿ��Է��ʣ����ⲻ�ɷ��� ����Ҳ���ɷ���
*/
class Circle 
{
public://����Ȩ��
	float m_r;
	double calculateZC() {
		return 2 * PI * m_r;
	}
};


class Student {
public:
	string name;
	int number;
	Student(string name, int number) :name(name), number(number) {}
	void showStudent() {
		cout << "ѧ��������" << name << endl;
		cout << "ѧ��ѧ�ţ�" << number << endl;
	}
	void setName(string name) {
		this->name = name;
	}
	void setNumber(int number) {
		this->number = number;
	}
};

class Person {
public:
	string m_Name;
	void fun() {
		m_Name = "zs";
		m_Car = "bm";
		m_Password = 123;
	}
protected:
	string m_Car;

private:
	int m_Password;
};
//struct �� class ������
// struct Ĭ��Ȩ���� public
// class Ĭ��Ȩ���� private
class C1 {
	int m_A;
};
struct S1 {
	int m_A;
};

//��Ա���Ե�˽�л�
// �����Լ����ƶ�дȨ��
// ����д���Լ�����ݵ���Ч��
class Person1 {
private:
	string m_Name;
	int m_Age;
	string m_Lover;
public:
	void set_Name(string name) {
		m_Name = name;
	}
	string get_Name() {
		return m_Name;
	}
	void set_Age(int age) {
		if (age > 0 && age < 150) {
			m_Age = age;
		}
		else {
			m_Age = 0;
			cout << "������������" << endl;
		}
	}
	int get_Age() {
		return m_Age;
	}
	string set_Lover(string lover){
		m_Lover = lover;
	}
};

int main1() {
	//ͨ��Բ�� ���������Բ������
	Circle c1;
	c1.m_r = 2;
	cout << "Բ���ܳ���" << c1.calculateZC() << endl;
	cout << "===============" << endl;
	Student s1("����",1001);
	s1.showStudent();

	Person p1;
	p1.m_Name = "ls";
	//p1.m_Car = "tlj";
	//p1.m_Password = 321;

	C1 c3;
	//c1.m_A = 10;

	S1 c2;
	c2.m_A = 10;

	cout << "==============" << endl;
	Person1 person1;
	person1.set_Name("����");
	person1.set_Age(200);

	cout << person1.get_Name() << endl;
	cout << person1.get_Age() << endl;

	//cout << person1.m_Lover << endl;

	system("pause");
	return 0;
}