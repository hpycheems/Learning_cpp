#include <iostream>
using namespace std;
#include <set>

/*
inser(elem);
clear();

erase(pos);
erase(beg,end);
erase(elem)
*/
void printSet3(const set<int>& s) {
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test3_1() {
	set<int> s;
	//²åÈë
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);

	//É¾³ı
	s.erase(s.begin());
	printSet3(s);

	s.erase(30);
	printSet3(s);

	//Çå³ı
	//s.erase(s.begin(), s.end());
	s.clear();
	printSet3(s);
	
}

int main3() {
	test3_1();
	system("pause");
	return 0;
}