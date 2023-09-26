#include<iostream>
using namespace std;
#include <deque>

//双端数组，可以对头端进行插入删除操作

//vector对于头部的插入删除效率低
//deque相对而言，对于头部的插入删除速度会比vector快
//vector访问元素时的速度会比deque快，

//deque内部工作原理
//deque内部有一个中控器，维护每段缓冲区中的内容，缓冲区存放真实数据
//中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间。
//deque支持随机存取

//deque构造函数
/*
deque<T> deqT;
deque(beg,end);
deque(n, elem);
deque(const deque & deq);
*/
void printDeque1(const deque<int> &d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test1_1() {

	deque<int> d;
	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
	}
	printDeque1(d);

	deque<int> d2(d.begin(), d.end());
	printDeque1(d2);

	deque<int> d3(10, 100);
	printDeque1(d3);

	deque<int> d4(d3);
	printDeque1(d4);

}

int main1() {
	test1_1();
	system("pause");
	return  0;
}