#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>


/*
sort: ��������Ԫ�ؽ�������
ԭ�ͣ�
	sort(iteraotr beg, iterator end, _Pred)
	���������е�Ԫ�� �� Ĭ�ϴ�С����
	����ͨ�� _Pred�ı�����ʽ
*/

void printFunc(int val) {
	cout << val << " ";
}

void test8_1() {
	vector<int> v;
	v.push_back(20);
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(40);
	v.push_back(15);

	//Ĭ��Ϊ��������
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), printFunc);
	cout << endl;

	//��������
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), printFunc);
	cout << endl;
}

int main8() {

	test8_1();

	system("pause");
	return 0;
}