#include <iostream>
using namespace std;

//ע�����
// �Զ��Ƶ��������Ƶ���һ�µ��������ͣ��ſ�ʹ��
template<class T>//typemane �����滻��class Ч����һ��
void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
void test2_1() {
	int a = 10;
	int b = 20;
	char c = 'a';

	//Swap(a, b);//��ȷ����
	// Swap(a, c);//����
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

}
// ģ�����Ҫȷ����T���������ͣ��ſ�ʹ��
template<class T>
void func() {
	cout << "func��������" << endl;
}
void test2_2() {
	func<char>();//����ָ��ģ������
}


int main2() {

	//test2_1();
	test2_2();
	system("pause");
	return 0;
}