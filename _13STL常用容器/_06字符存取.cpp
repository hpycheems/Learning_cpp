#include <iostream>
using namespace std;
#include <string>

//string存取
void test6_1() {
	string s1("hello");
	
	//[]访问方式
	for (int i = 0; i < 5; i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1.at(i) << endl;
	}	
	cout << endl;

	s1[0] = 'x';
	cout << s1 << endl;
	s1.at(1) = 'x';
	cout << s1 << endl;
}

int main6() {

	test6_1();

	system("pause");
	return 0;
}