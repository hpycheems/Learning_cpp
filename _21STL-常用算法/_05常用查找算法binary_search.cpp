#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
binary_search : ����ָ��Ԫ���Ƿ����
ԭ�ͣ�
	bool binary_search(iterator beg, iterator end, value)
	�鵽���� true�� ���򷵻�false
	��Ҫ�����ҵ�����Ҫ������� ���� ��������
*/

void test5_1() {
	vector<int >v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	v.push_back(2);
	bool ret = binary_search(v.begin(), v.end(), 9);
	if (ret) {
		cout << "���ҵ���" << endl;
	}
	else {
		cout << "δ���ҵ�" << endl;
	}
}

int main5() {
	test5_1();
	system("pause");
	return 0;
}