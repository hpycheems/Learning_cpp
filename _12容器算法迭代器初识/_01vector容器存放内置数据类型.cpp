#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

void func1_1(int val) {
	cout << val << endl;
}

int main1() {
	//����һ��vector����������
	vector<int> v;

	//�������в�������
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//vector<int>::iterator vBegin = v.begin();//���ص����� ���������ָ�������ĵ�һ��Ԫ��
	//vector<int>::iterator vEnd = v.end();//���ص����� ���������ָ�����������һ��Ԫ�ص���һ��λ��
	//vector<int>::iterator �õ�vector<int>�������͵ĵ�����
	
	//��һ�ֱ�������
	//while (vBegin != vEnd) {
	//	cout << *vBegin << endl;
	//	vBegin++;
	//}

	//�ڶ��ֱ�������
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	//�����ֱ�����ʽ
	for_each(v.begin(), v.end(), func1_1);

	system("pause");
	return 0;
}