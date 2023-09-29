#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

/*
replace : 将容器内指定范围的旧元素改为新元素
原型：
	replace(iterator beg, iterator end, oldValue, newValue);
*/

class MyPrint {

public:
	void operator()(int val) {
		cout << val << " ";
	}
};
void test13_1() {
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(20);
	v.push_back(60);
	v.push_back(70);

	cout << "替换前" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	replace(v.begin(), v.end(), 20, 1000);
	cout << "替换后" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}

int main13() {
	test13_1();
	system("pause");
	return 0;
}