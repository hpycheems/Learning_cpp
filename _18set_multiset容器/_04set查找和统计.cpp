#include <iostream>
using namespace std;
#include <set>

/*
find(key) 查找key是否存在，若存在返回该键的元素的迭代器，若不存在，返回set.end()
count(key) 统计key的元素个数
*/

//查找
void test4_1() {
	set<int> s;
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);

	set<int>::iterator pos = s.find(30);
	if (pos != s.end()) {

		cout << "查找到元素" << *pos << endl;
	}
	else {
		cout << "未查找到元素" << endl;
	}
}
//统计
void test4_2() {
	set<int> s;
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);

	int count = s.count(30); //set统计 返回值为 0 或1
	cout << count << endl;
}

int main4() {
	test4_2();

	system("pause");
	return 0;
}