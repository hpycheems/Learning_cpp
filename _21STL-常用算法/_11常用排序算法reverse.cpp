#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

/*
reverse: ��������Ԫ�ؽ��з�ת
ԭ�ͣ�
	reverse(iterator beg, iterator end);
	��תָ����Χ��Ԫ��

*/
void printFunc3(int val) {
	cout << val << " ";
}
void test11() {

	vector<int> v;
	for (int i = 0; i < 5; i++)
	{
		v.push_back(i);
	}

	cout << "��תǰ" << endl;

	for_each(v.begin(), v.end(), printFunc3);
	cout << endl;

	cout << "��ת��" << endl;
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), printFunc3);
	cout << endl;
	
}

int mai11n() {
	test11();

	system("pause");
	return 0;
}