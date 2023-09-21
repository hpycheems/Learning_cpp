#include<iostream>
using namespace std;
#include<string>
//递增运算符重载

class MyInteger {
	friend ostream& operator<<(ostream& cout, const MyInteger& m);
public:
	MyInteger() {
		m_Num = 0;
	}
	// 前置递增运算符重载 ++m_Num
	// 返回引用为了一直对一个数据进行递增操作
	MyInteger& operator++() {
		//先递增
		m_Num++;

		//再返回
		return *this;
	}

	//后置递增运算符重载 m_Num++
	// C++中产生的临时对象是不可修改的，即默认为const的，
	// 非cosnt引用只能绑定到与该引用同类型的对象
	MyInteger operator++(int) {
		//先记录
		MyInteger temp = *this;
		//再递增
		m_Num++;
		//最后返回记录的局部变量
		return temp;
	}
	//前置递减
	MyInteger& operator--() {
		m_Num--;
		return *this;
	}
	//后置递减
	MyInteger operator--(int) {
		MyInteger temp = *this;
		m_Num--;
		return temp;
	}

private:
	int m_Num;
};

ostream& operator<<(ostream& cout, const MyInteger& m) {
	cout << "m_Num = " << m.m_Num;
	return cout;
}


void test3_1() {

	MyInteger m;
	cout << ++(++m) << endl;
	cout << m << endl;
}

void test3_2() {
	MyInteger m;
	// operator<<(cout, MyInteger)
	cout << m++ << endl;
	cout << m << endl;

}

void test3_3() {
	MyInteger m;

	cout << --(--m) << endl;

	cout << m-- << endl;
	cout << m << endl;
}

// 总结：前置递增返回引用 后置递增返回值
int main3() {
	//test3_1();

	//test3_2();
	test3_3();

	system("pause");
	return 0;
}