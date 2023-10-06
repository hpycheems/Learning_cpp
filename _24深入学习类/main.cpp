#include<iostream>
using namespace std;
#include <fstream>
#include<vector>
#include<map>
#include <string>
#include "Good.h"

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

#pragma region ���캯���������ڹ��캯�����׳��쳣
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


#pragma region ��̬
//���麯�����ⲿ���Է��ʵ��ģ����Զ���Ϊvirtual
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
	//�а汾�����������ʽ
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



int main() {

	Good g;
	system("pause");
	return 0;
}