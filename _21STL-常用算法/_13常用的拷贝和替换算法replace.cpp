#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

/*
replace : ��������ָ����Χ�ľ�Ԫ�ظ�Ϊ��Ԫ��
ԭ�ͣ�
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

	cout << "�滻ǰ" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	replace(v.begin(), v.end(), 20, 1000);
	cout << "�滻��" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}

int main13() {
	test13_1();
	system("pause");
	return 0;
}