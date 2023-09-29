#include <iostream>
using namespace std;
#include <set>

/*
size();
empty();
swap();
*/
void printSet2(const set<int>& s) {
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//大小
void test2_1() {
	set<int> s;
	s.insert(10);
	s.insert(20);
	s.insert(30);

	if (s.empty()) {
		cout << "s 为空" << endl;
	}
	else {
		cout << "s 不为空" << endl;
		cout << "s 的大小为 " << s.size() << endl;
	}

}
//交换
void test2_2() {
	set<int> s;
	s.insert(10);
	s.insert(20);
	s.insert(30);

	set<int> s1;
	s1.insert(100);
	s1.insert(200);
	s1.insert(300);

	cout << "交换前：" << endl;
	printSet2(s);
	printSet2(s1);

	s.swap(s1);
	cout << "交换后：" << endl;
	printSet2(s);
	printSet2(s1);
}

int main2() {
	test2_2();
	system("pause");
	return 0;
}