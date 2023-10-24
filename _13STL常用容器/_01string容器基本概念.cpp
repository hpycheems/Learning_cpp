#include <iostream>
using namespace std;
#include <string>
//string基本概念
//本质：string是一个类

// string与char*区别：
//  char* 是指针
//  string是一个类，类内部封装了char*，管理这个字符串，是一个char*型的容器

//特点：
//string类内部封装了很多成员方法
// find\copy\delete\replace\insert
// string管理char*所分配的内存，不用担心复制越界和取值越界等，由累内部进行负责

//string构造函数
/*
string();
string(const char * s);
string(const string& str);
string(int n,char c);
*/

void test1_1() {
	string s1;

	const char* str = "Hello world!";
	string s2(str);

	cout << s2 << endl;

	string s3(s2);
	cout << s3 << endl;

	string s4(10, 'a');
	cout << s4 << endl;

	string s5("123123");

	string s6(s5.begin(), s5.end());
	cout << s6 << endl;
	string s7 = "asdasdasd";// string s7("asdasdasd")
	string s8 = { "asdasdasd" };
	string s9{ "12312312312" };
}
int main1() {


	test1_1();
	system("pause");
	return 0;
}