#include <iostream>
using namespace std;
#include <list>
#include <algorithm>

//将容器中的元素反转，以及将容器中的数据进行排序

/*
reverse() 反转
sort() 排序
*/
void printList7(list<int>& l) {
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
bool myCompare(int val1, int val2) {
	return val1 > val2;

}
void test7_1() {

	list<int> l;
	l.push_back(20);
	l.push_back(10);
	l.push_back(30);
	l.push_back(50);
	l.push_back(40);
	cout << "反转前：" << endl;
	printList7(l);

	l.reverse();
	cout << "反转后：" << endl;
	printList7(l);

}

void test7_2() {
	list<int> l;
	l.push_back(20);
	l.push_back(10);
	l.push_back(30);
	l.push_back(50);
	l.push_back(40);
	cout << "排序前" << endl;
	// 所有不支持随机访问迭代器,不可以用标准算法
	// 不支持随机访问迭代器的容器，内部会提供对应一些算法
	//sort(l.begin(), l.end());
	printList7(l);

	cout << "排序后" << endl;
	l.sort(myCompare);//默认降序排序 自己提供比较函数 更改排序方式
	printList7(l);


}

int main7() {


	test7_2();
	system("pause");
	return 0;
}