#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

/*
swap: 互换两个容器的元素
原型：
	swap(continer c1, container c2);
	交换的容器要是同种类型
*/
class MyPrint {

public:
	void operator()(int val) {
		cout << val << " ";
	}
};
void test15_1() {

	vector<int >v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 100);
	}

	cout << "替换前" << endl;
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;

	swap(v1, v2);
	cout << "---------------" << endl;
	cout << "替换后" << endl;
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;
}

int main15() {

	test15_1();

	system("pause");
	return 0;
}