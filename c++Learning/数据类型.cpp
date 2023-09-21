#include <iostream>
#include <string>
using namespace std;

//数据类型存在的意义
//分配合适的内存空间

int main07() {

//整型
	// 1、短整型 占2字节 
	short num1 = 10;

	// 2.整型 占4字节
	int num2 = 10;

	// 3. 长整型 占4字节
	long num3 = 10;

	// 4.长长整型 占8字节
	long long num4 = 10;

	cout << num1 << endl; 
	cout << num2 << endl; 
	cout << num3 << endl;
	cout << num4 << endl;

	//sizeof(数据类型/变量)关键字
	cout << "short占用内存空间：" << sizeof(short) << endl;
	cout << "int占用内存空间：" << sizeof(num2) << endl;
	cout << "long占用内存空间：" << sizeof(num3) << endl;
	cout << "long long占用内存空间：" << sizeof(num4) << endl;
	// short < int <= long < long long 

//浮点型 
	//单精度 flot 占4个字节 7位有效数字
	//默认情况下 输出小数 只会现实6个有效数字
	float f1 = 3.1415626f;//不加f会变成双精度
	cout << "f1 =" << f1 << endl;

	//双精度 double 占8个字节
	double d1 = 3.1415626;
	cout << "d1 =" << d1 << endl;
	cout << "flot占用的内存空间：" << sizeof(float) << endl;

	cout << "double占用的内存空间：" << sizeof(double) << endl;

	//科学计数法
	float f2 = 3e2; //3 * 10^2
	cout << "f2 = " << f2 << endl;
	float f3 = 3e-2;
	cout << "f3 = " << f3 << endl;

//字符型 char
	//用于显示单个字符 占1个字节
	cout << "char 占的内存空间：" << sizeof(char) << endl;
	
	char ch = 'a';//单引号中只能 存在一个字符
	cout << ch << endl;

	//常见错误
	//char ch2 = "a" 使用单引号
	//char ch2 = 'abcdef'; 只能存在一个字符

	//字符型变量对应ASCII编码 底层存放的是ASCII码
	// 字符型变量并不是把字符本身放到内存中存储，而是将对应的ASCII编码放入存储单元
	//a 97
	//A 65
	cout << (int)ch << endl;

//转移字符 用于表示一些不能显示出来的ASCII字符
	// \n 换行
	printf("换行 转移字符 \n");

	// \\ 代表一个反斜杠
	cout << "\\" << endl;

	// \t 水平制表 8个位置 整齐输出数据
	cout << "aa\t" << "水平制表" << endl;
	cout << "aaaaa\t" << "水平制表" << endl;
	cout << "aaa\t" << "水平制表" << endl;

//字符串型
	//c风格 char name[] = "字符串值";
	char str1[] = "Hello World";
	cout << str1 << endl;

	// string name = "字符串值"
	// 包含头文件 #include <string>
	string str2 = "Hello C++";
	cout << str2 << endl;

//布尔数据类型 bool
	//bool类型只有两个值 占1个字节
	// 1 代表真 0代表假
	// true
	// false
	cout << "bool 占用的内存空间：" << sizeof(bool) << endl;

	bool b1 = true;
	cout << b1 << endl;
	b1 = false;
	cout << b1 << endl;

//数据的输入
	//关键字 cin

	// 1.整型
	int a = 0;
	cout << "请给整型变量a赋值：" << endl;
	//cin >> a;
	cout << "整型变量a = " << a << endl;

	// 2. 浮点型
	float f = 0.0f;
	cout << "请给浮点变量f赋值：" << endl;
	//cin >> f;
	cout << "浮点变量f = " << f << endl;

	// 3.字符型
	char c = 'a';
	cout << "请给字符变量c赋值：" << endl;
	//cin >> c;
	cout << "字符变量c = " << c << endl;

	//字符串
	string s = "";
	cout << "请给字符串变量s赋值：" << endl;
	//cin >> s;
	cout << "字符串变量s = " << s << endl;

	//布尔类型
	bool b = "";
	cout << "请给字布尔变量b赋值：" << endl;
	cin >> b;//除了0为假 其他都为真
	cout << "布尔变量b = " << b << endl;

	system("pause");
	return 0;
}