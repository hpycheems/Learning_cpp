#include <iostream>
using namespace std;
#include <list>

/*
size()
empty()
resize(num)
resize(num,elem)
*/
void printList3(list<int>& l) {
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test4_1() {
	list<int> l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	printList3(l1);
	if (l1.empty()) {
		cout << "容器为空" << endl;
	}
	else {
		cout << "容器不为空" << endl;
		cout << "容器的大小为" << l1.size() << endl;
	}

	//
	l1.resize(10,1000);
	printList3(l1);

	l1.resize(3);
	printList3(l1);
}

int main4() {

	test4_1();
	system("pause");
	return 0;
}