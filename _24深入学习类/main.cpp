#include<iostream>
using namespace std;
#include <fstream>
#include<vector>
#include<map>
#include <string>
#include <memory>
#include "Good.h"
#include <assert.h>

#pragma region ǰ������
//ǰ������ ����������
// ��ͷ�ļ��У� �������ٵ�����ͷ�ļ� Parent Child������
// �����ڼ̳е�ʱ�򣬼̳еı��ͷ�ļ�����Ҫ���������� ����ʹ��ǰ������
// ���������Ϊ����ĳ�Ա ��ָ������� ��Ҳ��Ҫ��ͷ�ļ���������
// ��������������ǳ�Ա���������� ��Ҳ����Ҫ���� 

// ����Ϊ����ֵ���β�ʱ�ǲ���ҪҪ����ͷ�ļ���
class RuleOfFive;
class Parent;
class Child {
public:
	//��ʱParent��δ�������ͣ� ���д���ʱ ����Ҫʹ��ָ�������
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

#pragma region �����͹��캯��
//�Զ����� 
//delete ʱ����
class RuleOfThree {
	//��ά��ָ��ʱ ��Ȼ���Զ����������������� ��������Ҫ�Զ��������������ͷ��ڴ�
	char* cstring;
public:
	RuleOfThree(const char* arg):cstring(new char[strlen(arg + 1)]) {
		strcpy(cstring, arg);
	}
	~RuleOfThree() {
		delete[] cstring;
	}
	//��Ҫ��Ĭ�ϵĿ�����ǳ���� �Լ�ʵ�����
	RuleOfThree(const RuleOfThree& other) {
		cstring = new char[strlen(other.cstring) + 1];
		strcpy(other.cstring, cstring);
	}
	//����= Ĭ�ϵ�Ҳ��ǳ��������Ҫ�Լ�ʵ�����
	RuleOfThree& operator=(const RuleOfThree& other) {
		char* tem_cstring = new char[strlen(other.cstring) + 1];
		strcpy(tem_cstring, other.cstring);
		delete[] cstring;
		cstring = tem_cstring;
		return *this;
	}
};
//������Ҫ��������ʱ
//�ѿ������캯�� ����private
//C++11 ���� RuleOfThree(const RuleOfThree& other) = delete;

//C++11 �Ż���������
vector<int> makeVector() {
	vector<int> v(100);
	for (int i = 0; i < 100; i++)
	{
		v[i] = rand() % 101;
	}
	return v;
}

//C++ ��Ĺ����������5������
//��ֵ����ֵ ��ֵ��ȡ��ַ ��ֵ����  ��Ȼ������ȡ��ʱ���������ã�������ȡconst����
//���ڿ������죬 �βδ��뾡���� ��const����
void leftOrRight() {
	int a = 0;
	int b;
	int c = 2 + 3;
	int d = a + c;
	auto address = &a;
	//��ֵ����
	int&& re = 2;

	//std:move(b) �ñ�������취��b�����ֵ ����֮�� ��������ʹ��b
}
//move�������õ���ֵ�������� ������Ҫʱ Ҳ��delete��
class _RuleOfFive {
public:
	_RuleOfFive(const _RuleOfFive& rhs) :m_char(new int(*rhs.m_char)) {}
	_RuleOfFive(_RuleOfFive&& rhs) {//���� =move��b��ʱ���õ����������
		if (&rhs == this) return;
		delete m_char;
		*m_char = *(rhs.m_char);
		rhs.m_char = nullptr;
	}
	// =����Ҳһ��
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

#pragma region ���������ɵ���������������������Ҫ�׳��쳣

class A {
public:
	A() {}
};
class B :public A{//�������������ɱ��������ɵ�ʱ�� 
public:
	B() {}
	//Ĭ�� ������������ noexcept ���������������׳��쳣����������������terminal����
	//C++����ͬʱ���������еĶ���쳣 C++��֤��������һ������õ�
	~B() { throw 1; }
	//���������ɵ����������൱��  Ӧ�þ�����ֹ�������������������������������������������׳��쳣
	inline ~B() noexcept{}//����������������֮�󣬻�����ó�Ա�����������������ڵ��ø������������
private:
	string m_string;
};

#pragma endregion

#pragma region ���캯�����������ʱ �����ڹ��캯�����׳��쳣
//swpa ���ຯ����Ҫ�׳��쳣
class GoodB {
public:
	GoodB(const char* f) :m_file(f, ios_base::in){
		if (!m_file.is_open()) throw string("could ont open file");
	}
private:
	fstream m_file;
};
#pragma endregion


#pragma region ��̬ �麯�� ����������
//���麯�����ⲿ���Է��ʵ��ģ����Զ���Ϊvirtual
// �ڹ��캯�������������е����麯��ʱ��������ڶ�̬������
// ���ڹ�������У���û�����ɳ���
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

	//�����ж��Ƿ��ת��
	Grouped* gg = dynamic_cast<Grouped*>(baseGroup);
}

#pragma endregion

#pragma region auto
//ͨ���ұߵ�����Ƶ��� ��ߵ�����
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

static void autoPointer() {//ͬʱҲ���Ƶ� ָ�������
	auto age = new int(10);
	auto name = "LKX";// const char* name = "LKX"
	auto height = new float(3.14);
	auto width = new double(3.14);
}
//C++11��forѭ��
//������ʱ�� ��Ҫ�ȼӼ� ++it
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

	//���ڱ�׼����Ҳ��ͨ�õ�
	vector<int> group;
	for (size_t i = 0; i < 4; i++)
	{
		group.push_back(i);
	}

	cout << "old version " << endl;
	//С�Ż��� �Ѳ�Ҫÿ�ζ� ȡ��end() Ҫ ++������
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
	for (auto v : group) {//��ʱ vֻ�ǿ���������ֵ����ѭ���в���������ı������е�����
		cout << v << " ";
	}
	cout << "\n";

	for (auto& v : group) {//��ʱ �ı�v�����ݣ������е�����Ҳ��Ӧ�ĸı�
		cout << v << " ";// ͬʱ�Ż� ��������
	}
	cout << endl;

	for (const auto& v : group) {//ͨ��const���Է�ֹ �����
		cout << v << " ";
	}
	cout << endl;
}
#pragma endregion


#pragma region C++11�°湹��

class NewVersionConstruct{
public:
	explicit NewVersionConstruct(int value): m_value(value) {}
	////����ʱ��ʼ������
	NewVersionConstruct(int age) :m_age{ age }, m_height{130},m_weight(200) {}
private:
	int m_value{}; //��û�� ȷ�е�Ĭ��ֵ ����{}������
	int m_age = 18;//ֱ�ӷ���ʼֵ
	int m_height = 170;
	int m_weight = 75;
};


static void newVersionConstruct() {
	//�°汾�����������ʽ
	int avector[] = { 1,2,3 };
	vector<int> v = { 1,2,3 };

	NewVersionConstruct n(10);
	NewVersionConstruct n1{ 10 };

	NewVersionConstruct n2(true);
	NewVersionConstruct n3{false};

	NewVersionConstruct n4(1.1);
	//NewVersionConstruct n5{ 1.2 }; ��ʱ���벻��ͨ�� ��ľ��Ȳ�����Ϊ��������խ�ľ���
}


#pragma endregion

#pragma region ���� �Լ���ֵ

static void leftRefAndRightRef() {
	int a = 10;
	int aa = 20;
	int& refA = a;//���õı��� int* const refA
	refA = 20;//��ʱ aҲ����20
	refA = aa;//��ʱ refA�ı�Ĳ������ã��������ݼ� *refA = aa

	const int& constRefA = a;//const���ñ������ָ��һ����ֵ
	//���� ���캯��ʱ (const int&) ��ʱ���Դ��� 10 

	const int& cosntRefB = 10;//���� const int* const cosntRefB


	auto&& rrA = 10;//��ֵ
	rrA = 30;

	//��ֵת����ֵ ��ֵת������ָ��ͬһ����ַ
	int b = 20;
	int&& newRRB = move(b);
	const int&& newRRC = move(b);
	cout << &b << "address int&& " << &newRRB << "address const int&&" << &newRRC << "\n";
}

#pragma endregion

#pragma region C++11 �ڴ����ĸĽ�

void versionOne() {
	//C
	int* ageC = (int*)malloc(sizeof(int));
	if (ageC) {

	}
	free(ageC);

	//C++
	int* age = new int(20);//������Դ������ռ�  ���ù��캯��
	int* height = new int(130);
	cout << age << " " << height << " " << "\n";
	//������ ����ͨ�� ��������� ������ڴ濪�ٺ��ͷ�
	delete age;
	delete height;
}
//����ڴ�й¶����  ����ָ��
//4������ָ�� ����ͷ�ļ� memory
//auto_ptr ��ʹ��
//shared_ptr 
class SharedPtrObject {
public:
	SharedPtrObject(int id) :m_id(id) { cout << "init obj" << m_id << endl; }
	~SharedPtrObject() { cout << "bye bye " << m_id << endl; }
	int id()const { return m_id; }
private:
	int m_id;
};
//����ָ��
typedef shared_ptr<SharedPtrObject> ObjectPtr;

void print(ObjectPtr obj);
void printRef(ObjectPtr& obj);
void print(const SharedPtrObject& obj);
void interfaceOfSharedPtr() {
	ObjectPtr null;//��ָ��
	cout << "ref count is " << null.use_count() << endl; // 0
	ObjectPtr obj(new SharedPtrObject(1));
	cout << "ref count is " << obj.use_count() << endl; // 1
	ObjectPtr obj2(obj);
	cout << "ref count is" << obj.use_count() << endl;//2
	cout << "ref count obj2 is" << obj2.use_count() << endl;//2
	ObjectPtr obj3 = obj;
	cout << "ref count is" << obj.use_count() << endl;//3
	//�Ƴ�
	obj2.reset();// Ҳ�� obj2 = nullptr;
	cout << "ref count is" << obj.use_count() << endl;//2

	ObjectPtr obj4;
	obj3.swap(obj4);
	swap(obj3, obj4);//����
	cout << "ref count is" << obj.use_count() << endl;//2

	//ʹ��
	auto p = obj.get();
	if (p) {
		cout << "id is" << p->id() << endl;
	}
	//��������ʹ��
	if (obj) {
		cout << "id is" << (*obj).id() << endl;// operator*
		cout << "id is" << obj->id() << endl;// operatro->
	}

	obj4 = nullptr;
	//if(obj.unique())
	//if(obj.use_count() == 1)
	//�ж��Ƿ�ֻ����һ����ʹ��
	cout << "only one hold ptr" << obj.unique() << endl;

	//��Ϊ���� ��Ϊֵ���ڶ��߳����ã��� ��Ϊ����
	print(obj);
	printRef(obj);
	print(*obj);
}
void print(ObjectPtr obj) {
	cout << "count " << obj.use_count() << endl;//���ô�����1 Ϊ3
}
void printRef(const ObjectPtr& obj) {//��Obj������Ϊ����
	cout << "count" << obj.use_count() << endl;
}
void print(const SharedPtrObject& obj) {//ͨ�����ô���� ���ᷢ���仯
	
}
void deleteOfObject(SharedPtrObject* obj) {
	if (obj)
		cout << "delete obj" << endl;

	delete obj;
}
//����ָ�빹���� �����Դ���һ�����������������ͷ��ڴ�
void useDeleter() {
	ObjectPtr obj(new SharedPtrObject(2), deleteOfObject);
}

//ʹ������ָ����ֵ�����
class Parent_1;
typedef shared_ptr<Parent_1> ParentPtr;
typedef weak_ptr<Parent_1> weakParetPtr;
class Child {
public:
	weakParetPtr father;//��ParentPtr����weakParetPtr ������ѭ��
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
	ParentPtr p(new Parent_1());//�˴˼��໥��������ָ��ʱ������
	ChildPtr c(new Child());//����ָ������ʱ ֻ�� use_count() - 1
	p->son = c;//c->use_count() = 2 and p->use_count() = 1
	c->father = p;//p->use_count() = 2 and c->use_count() = 2
}//��ʱ ����ָ�� ������ڴ治���ͷż��� new�����Ķ���������������ᱻ����

//��Ա�������� ��������ָ��ʱ ������
// ������ ������ enable_shared_from_this<�Լ�>
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

		//α����������ָ��
		//parend_2Ptr p(this);
		//�������� enable_shared_from_this<>ʱ
		handleChildAndPraentRef(shared_from_this(), ps);//��ʱ�����
	}//����һ��parent �������� parent
}
//weaked_prt ����shared_ptr��ѭ������ 
//��shared_ptr����Դ�������ڹ����ʱ��weak_ptr����ʧЧ
void sharedPtrWithWealPtr() {

	ParentPtr obj(new Parent_1);//��ʱshared_ptr������һ����Դ
	typedef weak_ptr<Parent_1> WeakParendPtr;
	WeakParendPtr weakObj(obj);//��ʱ weakPtrָ��obj
	cout << "obj use count is" << obj.use_count() << "\n"; //��ʱ�����obj��use_count()Ϊ1
	{
		auto p = weakObj.lock();
		if (p) {
			//��pΪ��Ч��ָ��ʱ objռһ�ݣ�pռһ��
			cout << "obj use count is" << obj.use_count() << "\n"; //2
		}
		else {

		}
	}
	obj.reset();//��ʱ��obj���ڹ��� weakobjҲ��ʧЧ
	obj.reset(new Parent_1);//��ʱ ͬ��ʧЧ
	weakObj = obj;//���¸�ֵ�� ������Ч
	//�ж�wealptr�Ƿ���Ч
	if (weakObj.expired()) {
		cout << "��Ч" << endl;
	}
	else {
		cout << "��Ч" << endl;
	}
}

//unique_ptr
//�÷�
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
	print(obj);//ĳһʱ�� ��uniqueptr�������Դֻ����һ����ʹ��
	p = obj.release();//�ͷ� uniqueptr
	delete p;

	obj.reset();//delete�����ָ��
	obj.reset(new Child_2);//�ͷ�ԭ���ָ�� �������½���ָ��
	//
	transfer(move(obj));
	cout << obj->id() << "\n";//��ʱobj����Ч��

	// ��uniqueptr ת�Ƶ� shared_ptr
	obj.reset(new Child_2);
	child_2Ptr sharedPtr(move(obj));
	assert(obj == nullptr);
}
void print(const UniqueChild_2Ptr& obj) {}
void transfer(UniqueChild_2Ptr obj){
	cout << obj->id() << endl;
}

#pragma endregion


#pragma region ����ָ��Ŀ�

void sharedPtrNotice() {

	//ǰ�᣺���Բ�Ҫ�Լ��ֶ��Ĺ�����Դ
	int* a = new int(10);
	delete a;
	int* b = (int*)malloc(sizeof(int));
	if (b) {
		free(b);
	}

	//һ�����ָ�벻Ҫ������shaded_ptr����unique_ptr
	auto pObj = new Child_2();
	child_2Ptr obj(pObj);
	child_2Ptr obj2(pObj);

	//�� weak_ptr����ѭ�����ã�parrent ��child
	//����Ҫ������ڲ��ӿ��У������Ҫ��this��Ϊ����ָ����ʹ�õĻ���
	//��Ҫ�ø���������enable_shared_form_this

	//ʹ��shared_ptr��Ϊ�����Ľӿڣ�����п��� ��const shared_ptr&����ʽ
	//���߳�ģʽ��ʹ��shared_prt��Ҫע�������(���̱߳�̵�ʱ��)

	//shared_ptr weak_ptr ����ָ����ȣ� ���ܶ࣬����Ч���ϻ���Ӱ�졣�������ڶ��߳�ģʽ��
	child_2Ptr obj3(new Child_2);//������������ι��캯��
	child_2Ptr obj4 = obj3;

	//Ӧ��ʹ�����ַ�ʽ��������ָ��
	child_2Ptr obj5 = make_shared<Child_2>();

	//enable_shared_form_this shared_from_this()�͹�����������һ����ĳЩ������ǲ���ʹ�õģ�
	// �����ڹ��������������ǲ���ʹ�õ�

	//ĳЩ����£�������ڴ治�ή�����⣬������ʹ��weak_ptr������ѭ�����õ�����(weak_ptr ����)

	//����п��ܣ�����ʹ�����ʵ��������򲻵���ʹ��unique_ptr,
	//�򲻵���ʹ��shared_ptr;
}

#pragma endregion

#pragma region Lambda
//��һ��inline���� ��Ϊ���� local����

//��Ϊ����
template<class Func>
void printUseFunc(Func func, int a, int c, int b) {
	func(a, b, c);
}
void LambdaTest() {

	auto local = [](int a, int b, int c) {
		cout << "a =" << a << "b =" << b << "c = " << c << "\n";
	};
	auto local1 = []{cout << "hello Lambda\n";  };
	//��Ϊ����
	printUseFunc([](int a, int b, int c) {
		cout << "a =" << a << "b =" << b << "c = " << c << "\n";
		}, 1, 2, 3);

	int a = 10;
	int b = 20;
	int c = 30;
	auto local2 = [=]() {};
	//��Ҫ���òſ�ִ�д˺���
	local2();//��ʱ�����κβ��������Կ�������ʽ ����һ����ʹ��
	auto local3 = [&]() {};
	local3();//��ʱ�����κβ��������Դ��ε���ʽ����
	auto local4 = [a, b, c]() {};
	local4();//��ʱ�ǿ�������ʽ
	auto local5 = [&a, &b, &c]() {};
	local5();//��ʱ�����ô���

}
#pragma endregion

int main() {

	Good g;
	system("pause");
	return 0;
}