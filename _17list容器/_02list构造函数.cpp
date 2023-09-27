#include <iostream>
using namespace std;
#include <list>

/*
list<T> lst;
list(beg,end);
list (n,elem);
list(cont list &lst);
*/
void printList1(list<int> & l) {
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test2_1() {

	list<int> l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	printList1(l1);

	list<int> l2(l1);
	printList1(l2);

	list<int> l3(l1.begin(), l1.end());
	printList1(l3);

	list<int> l4(10, 1000);
	printList1(l4);
}

int main2() {

	test2_1();

	system("pause");
	return 0;
}