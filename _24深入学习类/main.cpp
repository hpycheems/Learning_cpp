#include<iostream>
using namespace std;
#include <fstream>
#include<vector>
#include<map>
#include <string>
#include "Good.h"

#pragma region 前置声明
//前置声明 不完整类型
// 在头文件中， 尽可能少的引用头文件 Parent Child类例子
// 当存在继承的时候，继承的别的头文件是需要包含进来的 不能使用前置声明
// 当别的类作为该类的成员 非指针或引用 ，也需要把头文件包含进来
// 当另外类的类型是成员容器的类型 则也是需要包含 

// 在作为返回值和形参时是不需要要包含头文件的
class RuleOfFive;
class Parent;
class Child {
public:
	//此时Parent是未定义类型， 所有传参时 则需要使用指针或引用
	Child(Parent* p) :m_parent(p) {}
private:
	Parent* m_parent;
};
class Parent {
public:
	bool addChild(Child* child) { m_children.push_back(child); }
private:
	vector<Child*> m_children;
};
#pragma endregion

#pragma region 析构和构造函数
//自动调用 
//delete 时调用
class RuleOfThree {
	//当维护指针时 虽然会自动调用它的析构函数 但还是需要自定义析构函数来释放内存
	char* cstring;
public:
	RuleOfThree(const char* arg):cstring(new char[strlen(arg + 1)]) {
		strcpy(cstring, arg);
	}
	~RuleOfThree() {
		delete[] cstring;
	}
	//需要把默认的拷贝的浅拷贝 自己实现深拷贝
	RuleOfThree(const RuleOfThree& other) {
		cstring = new char[strlen(other.cstring) + 1];
		strcpy(other.cstring, cstring);
	}
	//重载= 默认的也是浅拷贝，需要自己实现深拷贝
	RuleOfThree& operator=(const RuleOfThree& other) {
		char* tem_cstring = new char[strlen(other.cstring) + 1];
		strcpy(tem_cstring, other.cstring);
		delete[] cstring;
		cstring = tem_cstring;
		return *this;
	}
};
//当不需要拷贝构造时
//把拷贝构造函数 移入private
//C++11 方法 RuleOfThree(const RuleOfThree& other) = delete;

//C++11 优化拷贝构造
vector<int> makeVector() {
	vector<int> v(100);
	for (int i = 0; i < 100; i++)
	{
		v[i] = rand() % 101;
	}
	return v;
}

//C++ 类的构造和析构的5个规则
//左值和右值 左值可取地址 右值不可  虽然不可以取临时变量的引用，但可以取const引用
//对于拷贝构造， 形参传入尽可能 用const修饰
void leftOrRight() {
	int a = 0;
	int b;
	int c = 2 + 3;
	int d = a + c;
	auto address = &a;
	//右值引用
	int&& re = 2;

	//std:move(b) 让编译器想办法把b编程右值 这样之后 不建议再使用b
}
//move方法调用的右值拷贝构造 当不需要时 也可delete掉
class _RuleOfFive {
public:
	_RuleOfFive(const _RuleOfFive& rhs) :m_char(new int(*rhs.m_char)) {}
	_RuleOfFive(_RuleOfFive&& rhs) {//当用 =move（b）时调用的是这个方法
		if (&rhs == this) return;
		delete m_char;
		*m_char = *(rhs.m_char);
		rhs.m_char = nullptr;
	}
	// =重载也一样
	_RuleOfFive& operator=(_RuleOfFive&& rhs) {
		if (&rhs == this)return *this;
		delete m_char;
		*m_char = *(rhs.m_char);
		rhs.m_char = nullptr;
		return *this;
	}
private:
	int* m_char;
};
#pragma endregion

#pragma region 编译器生成的析构函数，析构函数不要抛出异常

class A {
public:
	A() {}
};
class B :public A{//当析构函数是由编译器生成的时候， 
public:
	B() {}
	//默认 析构函数都是 noexcept ，当在析构函数抛出异常，程序会崩溃（调用terminal），
	//C++不能同时处理代码块中的多个异常 C++保证析构函数一定会调用到
	~B() { throw 1; }
	//编译器生成的析构函数相当于  应该尽量阻止编译器给我们声明析构函数，并且析构函数不能抛出异常
	inline ~B() noexcept{}//当调用完析构函数之后，还会调用成员变量的析构函数。在调用父类的析构函数
private:
	string m_string;
};

#pragma endregion

#pragma region 构造函数，可以在构造函数中抛出异常
//swpa 这类函数不要抛出异常
class GoodB {
public:
	GoodB(const char* f) :m_file(f, ios_base::in){
		if (!m_file.is_open()) throw string("could ont open file");
	}
private:
	fstream m_file;
};
#pragma endregion


#pragma region 多态
//当虚函数是外部可以访问到的，可以定义为virtual
class Event;
class Base {
	virtual ~Base() {}
	virtual void act(Event const&) = 0;
	virtual void print() const = 0;
	int id()const { return m_id; }
	virtual void update() {}
	Base(int _id) :m_id(_id) {}
private:
	int m_id;
};
class Drived :public Base {
public:
	void act(Event const&);
	void print()const;
	Drived(int);
	~Drived();
private:
};
class Grouped : public Base {
public:
	void act(Event const&);
	void print()const;
	void addBase(Base* b);
	void removeBase(int id);
	Grouped(int id);
	~Grouped();
private:
	map<int, Base*> m_info;
};
void test_01() {
	Drived* info = new Drived(1);
	Grouped* group = new Grouped(2);
	//Event ev;

	Base* baseGroup = group;

	Grouped* g = static_cast<Grouped*>( baseGroup);
	Grouped* ggg = (Grouped*)baseGroup;

	//它会判断是否可转换
	Grouped* gg = dynamic_cast<Grouped*>(baseGroup);

}

#pragma endregion

#pragma region auto
//通过右边的语句推导出 左边的类型
static void autoValue() {

	auto a = 10;
	auto name = string("lkx");
	auto height = 3.14f;
	auto width = 3.14;
	cout << "a is a" << typeid(a).name() << endl;//int
	cout << "name is a" << typeid(name).name() << endl;//string
	cout << "height is a" << typeid(height).name() << endl;//float
	cout << "width is a" << typeid(width).name() << endl;//double
}

static void autoPointer() {//同时也可推导 指针的类型
	auto age = new int(10);
	auto name = "LKX";// const char* name = "LKX"
	auto height = new float(3.14);
	auto width = new double(3.14);
}
//C++11的for循环
//迭代的时候 需要先加加 ++it
static void newVersionFor() {
	int a[] = { 1,2,3,4 };
	cout << "new version for" << "\n";
	for (auto v : a) {
		cout << v << " ";
	}
	cout << "\n";

	cout << "old version for" << "\n";
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";

	//对于标准容器也是通用的
	vector<int> group;
	for (size_t i = 0; i < 4; i++)
	{
		group.push_back(i);
	}

	cout << "old version " << endl;
	//小优化， 把不要每次都 取出end() 要 ++迭代器
	for (vector<int>::iterator it = group.begin(); it != group.end() ; ++it)
	{
		cout << *it << " ";
	}
	cout << "\n";

	for (size_t i = 0; i < group.size(); i++)
	{
		cout << group[i] << " ";
	}
	cout << "\n";

	cout << "auto version" << endl;
	for (auto v : group) {//此时 v只是拷贝出来的值，在循环中操作它不会改变容器中的数据
		cout << v << " ";
	}
	cout << "\n";

	for (auto& v : group) {//此时 改变v的数据，容器中的数据也相应的改变
		cout << v << " ";// 同时优化 拷贝操作
	}
	cout << endl;

	for (const auto& v : group) {//通过const可以防止 误操作
		cout << v << " ";
	}
	cout << endl;
}
#pragma endregion


#pragma region C++11新版构造

class NewVersionConstruct{
public:
	explicit NewVersionConstruct(int value): m_value(value) {}
	////构造时初始化参数
	NewVersionConstruct(int age) :m_age{ age }, m_height{130},m_weight(200) {}
private:
	int m_value{}; //当没有 确切的默认值 可用{}来代替
	int m_age = 18;//直接符初始值
	int m_height = 170;
	int m_weight = 75;
};


static void newVersionConstruct() {
	//行版本数组的声明方式
	int avector[] = { 1,2,3 };
	vector<int> v = { 1,2,3 };

	NewVersionConstruct n(10);
	NewVersionConstruct n1{ 10 };

	NewVersionConstruct n2(true);
	NewVersionConstruct n3{false};

	NewVersionConstruct n4(1.1);
	//NewVersionConstruct n5{ 1.2 }; 此时编译不会通过 宽的精度不能作为参数传入窄的精度
}


#pragma endregion

#pragma region 引用 以及右值

static void leftRefAndRightRef() {
	int a = 10;
	int aa = 20;
	int& refA = a;//引用的本质 int* const refA
	refA = 20;//此时 a也等于20
	refA = aa;//此时 refA改变的不是引用，而是数据即 *refA = aa

	const int& constRefA = a;//const引用本身可以指向一个右值
	//比如 构造函数时 (const int&) 此时可以传入 10 

	const int& cosntRefB = 10;//本质 const int* const cosntRefB


	auto&& rrA = 10;//右值
	rrA = 30;

	//左值转换右值 右值转换都是指向同一个地址
	int b = 20;
	int&& newRRB = move(b);
	const int&& newRRC = move(b);
	cout << &b << "address int&& " << &newRRB << "address const int&&" << &newRRC << "\n";
}

#pragma endregion



int main() {

	Good g;
	system("pause");
	return 0;
}