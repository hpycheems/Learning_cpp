#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void test7_1() {
	vector<int> v;

	v.reserve(100000);//Ԥ���ռ� ���Ԥ��֪��Ҫ��������ݵĿռ��С�� ��������Ԥ���ռ������� �ռ�Ŀ��ٴ���

	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);

		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}

	cout << "���ٿռ����" << num << endl;

}

int main7() {
	test7_1();
	system("pause");
	return 0;
}