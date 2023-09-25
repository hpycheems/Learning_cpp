#include <iostream>
using namespace std;
#include <string>

//字符串比较
// 每个字符的ASCII码进行比较 逐个对比
// 0 相等
// 1
// -1

void test5_1() {
	string s1("hello");
	string s2("xello");
	int num = s1.compare(s2);
	if (num == 0) {
		cout << "s1 == s2" << endl;
	}
	else {
		cout << "s1 ！= s2" << endl;
	}
}

int main5() {
	test5_1();


	system("pause");
	return 0;
}