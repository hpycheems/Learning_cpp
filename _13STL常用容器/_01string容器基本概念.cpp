#include <iostream>
using namespace std;
#include <string>
//string��������
//���ʣ�string��һ����

// string��char*����
//  char* ��ָ��
//  string��һ���࣬���ڲ���װ��char*����������ַ�������һ��char*�͵�����

//�ص㣺
//string���ڲ���װ�˺ܶ��Ա����
// find\copy\delete\replace\insert
// string����char*��������ڴ棬���õ��ĸ���Խ���ȡֵԽ��ȣ������ڲ����и���

//string���캯��
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