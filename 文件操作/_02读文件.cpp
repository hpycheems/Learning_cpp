#include <iostream>
using namespace std;
#include <fstream>
#include <string>

//利用is_open函数可以判断文件是否打开成功

void test2_1() {

	// 包含头文件

	// 创建输入流对象
	ifstream ifs;

	// 打开文件
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "文件打卡失败" << endl;
		return;
	}

	// 读数据
	// 方式1
	//char buf[1024] = { 0 };
	//while (ifs >> buf) {
	//	cout << buf << endl;
	//}

	//方式2
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf))) {
	//	cout << buf << endl;
	//}

	//方式3
	string str;
	while (getline(ifs, str))
	{
		cout << str << endl;
	}
	
	//方式4 不使用
	//char c;
	//while ((c = ifs.get()) != EOF) {
	//	cout << c << endl;
	//}
	
	// 关闭文件
	ifs.close();
}

int main2() {
	test2_1();
	system("pause");
	return 0;
}