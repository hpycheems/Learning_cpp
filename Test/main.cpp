#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <future>
#include <string.h>
#include <memory>
#include <fstream>

/*
explicit 关键字
class Point {
public:
	int x, y;
	Point(int x = 0, int y = 0)
		: x(x), y(y) {}
};
void displayPoint(const Point& p)
{
	cout << "(" << p.x << ","
		 << p.y << ")" << endl;
}
int main()
{
	displayPoint(1);这样的方式却可以调用
	Point p = 1;
}
原因：隐式调用
即使你使用的是赋值操作符=, 也是会调用构造函数, 而不是重载的operator=运算符.
*/

#pragma region 链表反转
struct MyNode {
	MyNode* node;
	int num;
};

MyNode* reverse(MyNode* node) {
	//MyNode* q = node;
	//MyNode* p = node;
	//while (p->node != NULL) {
	//	p = p->node;
	//}
	//MyNode* temp = q->node;
	//p->node = temp;
	//temp->node = q;
	//q->node = NULL;
	//return p;
	MyNode* prev = 0;
	while (node) {
		MyNode* next = node->node;
		node->node = prev;
		prev = node;
		node = next;
	}
	node = prev;
	return node;
}

//指针 转换
void NewFunction01()
{
	MyNode n1, n2, n3;
	n3.num = 3;
	n3.node = &n2;
	n2.num = 2;
	n2.node = &n1;
	n1.num = 1;
	n1.node = NULL;

	MyNode* p = reverse(&n3);
	while (true) {
		cout << p->num << endl;
		if (p->node == NULL) {
			break;
		}
		p = p->node;
	}
}
#pragma endregion

//容器按指定位置转换
void changeOrder(vector<int>& objects, int pos) {
	//vector<int> newOrder;
	////newOrder.resize(objects.size());
	//vector<int>::iterator point = objects.begin();
	//for (int i = 0; i < pos; i++)
	//{
	//	point++;
	//}
	//for (vector<int>::iterator it = point; it != objects.end(); it++)
	//{
	//	newOrder.push_back(*it);
	//}
	////newOrder.push_back(*point);
	//for (vector<int>::iterator it = objects.begin(); it != point; it++)
	//{
	//	newOrder.push_back(*it);
	//}

	//for (vector<int>::iterator it = newOrder.begin(); it != newOrder.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;
	rotate(objects.begin(), objects.begin() + pos, objects.end());
	rotate(objects.begin(), objects.begin() + 1, objects.begin() + (objects.size() - pos));
	for (vector<int>::iterator it = objects.begin(); it != objects.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

#pragma region 有问题的代码（性能）

class BigObject {
private:
	char m_manyData[100000];
};
static void quizFour() {
	map<int, BigObject> group;//存放了很多数据 
	int whatYouFind = 100;
	//使用map 并且查找时 可以直接使用find
	map<int, BigObject>::iterator iter = group.find(whatYouFind);
	if (iter == group.end()) {

	}
	else {

	}

	for (map<int,BigObject>::iterator it = group.begin(); it != group.end(); it++)
	{
		if ((*it).first == whatYouFind) {
			(*it).second = group[whatYouFind];
			//BigObject obj;

			//group[whatYouFind] = obj;
		}
	}
}
#pragma endregion

#pragma region 创建对象时是否造成内存泄露 不会发生内存泄露
class ObjectA {
public:
	explicit ObjectA(int a):m_value(new int(a)) {
		cout << "ObjectA 的构造 "<< a  << endl;
	}
	~ObjectA() { 
		cout << "ObjectA 的析构" << endl;
		delete m_value; 
	}
private:
	int* m_value;
};
//构造没有完成，不会调用析构
class Evil {
public:
	Evil() { cout << "Evil 的构造" << endl; throw 10; }
	~Evil() { cout << "Evil 的析构" << endl; }
};

class Normal :public ObjectA {
public:
	explicit Normal(int a) : ObjectA(a), m_a(a + 1), m_resource(new int(a + 2)){
		cout << "Normal 的构造" << endl;
		if (m_resource) {
			std::cout << "m_resource is true";
		}
	}
	~Normal() { 
		cout << "Normal 的析构" << endl;
		delete m_resource; 
	}
private:
	ObjectA m_a;
	Evil m_evil;
	int* m_resource = nullptr;//当顺序调换时 会造成内存泄露
};
#pragma endregion

#pragma region Debug和发布 下的地址间隔不同
//debug相差 8 发布 相差 4
//原因 ：有4个字节被优化掉了 
//64位操作系统 通过寄存器传参

//在发布 时 通过寄存器传参 ，当没有打印地址时，不会在栈上预留
static void printAddress(int a, int b, int c) {
	cout << "a " << a << " " << &a << endl;
	cout << "b " << b << endl;
	cout << "c " << c << " " << &c << endl;
}
#pragma endregion

#pragma region 构造函数的隐式调用
class TestObject {
public:
	explicit TestObject(int a) :m_value(a){
		cout << "TestObject 有参的构造" << endl;
	}
	explicit TestObject(const TestObject& rhs) :m_value(rhs.m_value){
		cout << "TestObject 的拷贝构造" << endl;
	}
private:
	int m_value;
};

static void hasDifference() {
	TestObject a(2);
	//TestObject d = 2;

	TestObject b(a);
	//TestObject c = a;
}
#pragma endregion

#pragma region C++ 未定义 任何结果都是合法的

static int callFirst(int a) {
	cout << "callFirst" << a << endl;
	return ++a;
}
static int callSecond(int a) {
	cout << "callSecond" << a << endl;
	return --a;
}
static void print(int a, int b) {
	cout << "a " << a << " b " << b << endl;
}
//写法是否安全
class Test_01 {};
class Test_02 {};
void testPrtin(Test_01* a, Test_02* b) {
	try
	{

	}
	catch (const std::exception&)
	{

	}
	delete a;
	delete b;
}
void whoCallFirst() {
	int a = 10;
	++a;
	auto f = callFirst(a);
	auto s = callSecond(a);
	a--;
	print(f, s);

	// ++a 和 a--谁先执行都是可以的 所有是 未定义
	//print(callFirst(++a), callSecond(a--));

	//先给A分配内 同时给b分配内存， 当A抛出异常，a会把内存返回给系统，但b不会， 即内存泄露
	testPrtin(new Test_01(), new Test_02());//同时调用 new 是不安全的

	//auto a = new Test_01();
	//auto b = new Test_02();
	//testPrtin(a, b);
}


#pragma endregion

#pragma region 是否是空类
//通过模板继承的方式来判断是否是空类
template <class T>
struct EmptyHelper : T {//当父类不是空类时，会把父类的成员给继承下来
	int group[256];
};
class Empty {};
class NotEmpty { char a; };
class AontherEmpty :public Empty {};
class NotEmpty2 :public NotEmpty {};
bool isEmptyClass() {
	return false;
}
static void test() {
	
}

#pragma endregion

#pragma region C++为我们的类创建的函数

//当使用 map<int, Class>m 
//class 没有默认构造  则 m[1] = Claas(obj); 不会通过编译 
//因为 m[1] 先去map中查找， 如果m中不存在则插入一个新的Class 这个class 必须有默认构造函数
#pragma endregion

#pragma region namespace 
namespace NA{
	struct X {};
	struct Y {};
	void f(int) { cout << "A::f" << endl; }
	void g(X) { cout << "A::g\n"; }
}
namespace NB {
	void f(int i) {//循环调用 根据参数类型去调用匹配的函数
		f(i);
	}
	void g(NA::X x) {//调用NA下的g函数 原因：寻找函数
		//g(x);
	}
	void h(NA::Y y) {//A下面没有这个函数签名 ，则运行自身的。
		h(y);
	}
}
#pragma endregion

#pragma region sizeof相关
class A {};
class B { char m_data; };
class C { char m_data[100]; };
class D { char* m_data;
D() : m_data(new char[100]) {}
~D() { delete[] m_data; }
};
static void testSizeof() {
	cout << "bool sizeof" << sizeof(bool) << endl;//1
	cout << "char sizeof" << sizeof(char) << endl;//1
	cout << "int sizeof" << sizeof(int) << endl;//4
	char data[10];
	char* pData = data;
	cout << "char data[10] sizeof" << sizeof(data) << endl;//10
	cout << "char* sizeof" << sizeof(pData) << endl;//x86 4 x64 8
	cout << "A sizeof" << sizeof(A) << endl;//1
	cout << "B sizeof" << sizeof(B) << endl;//1
	cout << "C sizeof" << sizeof(C) << endl;//100
	cout << "D sizeof" << sizeof(D) << endl;//x86 4 x64 8
	cout << "size_t sizeof" << sizeof(size_t) << endl;//x86 4 x64 8
} 
static void unsignedAndSigned() {
	size_t a = 10; 
	//无符号与有符号作比较会存在陷阱 
	//但当有符号的数为 负数时，会转换成无符号的数，变成最大的数
	int b = -1;
	if (b < a) {
		cout << "right" << endl;
	}
	else {
		cout << "bad" << endl;
	}
}
#pragma endregion

#pragma region C++ 11 特性
void myPrint() {
	auto f = async([](int v) {cout << "hello world" << v << endl; }, 10);
	f.get(); //当调用get时， 函数是一定执行完成了的
}
#pragma endregion

#pragma region placementNew
class MyObject {
public:
	MyObject() {}
	~MyObject() {}

private:
	int m_data[100];
};
char info[10000];
void placementNew() {
	MyObject* s = new(info)MyObject(); //placementNew 
	//怎么释放资源
	s->~MyObject();//显示的调用析构
	//?
	delete s; //delete 调用默认的析构函数 将内存返回给系统
}
#pragma endregion

#pragma region 随机翻转

int rerangeOrder(vector<int> & arr, int v){
	vector<int> tempMin;
	vector<int> tempMax;
	int count = 0;
	int valCount = 0;
	for (vector<int> :: iterator it = arr.begin(); it != arr.end(); it++)
	{
		if(*it < v){
			tempMin.push_back(*it);
			count++;
		}
		else{
			if (*it == v) {
				valCount++;
			}
			else {
				tempMax.push_back(*it);
			}
		}
	}

	while (valCount > 0)
	{
		
		tempMin.push_back(v);
		valCount--;
	}
	for (vector<int>::iterator it = tempMax.begin(); it != tempMax.end(); it++)
	{
		tempMin.push_back(*it);
	}
	arr = tempMin;
	return count;
}

#pragma endregion

#pragma region dummyMalloc
void dummyMalloc(char* p) {
	p = (char*)malloc(8);//分配长度为8字节的内存块 
	//如果分配成功则返回指向被分配内存的指针，否则返回空指针NULL。
}
void dummyFunc() {
	char str[] = "Hello World";
	dummyMalloc(str);
	//从src地址开始
	//且含有null结束符的字符串复制到以dest地址开始的字符串中，并返回指向dest的指针。
	strcpy_s(str, "Hi World\n");
	//		dest	src

	auto n = printf(str);
}
#pragma	 endregion 

#pragma region vector容器的push_back是怎么样的 效率是否高， 怎么样让遍历容器更高效
void isGoodOrBad(const vector<int>& objects) {
	vector<int> tar;
	tar.reserve(100);// 每次开辟空间的大小
	int pos = 0;
	if (pos == objects.size() - 1) {
		tar.push_back(objects[pos]);//第一次调用的时候 会开辟一定的空间, 当空间不足时，先开辟较大的空间，并把原内容复制进去

		for (int i = 0; i < pos; i++)
		{
			tar.push_back(objects[i]);
		}
	}
}

#pragma endregion

#pragma region 使用的内存不会下降 如何下降

void isGoodOrBad1(vector<int>& objects) {
	sort(objects.begin(), objects.end());
	//大于10位之后的数 删除
	if (objects.size() > 10) objects.erase(objects.begin() + 10, objects.end());
	//
	objects.resize(10);
}

#pragma endregion

#pragma region 是否异常安全

template<class T>
class Stack {
public:
	//是否异常安全 这取决于T
	Stack() :m_data(0), m_capacity(20), m_used(0) { m_data = new T{ m_capacity }; }
	//是否异常安全
	~Stack() { delete[] m_data; }
private:
	T* m_data;
	int m_capacity;
	int m_used;
};

#pragma endregion

#pragma region 字符串反转
void changeStrs(char* data) {//优先使用给出来的算法
	string s = data;
	reverse(s.begin(), s.end());
	cout << s << endl;
	//reverse()
}
#pragma endregion


#pragma region 程序运行的结果
void func1() {
	int a = 0xFF;//256
	int b = a << 33;
	cout << "b is" << b << endl;//2
}
#pragma endregion


class Base {
public:
	virtual void func() {}
protected:
	~Base() {}
};
class Dertived : Base{
public:
	Dertived() { cout << "Dertived 的构造" << endl; }
	~Dertived() { cout << "Dertived 的析构" << endl; }
	void func() override {
		cout << "sun func " << "\n";
	}
};
void BaseTest(Base& b) {
	b.func();
}
void BaseTest() {
	Dertived d;
}

class Parent_1;
typedef shared_ptr<Parent_1> ParentPtr;
class Child {
public:
	ParentPtr father;
	~Child();
	Child();
};
typedef shared_ptr<Child> ChildPtr;
class Parent_1 {
public:
	ChildPtr son;
	~Parent_1();
	Parent_1();
};
Parent_1::Parent_1() { cout << "hello Parent" << "\n"; }
Child::Child() { cout << "Hello Child" << "\n"; }
Parent_1::~Parent_1() { cout << "bey Parent" << "\n"; }
Child::~Child() { cout << "bey Child" << "\n"; }
void testParentAndChild() {
	ParentPtr p(new Parent_1);
	ChildPtr c(new Child);
	p->son = c;
	c->father = p;
}
typedef unique_ptr<Parent_1> uniquePtr;
void sharedPtrWithWealPtr() {

	//ParentPtr obj(new Parent_1);//此时shared_ptr管理着一份资源
	//typedef weak_ptr<Parent_1> WeakParendPtr;
	//WeakParendPtr weakObj(obj);//此时 weakPtr指向obj
	//ParentPtr obj1(obj);
	//ParentPtr obj2 = obj;
	//obj.reset();
	//auto p = weakObj.lock();
	//if (p) {
	//	cout << "use count is" << p.use_count() << endl;
	//}
	//else {
	//	cout << "resource not person manager" << endl;
	//}
	//cout << "use count is" << obj1.use_count() << " " << obj2.use_count() << "\n";


	uniquePtr uniqueP(new Parent_1);// = make_shared<Parent_1>(); 这样会报错

	//auto uniaueP2 = uniqueP.release();

	//cout << typeid(uniaueP2).name() << endl;

	ParentPtr sharedP = move(uniqueP);

	//typedef weak_ptr<Parent_1> WeakParendPtr;
	//WeakParendPtr weakObj(obj);//此时 weakPtr指向obj
	//cout << "obj use count is" << obj.use_count() << "\n"; //此时输出的obj的use_count()为1
	//
	//{
	//	auto p = weakObj.lock();
	//	if (p) {
	//		//当p为有效的指针时 obj占一份，p占一份
	//		cout << "obj use count is" << obj.use_count() << "\n"; //2
	//	}
	//	else {

	//	}
	//}
	//cout << "obj use count is" << obj.use_count() << "\n"; //1
	//ParentPtr obj2 = obj;
	//WeakParendPtr weakobj2 = obj2;
	//cout << "obj use count is" << obj.use_count() << "\n"; //2
	////obj2.reset();
	////cout << "obj use count is" << obj.use_count() << "\n"; //1
	//obj.reset();//此时，obj不在管理， weakobj也会失效  use_count = 0 也就是说obj
	//cout << "obj use count is" << obj.use_count() << "\n"; //0
	//if (weakObj.expired()) {
	//	cout << "obj use count is" << obj.use_count() << "\n";
	//}
	//else {
	//	cout << "weakobj 失效" << endl;
	//}
	//obj.reset(new Parent_1);//此时 同样失效
	//weakObj = obj;//重新赋值后 继续生效
}


//class AdvenceParent {
//public:
//	int id();
//	AdvenceParent();
//	~AdvenceParent();
//};

class AdbenceChild {
public:
	int id();
	AdbenceChild();
	~AdbenceChild();
};
typedef shared_ptr<AdbenceChild> advenceChild_ptr;
int AdbenceChild::id() {
	return 1;
}
AdbenceChild::AdbenceChild() { cout << "hello child\n"; }
AdbenceChild::~AdbenceChild() { cout << "bey child\n"; }
void Test_2() {
	advenceChild_ptr obj = make_shared<AdbenceChild>();
	advenceChild_ptr obj2 = obj;
	obj.reset();
	if (obj2) {
		cout << obj2->id() << endl;
	}
}


#pragma region log文件写入

class Log {
public:
	Log(int id, std::string fileName) :m_id(id) { m_f.open("log.log", ios::out); }
	~Log() {}
	void log(const std::string& info) {
		std::cout << info;
		m_f << info;
	}
private:
	int m_id;
	std::fstream m_f;
};

static Log a(1, "log.log");
void logTest1() {
	a.log("hello ");
}
void logTest2() {
	a.log("world");
}
//answer
// hello //出现的原因：刚开始，构造出来的对象 打开的文件都只是指向文件的头部，只有在析构时才写入数据
// world //当输入文件后调用 flush()时，这时会写入文件
// hello world 把 static Log 从函数中提提取出来
// worldhello
#pragma endregion


class Lock {
public:
	Lock() { std::cout << "hello Lock\n"; }
	~Lock() { std::cout << "bey Lockn\n"; }
};

void LockFunc() {
	Lock a;
	throw 1;//即使抛出异常，也会调用 析构
}

int main() {
	//LockFunc();
	//logTest1();
	//logTest2();

	//testParentAndChild();
	//sharedPtrWithWealPtr();
	//Test_2();
	//BaseTest();
	//BaseTest(d);
	//NewFunction01();
	
	//vector<int> v;
	//for (int i = 0; i < 5; i++)
	//{
	//	v.push_back(i);
	//}
	//changeOrder(v, 2);

	try {
		Normal n(1);
		cout << "未抛出异常" << endl;
	}
	catch (...) {
		cout << "抛出异常" << endl;
	}

	//system("pause");
	//return 0;

	//testSizeof();
	//unsignedAndSigned();

	//hasDifference();

	//whoCallFirst();

	//NB::f(1);

	/*vector<int> temp;
	temp.push_back(1);
	temp.push_back(3);
	temp.push_back(4);
	temp.push_back(5);
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(3);

	int num = rerangeOrder(temp, 4);
	for (vector<int>::iterator it = temp.begin(); it != temp.end(); it++)
	{
		cout << *it << "  " << endl;
	}
	cout << endl;

	cout << "比4大的数的个数" << num << endl;*/


	//dummyFunc();

	//char arr[] = "Hello World!";
	//changeStrs(arr);

	//func1();

	system("pause");
	return 0;

}


