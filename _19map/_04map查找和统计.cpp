#include <iostream>
using namespace std;
#include <map>

/*
find(key) 查找key是否存在，若存在，返回该键的元素迭代器，若不存在，返回map
count(key) 统计key元素个数
*/

void test4_1() {

	map<int, int> m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));

	//查找
	map<int, int>::iterator pos = m.find(2);
	if (pos != m.end()) {
		cout << "查找到元素:" << pos->second << endl;
	}
	else {
		cout << "未能查找到元素" << endl;
	}

	//统计
	int num = m.count(2);
	cout << "key 为2的元素有：" << num << endl;


}

int main4() {

	test4_1();
	system("pause");
	return 0;
}