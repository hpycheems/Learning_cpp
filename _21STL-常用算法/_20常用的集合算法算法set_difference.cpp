#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*

set_difference: ���������ϵĲ
ԭ�ͣ�
	set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
	�������ϱ�������������
	dest Ŀ��������ʼ������
	*/

void test20_1() {

	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v2.push_back(i);
		v1.push_back(i + 5);
	}

	vector<int> vTarget;
	//���ٿռ�
	//����������������϶������ڽ��� ���ٿռ������Ǹ�
	vTarget.resize(max(v1.size(), v2.size()));//56.08

	vector<int> ::iterator pos = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for (vector<int>::iterator it = vTarget.begin(); it != pos; it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main() {


	test20_1();
	system("pause");
	return 0;
}
