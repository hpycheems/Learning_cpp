#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

/*
set_intersection: �����������Ľ���
ԭ�ͣ�
	set_intersection(interator beg1,iterator end1, interator beg2, iterator end2,iterator desc);
	ע�⣺***�������ϱ�������������***
	dest Ŀ��������ʼ������
*/


void test18_1() {

	vector<int> v;
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		v1.push_back(i + 5);
	}

	vector<int> vTarget;
	//vTarget ��Ҫ���ٿռ�
	// ���ٵĿռ��СΪ ������������С���Ǹ�
	vTarget.resize(min(v.size(), v1.size()));

	//��Ҫ�ϲ��� ���صĵ�������Ϊ������������Ȼ���Ŀ������ȫ����ӡ����
	vector<int>::iterator pos = set_intersection(v.begin(), v.end(), v1.begin(), v1.end(), vTarget.begin());
	for (vector<int>::iterator it = vTarget.begin(); it != pos; it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}
int main18() {
	test18_1();
	system("pause");
	return 0;
}