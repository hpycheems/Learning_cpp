#include <iostream>
using namespace std;
#include <string>
//string�ַ���ƴ��

/*
string& operator+=(const char* s);
string& operator+=(const char c);
string& operator+=(const string & s);

string& append(const char* s);
string& append(const char* s, int n); ���ַ���s��ǰn���ַ�׷�ӵ���ǰ�ַ���β��
string& append(const string& s);
string& append(const string& s,int pos,int n);//�ַ���s�д�pos��ʼ��n���ַ�ƴ�ӵ���ǰ�ַ�����
*/

void test3_1() {
	string s1(" �� ");
	s1 += " ������Ϸ ";
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