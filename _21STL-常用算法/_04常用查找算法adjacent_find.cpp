#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
adjacent_find�����������ظ�Ԫ��
ԭ��
adjacent_find(iterator beg, iterator end);
���������ظ�Ԫ�أ���������Ԫ�صĵ�һ��λ�õĵ�����
adjacent_find
*/

void test4_1() {

	vector<int > v;

	v.push_back(0);
	v.push_back(0);
	v.push_back(1);
	v.push_back(3);
	v.push_back(0);
	v.push_back(3);
	//v.push_back(3);

	vector<int>::iterator it = adjacent_find(v.begin(), v.end());

	if (it != v.end()) {
		cout << "���ҵ��ظ�����Ԫ��" << *it << endl;
	}
	else {
		cout << "δ���ҵ��ظ�����Ԫ��" << endl;
	}
}

int main() {
	test4_1();

	system("pause");
	return 0;
}