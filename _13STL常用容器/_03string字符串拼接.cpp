#include <iostream>
using namespace std;
#include <string>
//string字符串拼接

/*
string& operator+=(const char* s);
string& operator+=(const char c);
string& operator+=(const string & s);

string& append(const char* s);
string& append(const char* s, int n); 把字符串s的前n个字符追加到当前字符串尾部
string& append(const string& s);
string& append(const string& s,int pos,int n);//字符串s中从pos开始的n个字符拼接到当前字符串中
*/

void test3_1() {
	string s1(" 我 ");
	s1 += " 爱玩游戏 ";
	cout << "s1 = " << s1<< endl;
	s1 += ':';
	cout << "s1 = " << s1 << endl;
	string s2("LOL DNF");
	s1 += s2;
	cout << "s1 = " << s1 << endl;
 
	string s3("I");
	s3.append("Love");
	cout << "s3 = " << s3 << endl;
	s3.append("game abcd", 4);
	cout << "s3 = " << s3 << endl;
	s3.append(s2);
	cout << "s3 = " << s3 << endl;
	s3.append(s2, 4, 3);
	cout << "s3 = " << s3 << endl;
}

int main3() {

	test3_1();
	system("pause");
	return 0;
}