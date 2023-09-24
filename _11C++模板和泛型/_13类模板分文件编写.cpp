#include <iostream>
using namespace std;

//第一种解决方式,直接包含源文件
//#include "perons.cpp"
//第二种解决方式，将.h和.cpp中的内容写到一起 .hpp
#include "perons.hpp"

void test13_1() {
	Person<string, int> p1("孙无力", 10);
}

int main13() {

	test13_1();

	system("pause");
	return 0;
}