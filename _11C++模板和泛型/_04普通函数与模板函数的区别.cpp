#include <iostream>
using namespace std;

//��ͨ�����뺯��ģ�������
// ��ͨ��������ʱ���Է����Զ�����ת������ʽ����ת����

void func(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}


// ����ģ�����ʱ����������Զ������Ƶ������ᷢ����ʽ����ת��

// ���������ʽָ�����͵ķ�ʽ�����Է�����ʽ����ת��
template<class T>
void func1(T a, T b) {
	T temp = a;
	a = b;
	b = temp;
}

void test4_1() {
	int a = 10;
	int b = 20;
	char c = 'c';
	func(a, c);//��ʽ����ת��

	//func1(a, c);//���� ���Զ��Ƶ����Ͳ��ܷ�������ʽ��ת��
	func1<int>(a, c);//��ȷ
}

int main4() {
	test4_1();
	system("pause");
	return 0;
}