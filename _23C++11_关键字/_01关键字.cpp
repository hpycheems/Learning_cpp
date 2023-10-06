#include<iostream>
using namespace std;
#include <string>
#include <assert.h>
#include <map>

#pragma region alignas  alignof
//alignas（设置对齐位数） 、alignof(内存对齐位数) 默认的对齐是成员中占内存最大的类型
struct  Foo
{
	int i;
	float f;
	char c;
};
struct Empty {};
// 0 1 2 4 8...
struct alignas(64) Empty64 {};
struct alignas(0) BB {};//这个设置会被忽略
//对齐设置不能小于默认值 会报错
//struct alignas(1) Dobule { double d; };
void alignInfo() {

	cout << "- char :" << alignof(char) << endl // 1
		<< "- pointer :" << alignof(int*) << endl//4
		<< "- class FOO" << alignof(Foo) << endl//4
		<< "- empty class" << alignof(Empty) << endl// 1
		<< "- alignas(64) Empty" << alignof(Empty64) << endl;
}
#pragma endregion

#pragma region and 
void showAnd() {
	int a = 3;
	int b = 4;
	if ((a == 3) && (b == 4)) {

	}

	if ((a == 3) and (b == 4)) {

	}

	//and_eq (&=) & 按位与
	b and_eq b;
	b &= a;
	b = b & a;
}
#pragma endregion

//asm 内嵌汇编语言

#pragma region 
//aotu 根据后面的值来推导出它应该是的类型
void showAuto() {
	int aa = 1 + 2;
	auto a = 1 + 2.0;
	cout << "type of a" << typeid(a).name() << endl;
}
#pragma endregion

#pragma region bitand bitor
void showBitAndOr() {
	int a = 3;
	int b = 4;
	auto c = a bitand b;//&
	auto d = a bitor b;// |

}
#pragma endregion

//bool 一般是一个字节
//建议不要用bool 来作为函数的参数
void testBool() {
	bool a = true;
	bool b = false;
	*(reinterpret_cast<char*>(&a)) = -1;
	cout << "a = " << a << endl;

	if (a) {
		cout << "a true" << endl;
	}
	else {
		cout << "a false" << endl;
	}

	if (a == true) {
		cout << "a true" << endl;
	}
	else if (a == false) {
		cout << "a false" << endl;
	}
	else {
		cout << "a whate" << endl;
	}
}

//break 退出本层循环
//case switch中使用的
//catch try catch 捕获异常

//char 255 1个字节 (linux) == unsigned char , singed char == (window)
void showChar() {
	char a = -10;
	unsigned char b = -1;
	cout << (int)a << endl;
	cout << (int)b << endl;
}

//char16_t 包含 中日韩等 文字的字符

//char32_t

//class 类

//compl 即 ~ 

//concept (概念TS)

//const 常量  

//constexpr 直接在编译期间运算 |代码到程序 编译（）-》链接
int fact(int n) {
	return n <= 1 ? 1 : (n * fact(n - 1));
}
constexpr int factorial(int n) {
	return n <= 1 ? 1 : (n * factorial(n - 1));
}
void showConstexpr() {
	//char group[fact(3)];//报错
	char group[factorial(3)];//不会报错
}

//const_cast 把const转成可变的 对const这种不变性的破坏
void testConstCast() {
	const int j = 3;
	//const int*
	int* pj = const_cast<int*>(&j);
	*pj = 4;
}

//continue 跳过本次循环

//decltype 求类型 
void testDeclType() {
	
	int a = 10;
	decltype(a) y;//获取类型 int
	auto& cc = y;
	decltype((a)) z = y; // int&
}
template<class T,class U>
auto add(T a, U b) -> decltype(a + b) {
	return a + b;
}
template<class T, class U>
auto add(T a, U b) {
	auto c = a + b;
	return c; //两个返回的是不相同的
	return (c);
}

//defaulat switch case default

//delete 释放内存

//do do{}while()

//double

//dynamic_cast 把父类指针转换成子类指针
struct Base { virtual ~Base() {} };
struct Deriverd :Base {
	virtual void name() {}
};
void testDyn() {
	Base* b1 = new Base;
	//如果转换不成功 则返回空指针
	if (Deriverd* d = dynamic_cast<Deriverd*>(b1)) {
		cout << "成功转换 1" << endl;
	}
	Base* b2 = new Deriverd;
	if (Deriverd* d = dynamic_cast<Deriverd*>(b2)) {
		cout << "成功转换 2" << endl;
	}

	Base bb;
	Deriverd& cc = dynamic_cast<Deriverd&>(bb);//如果失败则抛出异常
}

//else

//enum
//enum Color{red, green, blue};
//enum Hate {red,blue};//不受命名空间的限制 此时会报错 red blue
//所以c++11的enum class int是默认元素的大小（可以更改，也可以省略）
enum class Color : int {red, green, blue};
void showEnum() {
	Color color = Color::red;
	switch (color)
	{
	case Color::red:
		break;
	case Color::green:
		break;
	case Color::blue:
		break;
	default:
		break;
	}
	//必须这样才能转成 整形的数据
	int a = static_cast<int>(color);
}

//explicit 防止隐式调用
struct A {
	A(int){}
	A(int, int) {}
	operator int()const { return 0; }
};
struct B
{
	explicit B(int) {}
	explicit B(int, int) {}
	explicit operator int()const { return 0; }
};
void testExpl() {
	A a1 = 1;//A a1 = A(1)
	//B b1 = 2;//报错
	A a2(2);//默认构造
	B b2(2);
	A a3 = { 3,4 };//C++11加的构造 A a3 = A(4,5);
	//B b3 = { 1,2 };//报错
	int na1 = a1;
	//int nb1 = b2;//报错
	int na2 = static_cast<int>(a1);
	int nb2 = static_cast<int>(b2);//必须使用强制转换才可
}

//export 废弃不使用

//extern 

//false ture

//float 4个字节

//for 循环 11中有新拓展

//firend 友元 是单向的

//goto 

//if

//inline 将代码从函数中展开（拿空间换时间）只能定义在头文件中
inline int add(int a, int b) { return a + b; }
//类中的函数默认也是inline 可以去除
//模板方法也一样

//int 4个字节 signed

//long 大小不会小于int 8字节

//mutable 可变的 在常量方法中可变

//namespace 命名空间
namespace YGroup {
	class A1 {
		int value;
	};
}
namespace XGroup {
	class A1 {
		int value;
	};
	class B {

	};
}
class A1 {
	int value;
};
void testNamespace() {
	XGroup::A1 a;
	YGroup::A1 a1;
}

//new 返回对象的指针

//noexcept 不抛出异常
void f() noexcept {
	//如果抛出异常 则会调用
	terminate();//这三个
	abort();
	exit(0);
}

//not !

//not_eq !=

//nullprt 空指针
//是一种类型 nullprt_t

//operator 重载+ - = （）

//or ||

//or_eq |=

//privete 
//protected  //类成员的权限
//public

//register（定义的某个变量 放入到寄存器中） 废弃 

//reinterpret_cast 转换
void testReinter() {
	int a;
	//reinterpret_cast
	//static_cast
	//const_cast
	//dynamic_cast 
	//c like cast 除了dynamic_cast 都可以用它实现
	auto pp = (char*)(&a);
}

//requires

//return 返回

//short 整形 比int小

//signed 有符号

//sizeof 

//static 类和文件中的static不一样
static int globalA = 0;//程序在编译时就分配内存了
void printInfo() {
	static int localStatic = 0;//只有第一次调用时才会执行
}

//static_assert 与assert功能相似，但static_assert在编译期进行
void testStaticAssert() {
	static_assert(sizeof(int) == 4, "当int不等于4时打印这句话");
	int a = 3;
	int b = 4;
	//当使用 assert时 只能使用assert 不能用static_assert
	assert(a == b, "");//这件事情只能在运行时做
	//static_assert(a==b,)//此时是报错的
}

//static_cast

//struct 结构体

//switch case defalut

//template 模板 模板函数 模板类

//this 类中 调用对象的指针

//thread_local 多线程时使用的

// throw 抛出异常

// true

// try catch

// typedef 把一个长的名字定义成短的名字
typedef unsigned long ulong;

//typeid 

//typename 

//union

//unsigned

//using

//virtual 虚函数 虚继承

//void 

//volatile 让编译器不要优化

//wchar_t 

//while 循环
void showWhile() {
	int num = 0;
	while (true) {
		num++;
		if (num == 5)break;
	}
}

//xor ^ 按位异或 0 1为1
void testXor() {
	int a = 2;// 0000 0000 0000 0010
			  // 0000 0000 0000 1010
	int b = a ^ 10;
	cout << b << endl;
}
//xor_eq ^=


int main() {
	//showAuto();
	//showChar();
	//testBool();
	//testDyn();
	testXor();
	system("pause");
	return 0;
}