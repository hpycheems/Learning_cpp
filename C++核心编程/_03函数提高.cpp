#include <iostream>
using namespace std;

//������Ĭ�ϲ���
int func(int a, int b = 20, int c = 30) {
	return a + b + c;
}
//1 ���ĳ��λ���Ѿ�����Ĭ�ϲ�������ô�����λ�����󣬶�������Ĭ��ֵ
//int func1(int a, int b = 10, int c) {
//	return a + b + c;
//}

//2 �������������Ĭ�ϲ���������ʵ�ֲ�����Ĭ�ϲ��� ������
// ������ʵ��ֻ����һ������Ĭ�ϲ���
int func2(int a, int b);
int func2(int a = 10, int b = 10) {
	return a + b;
}

//������ռλ����
void func3(int a, int) {// Ŀǰ��ռλ�������ò���
	cout << "this is func3" << endl;
}
void func4(int a, int = 10) {// Ŀǰ��ռλ�������ò���
	cout << "this is func4" << endl;
}


//3 ��������
	// ͬһ��������
	// ��������ͬ
	// �����������Ͳ�ͬ���������ͬ ��˳��ͬ
  //��������ֵ������Ϊ��������
void func5() {
	cout << "func5 ����" << endl;
}

void func5(int a) {
	cout << "func5 ����" << a << endl;
}
void func5(double a) {
	cout << "func5 ����" << a << endl;
}
void func5(double a, int b) {
	cout << "func5 ����" << a << endl;
}
void func5(int a, double b) {
	cout << "func5 ����" << a << endl;
}
void func5(float a, double b) {
	cout << "func5(float a, double b) ����" << a << endl;
}
void func5(double a, float b) {
	cout << "func5(double a, float b) ����" << a << endl;
}
	//ע�����������Ϊ��������
	//			������������Ĭ�ϲ���
void func6(int& a) {
	cout << "func(int &a)����" << endl;
}
void func6(const int& a) {
	cout << "func(const int& a)����" << endl;
}

void func7(int a,int b = 10) {
	cout << "func7(int a,int b )����" << endl;
}
void func7(int a) {
	cout << "func7(int a)����" << endl;
}

// �������
//	������Ĭ�ϲ���
//  ������ռλ����
//  ��������
int main3() {
	
// C++�У��������β��б��еĲ���������Ĭ��ֵ
	cout << func(10,30) << endl;
	//���ĳ��λ���Ѿ�����Ĭ�ϲ�������ô�����λ�����󣬶�������Ĭ��ֵ
	//�������������Ĭ�ϲ���������ʵ�ֲ�����Ĭ�ϲ���
	cout << func2() << endl;

// C++�к������β��б��������ռλ������������ռλ�����ú����Ǳ������λ��
	//�﷨ ����ֵ���� ������ ���������ͣ�{}
	//ռλ������������Ĭ�ϲ���
	cout << "===================" << endl;
	func3(10,10);
	func4(10);

// ������������ͬ����߸�����
	cout << "===================" << endl;
	func5();
	func5(1);
	func5(3.14, 3.14f);
//ע������
	cout << "===================" << endl;
	int a = 10;
	func6(a);
	func6(20);

	//func7(10); ���ֶ����ԣ������Ĭ�ϲ���
	func7(10, 10);

	system("pause");
	return 0;
}