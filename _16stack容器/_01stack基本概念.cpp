#include <iostream>
using namespace std;
#include <stack>

//stack是一种先进后出的数据结构，只有一个出口
//入栈 push
//出栈 pop

//栈顶 用于出和进
//栈底 

//栈不允许有遍历行为 只有栈顶元素才能被外界访问到
// empty 是否为空 size 返回元素个数

//对外接口
/*
构造函数：
stack<T> stk;
stack(const stack &stk);
赋值操作：
stack& operator=(const stack & stk);
数据存取：
push（elem）；
pop();
top();
大小操作：
empty();
size();
*/

void test1_1() {
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	cout << "栈的大小为:" << s.size() << endl;

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	cout << "栈的大小为:" << s.size() << endl;
}

int main1() {
	test1_1();
	system("pause");
	return 0;
}