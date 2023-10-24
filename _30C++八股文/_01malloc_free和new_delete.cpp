#include <iostream>

/* 
	malloc\free 和 new delete 的区别
		
	背景：malloc、free 是C语言中库函数，new、delete是C++中操作符
	a. new自动计算所需分配内存大小，malloc需要手动计算（sizeof）
	b. new返回的是对象类型的指针，malloc返回的是 void* 之后进类型转换
	c. new分配失败会抛出异常， malloc分配失败返回的是 NULL
	d. new是在free store（自由内存区）上分配内存{当没有重载new操作符时，在堆上分配}，malloc在堆上分配
	e. delete需要对象类型的指针， free是 void* 类型的指针；

	new
	1. operator new
	2. 申请足够的空间
	3. 调用构造函数，初始化成员变量
	delete
	1.先调用析构函数
	2.operator delete
	3.释放空间

	malloc是怎么分配内存的？
	malloc分配的是物理内存还是虚拟内存？
	malloc调用后是否立即得到物理内存？
	free(p) 怎么知道该释放多大的空间？
	free释放内存后，内存还在吗？

	malloc申请小于128k的内存，不会还给操作系统，而是由malloc内部管理起来
	malloc申请内存大于等于128k，释放内存，还给了操作系统。
*/
void test_1() {

	int* numA = (int*)malloc(sizeof(int));

	int* numB = new int(10);
}

int main() {
	


	system("pause");
	return 0;
}