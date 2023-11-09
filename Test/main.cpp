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
explicit �ؼ���
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
	displayPoint(1);�����ķ�ʽȴ���Ե���
	Point p = 1;
}
ԭ����ʽ����
��ʹ��ʹ�õ��Ǹ�ֵ������=, Ҳ�ǻ���ù��캯��, ���������ص�operator=�����.
*/

#pragma region ����ת
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

//ָ�� ת��
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

//������ָ��λ��ת��
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

#pragma region ������Ĵ��루���ܣ�

class BigObject {
private:
	char m_manyData[100000];
};
static void quizFour() {
	map<int, BigObject> group;//����˺ܶ����� 
	int whatYouFind = 100;
	//ʹ��map ���Ҳ���ʱ ����ֱ��ʹ��find
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

#pragma region ��������ʱ�Ƿ�����ڴ�й¶ ���ᷢ���ڴ�й¶
class ObjectA {
public:
	explicit ObjectA(int a):m_value(new int(a)) {
		cout << "ObjectA �Ĺ��� "<< a  << endl;
	}
	~ObjectA() { 
		cout << "ObjectA ������" << endl;
		delete m_value; 
	}
private:
	int* m_value;
};
//����û����ɣ������������
class Evil {
public:
	Evil() { cout << "Evil �Ĺ���" << endl; throw 10; }
	~Evil() { cout << "Evil ������" << endl; }
};

class Normal :public ObjectA {
public:
	explicit Normal(int a) : ObjectA(a), m_a(a + 1), m_resource(new int(a + 2)){
		cout << "Normal �Ĺ���" << endl;
		if (m_resource) {
			std::cout << "m_resource is true";
		}
	}
	~Normal() { 
		cout << "Normal ������" << endl;
		delete m_resource; 
	}
private:
	ObjectA m_a;
	Evil m_evil;
	int* m_resource = nullptr;//��˳�����ʱ ������ڴ�й¶
};
#pragma endregion

#pragma region Debug�ͷ��� �µĵ�ַ�����ͬ
//debug��� 8 ���� ��� 4
//ԭ�� ����4���ֽڱ��Ż����� 
//64λ����ϵͳ ͨ���Ĵ�������

//�ڷ��� ʱ ͨ���Ĵ������� ����û�д�ӡ��ַʱ��������ջ��Ԥ��
static void printAddress(int a, int b, int c) {
	cout << "a " << a << " " << &a << endl;
	cout << "b " << b << endl;
	cout << "c " << c << " " << &c << endl;
}
#pragma endregion

#pragma region ���캯������ʽ����
class TestObject {
public:
	explicit TestObject(int a) :m_value(a){
		cout << "TestObject �вεĹ���" << endl;
	}
	explicit TestObject(const TestObject& rhs) :m_value(rhs.m_value){
		cout << "TestObject �Ŀ�������" << endl;
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

#pragma region C++ δ���� �κν�����ǺϷ���

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
//д���Ƿ�ȫ
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

	// ++a �� a--˭��ִ�ж��ǿ��Ե� ������ δ����
	//print(callFirst(++a), callSecond(a--));

	//�ȸ�A������ ͬʱ��b�����ڴ棬 ��A�׳��쳣��a����ڴ淵�ظ�ϵͳ����b���ᣬ ���ڴ�й¶
	testPrtin(new Test_01(), new Test_02());//ͬʱ���� new �ǲ���ȫ��

	//auto a = new Test_01();
	//auto b = new Test_02();
	//testPrtin(a, b);
}


#pragma endregion

#pragma region �Ƿ��ǿ���
//ͨ��ģ��̳еķ�ʽ���ж��Ƿ��ǿ���
template <class T>
struct EmptyHelper : T {//�����಻�ǿ���ʱ����Ѹ���ĳ�Ա���̳�����
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

#pragma region C++Ϊ���ǵ��ഴ���ĺ���

//��ʹ�� map<int, Class>m 
//class û��Ĭ�Ϲ���  �� m[1] = Claas(obj); ����ͨ������ 
//��Ϊ m[1] ��ȥmap�в��ң� ���m�в����������һ���µ�Class ���class ������Ĭ�Ϲ��캯��
#pragma endregion

#pragma region namespace 
namespace NA{
	struct X {};
	struct Y {};
	void f(int) { cout << "A::f" << endl; }
	void g(X) { cout << "A::g\n"; }
}
namespace NB {
	void f(int i) {//ѭ������ ���ݲ�������ȥ����ƥ��ĺ���
		f(i);
	}
	void g(NA::X x) {//����NA�µ�g���� ԭ��Ѱ�Һ���
		//g(x);
	}
	void h(NA::Y y) {//A����û���������ǩ�� ������������ġ�
		h(y);
	}
}
#pragma endregion

#pragma region sizeof���
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
	//�޷������з������Ƚϻ�������� 
	//�����з��ŵ���Ϊ ����ʱ����ת�����޷��ŵ��������������
	int b = -1;
	if (b < a) {
		cout << "right" << endl;
	}
	else {
		cout << "bad" << endl;
	}
}
#pragma endregion

#pragma region C++ 11 ����
void myPrint() {
	auto f = async([](int v) {cout << "hello world" << v << endl; }, 10);
	f.get(); //������getʱ�� ������һ��ִ������˵�
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
	//��ô�ͷ���Դ
	s->~MyObject();//��ʾ�ĵ�������
	//?
	delete s; //delete ����Ĭ�ϵ��������� ���ڴ淵�ظ�ϵͳ
}
#pragma endregion

#pragma region �����ת

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
	p = (char*)malloc(8);//���䳤��Ϊ8�ֽڵ��ڴ�� 
	//�������ɹ��򷵻�ָ�򱻷����ڴ��ָ�룬���򷵻ؿ�ָ��NULL��
}
void dummyFunc() {
	char str[] = "Hello World";
	dummyMalloc(str);
	//��src��ַ��ʼ
	//�Һ���null���������ַ������Ƶ���dest��ַ��ʼ���ַ����У�������ָ��dest��ָ�롣
	strcpy_s(str, "Hi World\n");
	//		dest	src

	auto n = printf(str);
}
#pragma	 endregion 

#pragma region vector������push_back����ô���� Ч���Ƿ�ߣ� ��ô���ñ�����������Ч
void isGoodOrBad(const vector<int>& objects) {
	vector<int> tar;
	tar.reserve(100);// ÿ�ο��ٿռ�Ĵ�С
	int pos = 0;
	if (pos == objects.size() - 1) {
		tar.push_back(objects[pos]);//��һ�ε��õ�ʱ�� �Ὺ��һ���Ŀռ�, ���ռ䲻��ʱ���ȿ��ٽϴ�Ŀռ䣬����ԭ���ݸ��ƽ�ȥ

		for (int i = 0; i < pos; i++)
		{
			tar.push_back(objects[i]);
		}
	}
}

#pragma endregion

#pragma region ʹ�õ��ڴ治���½� ����½�

void isGoodOrBad1(vector<int>& objects) {
	sort(objects.begin(), objects.end());
	//����10λ֮����� ɾ��
	if (objects.size() > 10) objects.erase(objects.begin() + 10, objects.end());
	//
	objects.resize(10);
}

#pragma endregion

#pragma region �Ƿ��쳣��ȫ

template<class T>
class Stack {
public:
	//�Ƿ��쳣��ȫ ��ȡ����T
	Stack() :m_data(0), m_capacity(20), m_used(0) { m_data = new T{ m_capacity }; }
	//�Ƿ��쳣��ȫ
	~Stack() { delete[] m_data; }
private:
	T* m_data;
	int m_capacity;
	int m_used;
};

#pragma endregion

#pragma region �ַ�����ת
void changeStrs(char* data) {//����ʹ�ø��������㷨
	string s = data;
	reverse(s.begin(), s.end());
	cout << s << endl;
	//reverse()
}
#pragma endregion


#pragma region �������еĽ��
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
	Dertived() { cout << "Dertived �Ĺ���" << endl; }
	~Dertived() { cout << "Dertived ������" << endl; }
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

	//ParentPtr obj(new Parent_1);//��ʱshared_ptr������һ����Դ
	//typedef weak_ptr<Parent_1> WeakParendPtr;
	//WeakParendPtr weakObj(obj);//��ʱ weakPtrָ��obj
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


	uniquePtr uniqueP(new Parent_1);// = make_shared<Parent_1>(); �����ᱨ��

	//auto uniaueP2 = uniqueP.release();

	//cout << typeid(uniaueP2).name() << endl;

	ParentPtr sharedP = move(uniqueP);

	//typedef weak_ptr<Parent_1> WeakParendPtr;
	//WeakParendPtr weakObj(obj);//��ʱ weakPtrָ��obj
	//cout << "obj use count is" << obj.use_count() << "\n"; //��ʱ�����obj��use_count()Ϊ1
	//
	//{
	//	auto p = weakObj.lock();
	//	if (p) {
	//		//��pΪ��Ч��ָ��ʱ objռһ�ݣ�pռһ��
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
	//obj.reset();//��ʱ��obj���ڹ��� weakobjҲ��ʧЧ  use_count = 0 Ҳ����˵obj
	//cout << "obj use count is" << obj.use_count() << "\n"; //0
	//if (weakObj.expired()) {
	//	cout << "obj use count is" << obj.use_count() << "\n";
	//}
	//else {
	//	cout << "weakobj ʧЧ" << endl;
	//}
	//obj.reset(new Parent_1);//��ʱ ͬ��ʧЧ
	//weakObj = obj;//���¸�ֵ�� ������Ч
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


#pragma region log�ļ�д��

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
// hello //���ֵ�ԭ�򣺸տ�ʼ����������Ķ��� �򿪵��ļ���ֻ��ָ���ļ���ͷ����ֻ��������ʱ��д������
// world //�������ļ������ flush()ʱ����ʱ��д���ļ�
// hello world �� static Log �Ӻ���������ȡ����
// worldhello
#pragma endregion


class Lock {
public:
	Lock() { std::cout << "hello Lock\n"; }
	~Lock() { std::cout << "bey Lockn\n"; }
};

void LockFunc() {
	Lock a;
	throw 1;//��ʹ�׳��쳣��Ҳ����� ����
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
		cout << "δ�׳��쳣" << endl;
	}
	catch (...) {
		cout << "�׳��쳣" << endl;
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

	cout << "��4������ĸ���" << num << endl;*/


	//dummyFunc();

	//char arr[] = "Hello World!";
	//changeStrs(arr);

	//func1();

	system("pause");
	return 0;

}


