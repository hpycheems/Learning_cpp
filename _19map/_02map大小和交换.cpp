#include <iostream>
using namespace std;
#include <map>

/*
size()返回容器中元素个数
emptu() 判断容器是否为空
swap(st) 交换两个集合容器
*/

void printMap1(map<int, int>& m) {
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << " Key = " << it->first << " Value = " << it->second << endl;;
	}
	cout << endl;
}

void test2_1() {

	map<int, int> m;
	m.insert(pair<int, int >(1, 10));
	m.insert(pair<int, int >(2, 20));
	m.insert(pair<int, int >(3, 30));

	if (m.empty()) {
		cout << "map 容器为空" << endl;
	}
	else {
		cout << "map 容器不为空" << endl;
		cout << m.size() << endl;
	}
}

void test2_2() {

	map<int, int> m;
	m.insert(pair<int, int >(1, 10));
	m.insert(pair<int, int >(2, 20));
	m.insert(pair<int, int >(3, 30));

	map<int, int> m2;
	m2.insert(pair<int, int >(4, 40));
	m2.insert(pair<int, int >(5, 50));
	m2.insert(pair<int, int >(6, 60));
	cout << "交换前" << endl;
	printMap1(m);
	printMap1(m2);

	cout << "交换后" << endl;
	m.swap(m2);
	printMap1(m);
	printMap1(m2);
	
}

int main2() {

	test2_2();

	system("pause");
	return 0;
}