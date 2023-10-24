#include <iostream>

//宏
#define exp(s) printf("test s is:%s\n", s);
#define exp1(s) printf("test s is:%s\n", #s);
#define exp2(s) #s

#define MAX 100
#pragma region const那些事
namespace Const {
	//1.const含义：常类型是指使用类型修饰符const说明的类型，常类型的变量或对象的值是不能被更新的。
	//2.const作用：
	//（1）定义常量 (常量不可修改、常量必须初始化)
	const int constNumber = 100;
	//（2）类型检查：const常量具有类型，编译器可以进行安全检查；
	// #define宏定义没有数据类型，只是简单的字符串替换，不能进行安全检查。
	
	// const定义的变量只有类型为整数或枚举，且以常量表达式初始化时才能作为常量表达式。
	// 其他情况下它只是一个 const 限定的变量，不要将与常量混淆。
	//（3）防止修改，起到保护作用，增强程序健壮性
	void constFunction(const int i) {
		//i++;//报错
	}

	// (4)节省空间，避免不必要的内存分配
	/*
	* const定义常量从汇编的角度来看，只是给出了对应的内存地址，而不是像#define一样给出的是立即数，
	* 所以，const定义的常量在程序运行过程中只有一份拷贝，而#define定义的常量在内存中有若干个拷贝。
	*/

	//3.const对象默认为文件局部变量
	/*非const变量默认为extern。
	* 要使const变量能够在其他文件中访问，必须在文件中显式地指定它为extern。
	
	//未被const修饰的变量在不同文件的访问
	//file.cpp
	int ext;
	//file2.cpp
	extern int ext;
	int main() { std::cout << (ext + 10) << std::endl; }

	//const常量在不同文件的访问
	//file.cpp
	extern const int ext = 12;
	//file2.cpp
	extern const int ext;
	int main() {
		std::cout << ext << std::endl;
	}
	可以发现未被const修饰的变量不需要extern显式声明！
	而const常量需要显式声明extern，并且需要做初始化！因为常量在定义后就不能被修改，所以定义时必须初始化。
	*/
	
	//4.指针与const
	const char* a;//常量指针
	char const* a;//指针常量
	char* const a;
	const char* const a;
	/*
	* 如果const位于*的左侧，则const就是用来修饰指针所指向的变量，
	* 即指针指向为常量；如果const位于*的右侧，const就是修饰指针本身，即指针本身是常量。
	*/
	//(1)常量指针（指向常量的指针）
	const int* ptr;
	//*ptr = 10;
	/*
	* ptr是一个指向int类型const对象的指针，const定义的是int类型，
	* 也就是ptr所指向的对象类型，而不是ptr本身，所以ptr可以不用赋初始值。
	* 但是不能通过ptr去修改所指对象的值。
	* 
	* 除此之外，也不能使用void*指针保存const对象的地址，
	* 必须使用const void*类型的指针保存const对象的地址。
	* 
	* 允许把非const对象的地址赋给指向const对象的指针。
	* 
	* 对于指向常量的指针，不能通过指针来修改对象的值。
	*/
	const int p = 10;
	const void* vp = &p;
	//void* vo = &p;

	const int* p;
	int b = 10;
	//p = &b;
	//我们不能通过ptr指针来修改val的值，即使它指向的是非const对象!

	//（2）常指针
	int num = 0;
	int* const ptr = &num;


	//(5)函数中使用const
	//const修饰函数返回值
	const int func1();//这个本身无意义，因为参数返回本身就是赋值给其他的变量！
	const int* func2(); //指针指向的内容不变。
	int* const func3();//指针本身不可变。


	//（6）类中使用const
	/*
	* 在一个类中，任何不会修改数据成员的函数都应该声明为const类型。
	*/
}
#pragma endregion

#pragma region Static那些事
namespace Static {
	/*
	* 当与不同类型一起使用时，Static关键字具有不同的含义。
	* 静态变量：函数中的变量，类中的变量
	* 静态类的成员：类对象和类中的函数
	* 
	*/
	//函数中的静态变量
	//当变量声明为static时，空间将在程序的生命周期内分配。
	//即使多次调用该函数，静态变量的空间也只分配一次，前一次调用中的变量值通过下一次函数调用传递。
	void demo() {
		static int count = 0;
		count++;
	}

	//类中的静态变量
	//由于声明为static的变量只被初始化一次，因为它们在单独的静态存储中分配了空间，
	//因此类中的静态变量由对象共享。对于不同的对象，不能有相同静态变量的多个副本。
	class Apple {
	public :
		static  int i;
	};
}
#pragma endregion

#pragma region This

#pragma endregion

#pragma region 引用和指针
/*
* 引用：必须初始化    不能为空   不能更换目标
* 指针：可以不初始化  可以为空	   可以更换目标
*/
#pragma endregion


#pragma region 宏
/*
* 1.宏中包含特殊符号： # ,## ,\
* (1)字符串化操作符（#）
*	#是“字符串化”的意思，出现在宏定义中的#是把跟在后面的参数转换成一个字符串。
* 注意：其只能用于有传入参数的宏定义中，且必须置于宏定义体中的参数名前
*/
void HongTest() {
	exp("hello");
	exp1("hello");
}

//(2)符号连接操作符（##）

#pragma endregion


int main() {

	system("pause");
	return 0;
}