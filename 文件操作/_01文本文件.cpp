#include <iostream>
using namespace std;
#include <fstream>
//程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放
// 通过文件可以将数据持久化
// C++中对文件操作需要包含头文件 <fstream>


// 文件类型分为两种：
// 文本文件：文本以文本的ASCAII码形式存储在计算机中
// 二进制文件：文件以文本的二进制形式存储在计算中

//操作文件的三大类：
// ofstream 写操作
// ifstream 读操作
// fstream 读写操作

//写文件
// step1 :包含头文件 #include <fstream>
// step2 :创建流文件 ofstream ofs;
// step3 :打开文件 ofs.open("文件路径",打开方式)
// step4 :写数据 ofs << "写入的数据"
// step5 :关闭文件 ofs.close();

void test1_1() {

	//包含头文件
	//创建流对象
	ofstream ofs;
	//打开文件
	ofs.open("test.txt", ios::out);
	//写数据
	ofs << "姓名:张三" << endl;
	ofs << "性别:男" << endl;
	ofs << "年龄:20" << endl;
	//关闭文件
	ofs.close();
}

int main1() {
	test1_1();
	system("pause");
	return 0;
}