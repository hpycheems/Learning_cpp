#include<iostream>
using namespace std;
#include <fstream>
#include<vector>
#include<map>
#include <string>
#include <memory>
#include "Good.h"
#include <assert.h>

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

#pragma region 构造函数，构造错误时 可以在构造函数中抛出异常
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


#pragma region 多态 虚函数 虚析构函数
//当虚函数是外部可以访问到的，可以定义为virtual
// 在构造函数和析构函数中调用虚函数时，不会存在多态的作用
// 类在构造过程中，并没有生成出来
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
	//新版本数组的声明方式
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

#pragma region C++11 内存管理的改进

void versionOne() {
	//C
	int* ageC = (int*)malloc(sizeof(int));
	if (ageC) {

	}
	free(ageC);

	//C++
	int* age = new int(20);//分配资源，分配空间  调用构造函数
	int* height = new int(130);
	cout << age << " " << height << " " << "\n";
	//在类中 可以通过 构造和析构 来解决内存开辟和释放
	delete age;
	delete height;
}
//解决内存泄露问题  智能指针
//4种智能指针 都在头文件 memory
//auto_ptr 不使用
//shared_ptr 
class SharedPtrObject {
public:
	SharedPtrObject(int id) :m_id(id) { cout << "init obj" << m_id << endl; }
	~SharedPtrObject() { cout << "bye bye " << m_id << endl; }
	int id()const { return m_id; }
private:
	int m_id;
};
//智能指针
typedef shared_ptr<SharedPtrObject> ObjectPtr;

void print(ObjectPtr obj);
void printRef(ObjectPtr& obj);
void print(const SharedPtrObject& obj);
void interfaceOfSharedPtr() {
	ObjectPtr null;//裸指针
	cout << "ref count is " << null.use_count() << endl; // 0
	ObjectPtr obj(new SharedPtrObject(1));
	cout << "ref count is " << obj.use_count() << endl; // 1
	ObjectPtr obj2(obj);
	cout << "ref count is" << obj.use_count() << endl;//2
	cout << "ref count obj2 is" << obj2.use_count() << endl;//2
	ObjectPtr obj3 = obj;
	cout << "ref count is" << obj.use_count() << endl;//3
	//移除
	obj2.reset();// 也可 obj2 = nullptr;
	cout << "ref count is" << obj.use_count() << endl;//2

	ObjectPtr obj4;
	obj3.swap(obj4);
	swap(obj3, obj4);//交换
	cout << "ref count is" << obj.use_count() << endl;//2

	//使用
	auto p = obj.get();
	if (p) {
		cout << "id is" << p->id() << endl;
	}
	//建议这样使用
	if (obj) {
		cout << "id is" << (*obj).id() << endl;// operator*
		cout << "id is" << obj->id() << endl;// operatro->
	}

	obj4 = nullptr;
	//if(obj.unique())
	//if(obj.use_count() == 1)
	//判断是否只存在一人在使用
	cout << "only one hold ptr" << obj.unique() << endl;

	//作为参数 作为值（在多线程中用）， 作为引用
	print(obj);
	printRef(obj);
	print(*obj);
}
void print(ObjectPtr obj) {
	cout << "count " << obj.use_count() << endl;//引用次数加1 为3
}
void printRef(const ObjectPtr& obj) {//以Obj本身作为参数
	cout << "count" << obj.use_count() << endl;
}
void print(const SharedPtrObject& obj) {//通过引用传入的 不会发生变化
	
}
void deleteOfObject(SharedPtrObject* obj) {
	if (obj)
		cout << "delete obj" << endl;

	delete obj;
}
//智能指针构造是 还可以传入一个参数（方法）来释放内存
void useDeleter() {
	ObjectPtr obj(new SharedPtrObject(2), deleteOfObject);
}

//使用智能指针出现的问题
class Parent_1;
typedef shared_ptr<Parent_1> ParentPtr;
typedef weak_ptr<Parent_1> weakParetPtr;
class Child {
public:
	weakParetPtr father;//把ParentPtr换成weakParetPtr 来打破循环
	~Child();
	Child();
};
typedef shared_ptr<Child> ChildPtr;
typedef weak_ptr<Child> weakChildPtr;
class Parent_1 {
public:
	ChildPtr son;
	~Parent_1();
	Parent_1();
};
Parent_1::Parent_1() { cout << "hello Parent" << "\n"; }
Child::Child() { cout << "Hello Child" << "\n";}
Parent_1::~Parent_1() { cout << "bey Parent" << "\n"; }
Child::~Child() { cout << "bey Child" << "\n"; }
void testParentAndChild() {
	ParentPtr p(new Parent_1());//彼此间相互引用智能指针时的问题
	ChildPtr c(new Child());//智能指针析构时 只是 use_count() - 1
	p->son = c;//c->use_count() = 2 and p->use_count() = 1
	c->father = p;//p->use_count() = 2 and c->use_count() = 2
}//此时 智能指针 管理的内存不会释放即， new出来的对象的析构函数不会被调用

//成员函数调用 自身智能指针时 的问题
// 问题解决 派生自 enable_shared_from_this<自己>
class Parent_2;
typedef shared_ptr<Parent_2> parend_2Ptr;
typedef weak_ptr<Parent_2> weakParend_2Ptr;
class Child_2{
public:
	weakParend_2Ptr father;
	Child_2();
	~Child_2();
	void checkRelation();
	int id();

};
typedef shared_ptr<Child_2> child_2Ptr;
typedef weak_ptr<Child_2> weakChild_2Ptr;
class Parent_2 : public enable_shared_from_this<Parent_2>{
public:
	weakChild_2Ptr son;
	Parent_2();
	~Parent_2();
	void checkRelation();
};

void handleChildAndPraentRef(const parend_2Ptr& p, const child_2Ptr& s){
	
}
Child_2::Child_2() { cout << "hello child\n"; }
Child_2::~Child_2() { cout << "bey child\n"; }
Parent_2::Parent_2() { cout << "hello parent\n"; }
Parent_2::~Parent_2() { cout << "bey parent\n"; }
void Parent_2::checkRelation() {
	auto ps = this->son.lock();
	if (ps) {

		//伪造自身智能指针
		//parend_2Ptr p(this);
		//当派生自 enable_shared_from_this<>时
		handleChildAndPraentRef(shared_from_this(), ps);//此时会出错
	}//构造一个parent 析构两个 parent
}
//weaked_prt 打破shared_ptr的循环引用 
//当shared_ptr的资源还有人在管理的时候，weak_ptr不会失效
void sharedPtrWithWealPtr() {

	ParentPtr obj(new Parent_1);//此时shared_ptr管理着一份资源
	typedef weak_ptr<Parent_1> WeakParendPtr;
	WeakParendPtr weakObj(obj);//此时 weakPtr指向obj
	cout << "obj use count is" << obj.use_count() << "\n"; //此时输出的obj的use_count()为1
	{
		auto p = weakObj.lock();
		if (p) {
			//当p为有效的指针时 obj占一份，p占一份
			cout << "obj use count is" << obj.use_count() << "\n"; //2
		}
		else {

		}
	}
	obj.reset();//此时，obj不在管理， weakobj也会失效
	obj.reset(new Parent_1);//此时 同样失效
	weakObj = obj;//重新赋值后 继续生效
	//判读wealptr是否有效
	if (weakObj.expired()) {
		cout << "有效" << endl;
	}
	else {
		cout << "无效" << endl;
	}
}

//unique_ptr
//用法
void print(const UniqueChild_2Ptr& obj);
void transfer(UniqueChild_2Ptr obj);
typedef unique_ptr<Child_2> UniqueChild_2Ptr;
void uniquePtr() {

	UniqueChild_2Ptr obj(new Child_2);
	auto p = obj.get();
	if (p) {

	}

	//beter
	if (obj) {

	}

	//opterator -> *
	cout << p->id() << obj->id() << (*obj).id() << "\n";
	print(obj);//某一时间 由uniqueptr管理的资源只能有一个在使用
	p = obj.release();//释放 uniqueptr
	delete p;

	obj.reset();//delete管理的指针
	obj.reset(new Child_2);//释放原理的指针 并管理新建的指针
	//
	transfer(move(obj));
	cout << obj->id() << "\n";//此时obj是无效的

	// 从uniqueptr 转移到 shared_ptr
	obj.reset(new Child_2);
	child_2Ptr sharedPtr(move(obj));
	assert(obj == nullptr);
}
void print(const UniqueChild_2Ptr& obj) {}
void transfer(UniqueChild_2Ptr obj){
	cout << obj->id() << endl;
}

#pragma endregion


#pragma region 智能指针的坑

void sharedPtrNotice() {

	//前提：绝对不要自己手动的管理资源
	int* a = new int(10);
	delete a;
	int* b = (int*)malloc(sizeof(int));
	if (b) {
		free(b);
	}

	//一个裸的指针不要用两个shaded_ptr管理，unique_ptr
	auto pObj = new Child_2();
	child_2Ptr obj(pObj);
	child_2Ptr obj2(pObj);

	//用 weak_ptr打破循环引用，parrent 和child
	//当需要再类的内部接口中，如果需要将this作为智能指针来使用的话，
	//需要用该类派生自enable_shared_form_this

	//使用shared_ptr作为函数的接口，如果有可能 用const shared_ptr&的形式
	//多线程模式下使用shared_prt需要注意的事项(多线程编程的时候)

	//shared_ptr weak_ptr 和裸指针相比， 会大很多，并且效率上会有影响。尤其是在多线程模式下
	child_2Ptr obj3(new Child_2);//这样会调用两次构造函数
	child_2Ptr obj4 = obj3;

	//应该使用这种方式创建智能指针
	child_2Ptr obj5 = make_shared<Child_2>();

	//enable_shared_form_this shared_from_this()和构造析构函数一样，某些情况下是不能使用的，
	// 例如在构造析构函数下是不能使用的

	//某些情况下，会出现内存不会降的问题，尤其是使用weak_ptr来处理循环引用的问题(weak_ptr 勾着)

	//如果有可能，优先使用类的实例，其次万不得已使用unique_ptr,
	//万不得已使用shared_ptr;
}

#pragma endregion

#pragma region Lambda
//将一个inline函数 作为参数 local对象

//作为参数
template<class Func>
void printUseFunc(Func func, int a, int c, int b) {
	func(a, b, c);
}
void LambdaTest() {

	auto local = [](int a, int b, int c) {
		cout << "a =" << a << "b =" << b << "c = " << c << "\n";
	};
	auto local1 = []{cout << "hello Lambda\n";  };
	//作为参数
	printUseFunc([](int a, int b, int c) {
		cout << "a =" << a << "b =" << b << "c = " << c << "\n";
		}, 1, 2, 3);

	int a = 10;
	int b = 20;
	int c = 30;
	auto local2 = [=]() {};
	//需要调用才可执行此函数
	local2();//此时传入任何参数都会以拷贝的形式 拷贝一份来使用
	auto local3 = [&]() {};
	local3();//此时传入任何参数都会以传参的形式传递
	auto local4 = [a, b, c]() {};
	local4();//此时是拷贝的形式
	auto local5 = [&a, &b, &c]() {};
	local5();//此时是引用传递

}
#pragma endregion

int main() {

	Good g;
	system("pause");
	return 0;
}