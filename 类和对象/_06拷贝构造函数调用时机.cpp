#include <iostream>
using namespace std;
#include<string>

//�������캯������ʱ��
class MyClass {
public:
	MyClass() {
		cout << "MyClass Ĭ�Ϲ��캯����" << endl;
	}
	MyClass(int age) {
		cout << "MyClass �вι��캯����" << endl;
		m_Age = age;
	}
	MyClass(const MyClass& m) {
		cout << "MyClass �������캯����" << endl;
		m_Age = m.m_Age;
	}
	~MyClass() {
		cout << "MyClass �������캯����" << endl;
	}

private:
	int m_Age;
};
// ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void func1() {
	MyClass m1(20);
	MyClass m2(m1);
}
 
// ֵ���ݵķ�ʽ��������ֵ
void func2(MyClass m) {

}

MyClass doWork() {
	MyClass m;
	cout << (int)&m << endl;
	return m;
}

// ��ֵ��ʽ���ؾֲ�����
void func3() {
	MyClass m = doWork();//�������Զ��Ż� ��������²��ᴥ���������캯��
	//m = doWork();
	cout << (int)&m << endl;
}

int main6() {

	//func1();

	//MyClass m(30);
	//func2(m);

	func3();

	system("pause");
	return 0;
}