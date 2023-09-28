#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

/*
���
 STL�ڽ���һЩ��������
���ࣺ
	�����º���
	��ϵ�º���
	�߼��º���
�÷���
	��Щ�º����������Ķ����÷���һ�㺯����ȫ��ͬ
	ʹ���ڽ�����������Ҫ����ͷ�ļ�#include <functional>
*/

/*
�����º�����
 ʵ����������
 negate һԪ�º��� ȡ��

 plus ��Ԫ�º��� �ӷ�
 minus ����
 multiplies �˷�
 divides ����
 modulus ȡģ

��ϵ�º�����
	equal_to ����
	not_equal_to ������
	greater ����
	greater_equal ���ڵ���
	less С��
	less_equal С�ڵ���

�߼��º�����
	logical_ont ��
	logical_or ��
	logical_and ��
*/
//negate ȡ��
void test3_1() {
	negate<int> n;
	cout << n(50) << endl;
}
//plus
void test3_2() {
	plus<int> p;
	cout << p(10, 20) << endl;
}

//��ϵ�º���
void test3_3() {
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(10);
	v.push_back(40);

	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//�߼��º���
void test3_4() {
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	vector<bool > v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
	test3_1();
	test3_2();
	test3_3();
	test3_4();
	system("pause");
	return 0;
}