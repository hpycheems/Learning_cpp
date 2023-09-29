#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>


/*
sort: 对容器内元素进行排序
原型：
	sort(iteraotr beg, iterator end, _Pred)
	排序容器中的元素 ， 默认从小到大
	可以通过 _Pred改变排序方式
*/

void printFunc(int val) {
	cout << val << " ";
}

void test8_1() {
	vector<int> v;
	v.push_back(20);
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(40);
	v.push_back(15);

	//默认为升序排序
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), printFunc);
	cout << endl;

	//降序排序
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), printFunc);
	cout << endl;
}

int main8() {

	test8_1();

	system("pause");
	return 0;
}