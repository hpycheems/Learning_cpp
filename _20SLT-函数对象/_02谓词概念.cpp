#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
概念：
	返回bool类型的仿函数称为谓词
	如果operator()接收一个参数，那么叫做一元谓词
	如果operator()接收两个个参数，那么叫做二元谓词
*/

//一元谓词
class GreaterFIve {
public:
	bool operator()(int val){
		return val > 5;
	}
};
void test2_1() {

	vector<int> v;
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);

	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterFIve());
	if (pos == v.end()) {
		cout << "未找到元素" << endl;
	}
	else {
		cout << "找到元素" << *pos << endl;
	}

}
//二元谓词
class Compare {
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};
void test2_2() {
	vector<int> v;
	v.push_back(5);
	v.push_back(3);
	v.push_back(6);
	v.push_back(4);
	v.push_back(7);

	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "============== " << endl;
	sort(v.begin(), v.end(),Compare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main2() {

	test2_1();

	test2_2();
	system("pause");
	return 0;
}