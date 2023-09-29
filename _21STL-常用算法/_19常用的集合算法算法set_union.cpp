#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
set_union: ���������ϵĲ���
ԭ�ͣ�
	set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
	ע�⣺�������ϱ�������������
	dest��Ŀ��������ʼ������
*/


void test19_1() {
	vector<int> v;
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		v1.push_back(i + 5);
	}

	vector<int> vTarget;
	//���� �ռ� ����������� ����������û�� ��ͬ��Ԫ��
	vTarget.resize(v.size() + v1.size());

	vector<int>::iterator pos = 
		set_union(v.begin(), v.end(), v1.begin(), v1.end(), vTarget.begin());
	for (vector<int>::iterator it = vTarget.begin(); it != pos; it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

int main19() {

	test19_1();

	system("pause");
	return 0;
}