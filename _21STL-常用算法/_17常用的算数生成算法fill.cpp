#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

/*
fill: �����������ָ����Ԫ��
ԭ�ͣ�
	fill(iterator beg, iterator end, value);
	value ���ֵ
*/

void test17_1() {

	vector<int> v;
	v.resize(10, 1);

	//������д�������
	fill(v.begin(), v.end(), 1000);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main17() {
	test17_1();
	system("pause");
	return 0;
}