#include <iostream>
using namespace std;
//C++��һ�б��˼���Ϊ ���ͱ�̣���Ҫ���õļ�������ģ��
//C++�ṩ����ģ����ƣ�����ģ�����ģ��

//ģ�岻����ֱ��ʹ�ã���ֻ��һ�����
//ģ���ͨ�ò���������

//����ģ���﷨
//����ģ�����ã�����һ��ͨ�ú������亯������ֵ���ͺ��β����Ϳ��Բ����嶨�ƣ���һ�����������������
// �﷨��template<typename T> ������������
// template -- ��������ģ��
// tempname -- ��ʾ�����ķ�����һ���������ͣ�����class����
// T -- ͨ�õ��������ͣ����ƿ����滻��ͨ��Ϊ��д��ĸ



template<typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

int main1() {

	int a = 10;
	int b = 20;
	//�Զ��Ƶ�
	mySwap(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	double d1 = 1.1;
	double d2 = 2.2;
	//��ʽָ������
	mySwap<double>(d1, d2);

	cout << "d1 = " << d1 << endl;
	cout << "d2 = " << d2 << endl;

	system("pause");
	return 0;
}