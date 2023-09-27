#include <iostream>
using namespace std;
#include <list>

/*
list& operator=(const list& lst);
assign(beg,end)
assign(n,elem)
swap(list);
*/
void printList2(list<int>& l) {
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test3_1() {
	list<int> l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	printList2(l1);

	list<int> l2;
	l2 = l1;
	printList2(l2);

	list<int> l3;
	l3.assign(l1.begin(), l1.end());
	printList2(l3);

	list<int> l4;
	l4.assign(10, 100);
	printList2(l4);
}
void test03_2() {
	list<int> l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	list<int> l2(10, 100);
	cout << "交换前" << endl;
	printList2(l1);
	printList2(l2);

	l1.swap(l2);
	cout << "交换后" << endl;
	printList2(l1);
	printList2(l2);


}

int main3() {
	test03_2();
	system("pause");
	return 0;
}