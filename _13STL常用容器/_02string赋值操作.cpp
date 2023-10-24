#include <iostream>
using namespace std;
#include <string>

/*
string & operator=(cosnt char* s);
string & operator=(cosnt string& s);
string & operator=(char c);

string& assign(const char *s);
string& assign(const char *s, int n); // 把字符串s的前n个字符赋值给当前的字符串
string& assign(const string & s);
string& assign(int n,char c);

*/

void test2_1() {
	string s1;
	s1 = "hello world";
	cout << "s1 = " << s1 << endl;

	string s2;
	s2 = s1;
	cout << "s2 = " << s2 << endl;

	string s3;
	s3 = 'a';
	cout << "s3 = " << s3 << endl;

	string s4;
	s4.assign("hello c++");
	cout << "s4 = " << s4 << endl;

	string s5;
	s5.assign(s4);
	cout << "s5 = " << s5 << endl;

	string s6;
	s6.assign("hello c++", 5);
	cout << "s6 = " << s6 << endl;

	string s7;
	s7.assign(10,'a');
	cout << "s7 = " << s7 << endl;
}

int main() {

	test2_1();

	system("pause");
	return 0;
}