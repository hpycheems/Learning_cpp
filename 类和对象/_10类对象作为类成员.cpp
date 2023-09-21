#include <iostream>
using namespace std;
#include<string>
//类对象作为类成员

class Phone {
public :
	string m_PName;
	Phone(string pName):m_PName(pName){
		cout << "Phone 的构造函数" << endl;
	}
};
class Person_3 {
public:
	string m_Name;
	Phone m_Phone;
	// m_Phone(pName) 相当于 Phone m_Phone = pName 隐式转换法
	Person_3(string name,string pName):m_Name(name),m_Phone(pName){
		cout << "Person_3 的构造函数" << endl;
	}
};
// 当其他类对象作为本类成员，构造时候先构造类对象，再构造自身
// 析构顺序相反
void test_3() {
	Person_3 p("张三", "IOS");
}

int main10() {
	test_3();
	system("pause");
	return 0;
}