#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

/*
accumulate: ���������� ����Ԫ���ۼ��ܺ�
ԭ�ͣ�
	accumulate(iterator beg, iterator end, value)
	value ��ʼֵ
*/

void test16_1() {

	vector<int> v;
	for (int i = 1; i <= 100; i++)
	{
		v.push_back(i);
	}

	//����3 ��ʼ�ۼ�ֵ
 	int sum = accumulate(v.begin(), v.end(), 1);
	cout << "��1�ӵ�100Ϊ" << sum << endl;
}
int main16() {

	test16_1();
	system("pause");
	return 0;
}