#include <iostream>
using namespace std;
#include <list>

/*
push_back(elem)
pop_back()
push_front(elem)
pop_front()

insert(pos,elem)
insert(pos,n,elem)
insert(pos,beg,end)

clear()

erase(beg,end)
erase(pos)

remove(elem) 删除与elem相等的元素
*/
void printList5(list<int>& l) {
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test5_1() {
	list<int> l1;
	//尾插
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	//头插
	l1.push_front(100);
	l1.push_front(200);
	l1.push_front(300);
	printList5(l1);

	//尾删
	l1.pop_back();
	printList5(l1);
	//头删
	l1.pop_front();
	printList5(l1);

	//插入
	l1.insert(++l1.begin(), 1000);
	printList5(l1);
	l1.insert(l1.begin(), 2, 900);
	printList5(l1);

	//删除
	l1.erase(++l1.begin());
	printList5(l1);

	l1.push_back(10000);
	l1.push_back(10000);
	l1.push_back(10000);
	printList5(l1);
	l1.remove(10000);
	printList5(l1);
}

int main5(){
	test5_1();
	system("pause");
	return 0;
}