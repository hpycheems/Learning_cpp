#include <iostream>
using namespace std;

/*
功能：将数据进行链式存储
数据域：存放数据
指针域：存放指针

优点：可以对任意位置快速插入和删除元素
缺点：容器遍历速度没有数组快、占用的空间比数组大

STL中的链表是一个双向循环链表
list迭代器也只能前移后移

list优点：
采用动态分配，不会造成内存浪费和溢出
链表执行插入和删除操作十分方便，修改指针即可，不需要大量移动数据
list：缺点：
链表灵活，但是空间（指针域）和时间（遍历）额外耗费较大
List有一个非常重要的性质，插入和删除操作都不会造成原有list迭代器的失效，这在vector不成立的
*/

int main1() {

	system("pause");
	return 0;
}