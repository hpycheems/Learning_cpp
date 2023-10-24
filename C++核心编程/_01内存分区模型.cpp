#include <iostream>
using namespace std;

int g_a = 10;//全局变量
int g_b = 20;

//const 修饰的全局变量 
const int c_g_a = 10;
const int c_g_b = 20;

int* func() {
	int a = 10;//存放在栈，函数执行完毕后自动释放
	return &a;// 不要返回局部变量的地址
}

int* func01() {
	//指针本质也是局部变量， 放在栈上，只是该指针用来接收堆中的 地址
	int *p = new int(10);
	return p;
}

int* func2() {
	//new返回 该数据类型的指针
	int *p = new int(10);
	return p;
}

void test01() {
	int* p = func2();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;

	//释放
	delete p;
	//cout << *p << endl;//释放后不可访问
}

void test02() {
	int* arr = new int[10];

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}
	
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	//释放数组
	delete[] arr;

}


//C++程序执行时，将内存大方向划分为4个区域
// 代码区：存放函数体的二进制代码，由操作系统进行管理
// 全局区： 存放全局变量和静态变量以及常量
// 栈区：由编译器自动分配释放，存放函数的参数值，局部变量等
// 堆区：由程序员分配和释放，若不释放，程序结束时由操作系统回收
// 意义：不同区域存放的数据，赋予不同的生命周期，给我们更大的灵活编程
int main(){

//程序运行前
   // 在程序编译后，生成了exe 可执行程序，未执行该程序前分为两个区域
	// 代码区：
		// 存放CPU执行的机器指令
		// 代码区是共享的， 共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可
		// 代码区是只读的，使其只读的原因是防止程序意外的修改了它的指令
	// 全局区
		// 全局变量和静态变量存放在此
		// 全局区还包含了常量区：字符串常量和其他常量也存放在此
		// 该区域的数据在程序结束后由操作系统释放
	// 全局变量、静态变量、常量
	int a = 10;//局部变量
	int b = 20;
	cout << "局部变量a地址：" << (int)&a << endl;
	cout << "局部变量b地址：" << (int)&b << endl;

	cout << "全局变量g_a地址：" << (int)&g_a << endl;
	cout << "全局变量g_b地址：" << (int)&g_b << endl;
	
	static int s_a = 10;
	static int s_b = 20;
	cout << "静态变量s_a地址：" << (int)&s_a << endl;
	cout << "静态变量s_b地址：" << (int)&s_b << endl;

	//常量
		//字符串常量
	cout << "字符串常量地址:" << (int)&"Hello" << endl;

	cout << "全局常量c_g_a常量地址:" << (int)&c_g_a << endl;
	cout << "全局常量c_g_b常量地址:" << (int)&c_g_b << endl;

	//const修饰的变量(常量)
	//const修饰的全局变量（全局常量），const修饰的局部变量（局部常量）
	const int c_a = 10;
	const int c_b = 10;
	//局部常量存放在栈区
	cout << "局部常量c_a常量地址:" << (int)&c_a << endl;
	cout << "局部常量c_b常量地址:" << (int)&c_b << endl;

//程序运行后
//栈区
	// 由编译器自动分配释放，存放函数的参数值，局部变量等
	// 注意：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;

//堆区
	//由程序员分配和释放，若不释放，程序结束时由操作系统回收
	//在C++中利用new在堆开辟内存
	int* p1 = func01();
	cout << *p1 << endl;
	cout << *p1 << endl;
	cout << *p1 << endl;

// new操作符
	//new 语法
	//在堆区 利用new开辟数组
	cout << "=======================" << endl;
	test01();
	cout << "=======================" << endl;
	test02();

	system("pause");
	return 0;
}