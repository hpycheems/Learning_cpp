#include <iostream>
using namespace std;
#include <map>

/*
insert(elem) 在容器中插入元素
clear（） 清除所有元素
erase（pos） 清除pos迭代器所指向的元素，返回下一个元素的迭代器
erase(beg,end) 清除区间中的所有元素，返回下一个元素的迭代器
erase(key) 删除容器中值为key的元素
*/
void printMap2(map<int, int>& m) {
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << " Key = " << it->first << " Value = " << it->second << endl;;
	}
	cout << endl;
}
void test3_1() {
	map<int, int> m;
	//插入

	//方式一
	m.insert(pair<int, int>(1, 10));
	//方式二
	m.insert(make_pair(2, 20));
	//方式三
	m.insert(map<int, int>::value_type(3, 30));
	//方式四 不推荐使用来插入 可以用来访问 如果该key不存在，则会自动插入该key并初始化value
	m[4] = 40;
	printMap2(m);

	//删除
	m.erase(m.begin());
	printMap2(m);

	m.erase(3);
	printMap2(m);

	//清除
	//m.erase(m.begin(), m.end());
	m.clear();
	printMap2(m);
}

int main3() {
	test3_1();

	system("pause");
	return 0;
}