#include <iostream>
using namespace std;
#include <fstream>
//以二进制的方式对文件进行读写操作
// 打开方式要指定为 ios::binary

//写文件
// 二进制方式写文件主要利用流对象调用成员函数write
// 函数原型：ostream& write(const char * buffer, int len);
// 参数解释：字符指针buff指向内存中一段存储空间。len是读写的字节数

class Person {
public :

	char m_Name[64];
	int m_Age;
};

void test3_1() {
	Person person = {"张三", 19};
	//包含头文件
	//创建输流文件
	// 打开文件
	ofstream ofs("person.txt", ios::out | ios::binary);

	//写数据

	ofs.write((const char*)&person, sizeof(person));

	//关闭文件
	ofs.close();

}

int main3() {

	test3_1();

	system("pause");
	return 0;
}