#include<iostream>
using namespace std;

/*
���
 ���غ������ò��������࣬����󳣳�Ϊ��������
 ��������ʹ�����صģ���ʱ����Ϊ���ƺ������ã�Ҳ�зº���
���ʣ�
	����������һ���࣬����һ������
	
�º����ǳ���������Ϊ����

��������ʹ�ã�
 �ص㣺
	����������ʹ��ʱ����������ͨ�����������ã�Ҳ�����в����������з���ֵ
	�������󳬳���ͨ�����ĸ����������������Լ���״̬
	�������������Ϊ��������
*/

//����������ʹ��ʱ����������ͨ�����������ã�Ҳ�����в����������з���ֵ
class MyAdd{
public:
	int operator()(int num1, int num2) {
		return num1 + num2;
	}
};
void test1_1() {

	MyAdd m;
	cout << m(10, 20) << endl;
}
//�������󳬳���ͨ�����ĸ����������������Լ���״̬
class MyPrint {
public:
	MyPrint() {
		this->count = 0;
	}
	int count;
	void operator()(string text) {
		cout << text << endl;
		count++;
	}
};
void test1_2() {
	MyPrint m;
	m("hello ");
	m("hello ");
	m("hello ");
	m("hello ");
	cout << m.count << endl;
}
//�������������Ϊ��������

void doPrint(MyPrint& m, string text) {
	m(text);
}

void test1_3() {
	MyPrint m;
	doPrint(m, "C++");
}

int main1(){
	test1_1();
	test1_2();
	test1_3();
	system("pause");
	return 0;
}