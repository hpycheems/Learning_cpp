#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

/*
copy: ��������ָ����Χ��Ԫ�ؿ�������һ��������
ԭ�ͣ�
	copy(iterator beg, iterator end, iterator dest);
	dest Ŀ����ʼ������
*/
void printFunc4(int val) {
	cout << val << " ";
}
void test12_1() {

	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}

	vector<int> v2;
	v2.resize(v1.size());//��ǰ��Ŀ���������ٿռ�
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), printFunc4);
}


int main12() {
	
	test12_1();

	system("pause");
	return 0;
}