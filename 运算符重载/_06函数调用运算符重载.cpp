#include<iostream>
using namespace std;
#include<string>
//�����������������
// �����������������Ҳ��������
// �������غ�ʹ�õķ�ʽ�ǳ������ĵ��ã���˳�Ϊ�º���
// �º���û�й̶�д�����ǳ����

class MyPrint {
public :
	//�º��� ()���������� 
	void operator()(string text) {
		cout << text << endl;
	}

};

void test6_1() {
	MyPrint m;
	m("Hello World!");

}
//�º���û�й̶�д�����ǳ����

class MyAdd {
public:
	int operator()(int num1, int num2) {
		return num1 + num2;
	}
};

void test6_2() {
	MyAdd m;
	int ref = m(10, 20);
	cout << ref << endl;

	//������������
	cout << MyAdd()(20, 30) << endl;
}

int main6() {

	//test6_1();

	test6_2();

	system("pause");
	return 0;
}