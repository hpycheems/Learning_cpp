#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//ʵ������������Ԫ�ؽ��л���
//swap(vec)

void printVector6(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//�����÷� ������������������
void test6_1() {
	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}

	vector<int> v2;
	for (int i = 5; i < 10; i++)
	{
		v2.push_back(i);
	}

	cout << "����ǰ" << endl;
	cout << "v1:";
	printVector6(v1);
	cout << "v1:";
	printVector6(v2);

	cout << "������" << endl;
	v1.swap(v2);
	cout << "v1:";
	printVector6(v1);
	cout << "v1:";
	printVector6(v2);

}

//ʹ�ð��� �����ڴ� ���һ�����������˺ܶ�Ŀռ䣬��ֻʹ���˺�С��һ���� ��������ڴ�
void test6_2() {
	vector<int> v1;
	for (int i = 0; i < 10000; i++)
	{
		v1.push_back(i);
	}

	cout << "v1 ������" << v1.capacity() << endl;
	cout << "v1 �Ĵ�С" << v1.size() << endl;

	v1.resize(3);
	cout << "v1 ������" << v1.capacity() << endl;
	cout << "v1 �Ĵ�С" << v1.size() << endl;

	vector<int>(v1).swap(v1);//������������ʱ����ᱻϵͳ�Զ�����
	cout << "v1 ������" << v1.capacity() << endl;
	cout << "v1 �Ĵ�С" << v1.size() << endl;

}

int main6() {

	test6_2();

	system("pause");
	return 0;
}