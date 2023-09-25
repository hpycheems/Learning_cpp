#include <iostream>
using namespace std;
#include <string>

//string 查找和替换
/* 找到返回位置 找不到返回-1
* //查找str第一次出现位置，从pos开始查找
int find(const string& str,int pos = 0) const;
int find(const char* s,int pos = 0)const;
//从pos位置查找s的前n个字符第一次位置
int find(const char* s,int pos = 0, int n)const;
查找字符c第一次出现的位置
int find(cosnt char ,int pos = 0) const;

//从右往左查找 重载和find一样
int rfind(const string& str,int pos = 0)

string& replace(int pos, int n ,const string& str);//替换从pos开始n个字符为字符串str
string& replace(int pos, int n, const char* c);
*/

void test4_1() {
	string s1("abcdefgde");

	//find 从左往右查找
	int pos = s1.find("de");
	if (pos == -1) {
		cout << "未能查找到" << endl;
	}
	else {
		cout << "pos = " << pos << endl;
	}
	//rfind 从右往左查找
	int pos1 = s1.rfind("de");
	cout <<"rPos = "<< pos1 << endl;
}

void test4_2() {
	string s1("abcdefg");
	s1.replace(1, 3, "111111");
	cout << s1 << endl;
}

int main4() {
	test4_1();
	test4_2();
	system("pause");
	return 0;
}