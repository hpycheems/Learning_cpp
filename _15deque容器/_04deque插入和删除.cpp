#include<iostream>
using namespace std;
#include <deque>

void printDeque4(const deque<int>& d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test4_1() {
	deque<int> d;
	
	//Î²²å
	d.push_back(10);
	printDeque4(d);
	//Í·²å
	d.push_front(100);
	printDeque4(d);

	d.push_back(10);
	d.push_back(1);

	//Î²É¾
	d.pop_back();
	printDeque4(d);

	//Í·É¾
	d.pop_front();
	printDeque4(d);

}

void test4_2() {
	deque<int> d2;
	d2.push_back(10);
	d2.push_back(20);
	d2.push_front(100);
	d2.push_front(200);
	printDeque4(d2);

	//insert ²åÈë
	d2.insert(d2.begin(), 1000);
	printDeque4(d2);

	d2.insert(d2.begin(), 2, 10000);
	printDeque4(d2);

	deque<int> d3;
	d3.push_back(1);
	d3.push_back(2);
	d3.push_back(3);

	d2.insert(d2.begin(), d3.begin(), d3.end());
	printDeque4(d2);
}
//É¾³ý
void test4_3() {
	deque<int> d2;
	d2.push_back(10);
	d2.push_back(20);
	d2.push_front(100);
	d2.push_front(200);
	printDeque4(d2);

	d2.erase(d2.begin());
	printDeque4(d2);

	//d2.erase(d2.begin(), d2.end());
	d2.clear();
	printDeque4(d2);



}

int main4() {
	test4_3();
	system("pause");
	return 0;
}