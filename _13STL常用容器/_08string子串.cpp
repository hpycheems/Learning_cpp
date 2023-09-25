#include <iostream>
using namespace std;
#include <string>

//截取字符串中获取想要的内容
void test8_1() {
	string s1("abcdefg");
	string s2 = s1.substr(1, 3);
	cout << s2 << endl;
}

void test8_2() {
	string s1 = "lisi@qq.com";
	int pos = s1.find("@");
	string username = s1.substr(0, pos);
	cout << username << endl;
}

int main() {

	test8_1();
	test8_2();
	system("pause");
	return 0;
}