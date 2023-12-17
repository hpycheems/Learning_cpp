#include <iostream>
using namespace std;
#include <string>

/*
string& insert(int pos, cosnt char* s);
string& insert(int pos, cosnt string& s);
string& insert(int pos, int n ,char c);在指定位置插入n个字符c
string& erase(int pos, int n = npos);
*/

void test7_1() {
	string str("hello");
	str.insert(1, "1111");
	cout << "str = " << str << endl;

	str.erase(1, 4);
	cout << "str = " << str << endl;
}

int main() {

	test7_1();
	system("pause");
	return 0;
}