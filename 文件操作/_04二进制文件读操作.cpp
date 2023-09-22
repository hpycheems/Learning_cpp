#include <iostream>
using namespace std;
#include <fstream>

class Person {
public:

	char m_Name[64];
	int m_Age;
};

//文件输入流对象，可以通过read函数，以二进制方式读取数据

void test4_1() {
	//包含头文件
	//创建输入流对象
	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
	}

	//读数据
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << "姓名 :" << p.m_Name << "年龄" << p.m_Age << endl;

}

int main() {
	test4_1();
	system("pause");
	return 0;
}