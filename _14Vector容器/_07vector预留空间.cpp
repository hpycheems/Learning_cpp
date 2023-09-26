#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void test7_1() {
	vector<int> v;

	v.reserve(100000);//预留空间 如果预先知道要存入的数据的空间大小， 可以设置预留空间来减少 空间的开辟次数

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

	cout << "开辟空间次数" << num << endl;

}

int main7() {
	test7_1();
	system("pause");
	return 0;
}