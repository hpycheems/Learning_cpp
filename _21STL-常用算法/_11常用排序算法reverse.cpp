#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

/*
reverse: 将容器内元素进行反转
原型：
	reverse(iterator beg, iterator end);
	反转指定范围的元素

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

	cout << "反转前" << endl;

	for_each(v.begin(), v.end(), printFunc3);
	cout << endl;

	cout << "反转后" << endl;
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), printFunc3);
	cout << endl;
	
}

int mai11n() {
	test11();

	system("pause");
	return 0;
}