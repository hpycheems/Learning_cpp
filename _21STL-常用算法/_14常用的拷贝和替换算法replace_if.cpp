#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>


/*
replace_if: 将区间满足条件的元素，替换成指定元素
原型：
replace_if(iterator beg, iterator end, _pared, newValue);
_pred 谓词
*/

class MyPrint {

public:
	void operator()(int val) {
		cout << val << " ";
	}
};

class Greate30 {
public:
	bool operator()(int val) {
		return val >= 30;
	}

};

void test14_1() {

	vector<int> v;
	v.push_back(20);
	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(60);
	v.push_back(50);

	cout << "替换前" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	//替换大于等于30 的元素
	replace_if(v.begin(), v.end(), Greate30(), 3000);
	cout << "替换后" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}


int main14() {

	test14_1();

	system("pause");
	return 0;
}