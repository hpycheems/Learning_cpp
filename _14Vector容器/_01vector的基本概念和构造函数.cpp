#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//�������� �������β�˽��в���ɾ��
//�����Ǿ�̬�ռ䣬vector���Զ�̬��չ

//��̬��չ
//������ԭ�ռ�֮���������¿ռ䣬�����Ҹ���Ŀռ䣬Ȼ�󿽱����ݵ��¿ռ䣬Ȼ���ͷžÿռ�

//vector�����ĵ�������֧��������ʵĵ�����


//vector�Ĺ���
/*
vector<T> v;
vector(v.begin(), v.end());
vector(n,elem); //���캯����n��elem����������
vector(const vector &vec);
*/

void printVector(vector<int>& v) {
	for (vector<int>::iterator it= v.begin() ; it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test1_1() {
	vector<int> v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int>v2(v1.begin(), v1.end());
	printVector(v2);

	vector<int>v3(10, 100);
	printVector(v3);

	vector<int> v4(v3);
	printVector(v4);
}

int main1() {

	test1_1();

	system("pause");
	return 0;
}