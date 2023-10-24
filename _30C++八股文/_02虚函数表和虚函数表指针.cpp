#include <iostream>

/*
* 虚函数表和虚函数表指针的创建时机
* 背景： 用来实现多态
* 
* 虚函数表创建时机：
* a.什么时候生成？ 编译器编译的时候生成，要有virtual关键字修饰的函数
* b.存放在哪？可执行程序（磁盘 .rodata(只读数据段，存储虚函数表（虚函数地址的数组）)），
* 运行状态（内存，只读代码区）
* 
* 内核空间
* 栈区
* 文件映射区
* 堆区
* 数据区
* 代码区 
* 
* 虚函数表与虚函数表指针的关系：
* 每个类最多只有一个虚函数表
* 类的不同对象，通常虚函数表指针是不一样的，（深）拷贝构造或重载运算符
* 虚函数不熬指针就是指向虚函数表的指针
* 
* 虚函数表指针的创建时机：
* 1.类对象构造的时候，把类的虚函数表地址赋值给 vptr
* 2.没有构造函数，编译器会生成默认的构造函数
* 3.继承的情况下
*  a.调用基类的构造函数，把A的虚函数表地址赋值给vptr
*  b.调用子类构造函数，把B的虚函数表的地址赋值给vptr
*/

int main() {



	system("puase");
	return 0;
}