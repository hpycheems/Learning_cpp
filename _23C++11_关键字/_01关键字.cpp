#include<iostream>
using namespace std;
#include <string>
#include <assert.h>
#include <map>

#pragma region alignas  alignof
//alignas�����ö���λ���� ��alignof(�ڴ����λ��) Ĭ�ϵĶ����ǳ�Ա��ռ�ڴ���������
struct  Foo
{
	int i;
	float f;
	char c;
};
struct Empty {};
// 0 1 2 4 8...
struct alignas(64) Empty64 {};
struct alignas(0) BB {};//������ûᱻ����
//�������ò���С��Ĭ��ֵ �ᱨ��
//struct alignas(1) Dobule { double d; };
void alignInfo() {

	cout << "- char :" << alignof(char) << endl // 1
		<< "- pointer :" << alignof(int*) << endl//4
		<< "- class FOO" << alignof(Foo) << endl//4
		<< "- empty class" << alignof(Empty) << endl// 1
		<< "- alignas(64) Empty" << alignof(Empty64) << endl;
}
#pragma endregion

#pragma region and 
void showAnd() {
	int a = 3;
	int b = 4;
	if ((a == 3) && (b == 4)) {

	}

	if ((a == 3) and (b == 4)) {

	}

	//and_eq (&=) & ��λ��
	b and_eq b;
	b &= a;
	b = b & a;
}
#pragma endregion

//asm ��Ƕ�������

#pragma region 
//aotu ���ݺ����ֵ���Ƶ�����Ӧ���ǵ�����
void showAuto() {
	int aa = 1 + 2;
	auto a = 1 + 2.0;
	cout << "type of a" << typeid(a).name() << endl;
}
#pragma endregion

#pragma region bitand bitor
void showBitAndOr() {
	int a = 3;
	int b = 4;
	auto c = a bitand b;//&
	auto d = a bitor b;// |

}
#pragma endregion

//bool һ����һ���ֽ�
//���鲻Ҫ��bool ����Ϊ�����Ĳ���
void testBool() {
	bool a = true;
	bool b = false;
	*(reinterpret_cast<char*>(&a)) = -1;
	cout << "a = " << a << endl;

	if (a) {
		cout << "a true" << endl;
	}
	else {
		cout << "a false" << endl;
	}

	if (a == true) {
		cout << "a true" << endl;
	}
	else if (a == false) {
		cout << "a false" << endl;
	}
	else {
		cout << "a whate" << endl;
	}
}

//break �˳�����ѭ��
//case switch��ʹ�õ�
//catch try catch �����쳣

//char 255 1���ֽ� (linux) == unsigned char , singed char == (window)
void showChar() {
	char a = -10;
	unsigned char b = -1;
	cout << (int)a << endl;
	cout << (int)b << endl;
}

//char16_t ���� ���պ��� ���ֵ��ַ�

//char32_t

//class ��

//compl �� ~ 

//concept (����TS)

//const ����  

//constexpr ֱ���ڱ����ڼ����� |���뵽���� ���루��-������
int fact(int n) {
	return n <= 1 ? 1 : (n * fact(n - 1));
}
constexpr int factorial(int n) {
	return n <= 1 ? 1 : (n * factorial(n - 1));
}
void showConstexpr() {
	//char group[fact(3)];//����
	char group[factorial(3)];//���ᱨ��
}

//const_cast ��constת�ɿɱ�� ��const���ֲ����Ե��ƻ�
void testConstCast() {
	const int j = 3;
	//const int*
	int* pj = const_cast<int*>(&j);
	*pj = 4;
}

//continue ��������ѭ��

//decltype ������ 
void testDeclType() {
	
	int a = 10;
	decltype(a) y;//��ȡ���� int
	auto& cc = y;
	decltype((a)) z = y; // int&
}
template<class T,class U>
auto add(T a, U b) -> decltype(a + b) {
	return a + b;
}
template<class T, class U>
auto add(T a, U b) {
	auto c = a + b;
	return c; //�������ص��ǲ���ͬ��
	return (c);
}

//defaulat switch case default

//delete �ͷ��ڴ�

//do do{}while()

//double

//dynamic_cast �Ѹ���ָ��ת��������ָ��
struct Base { virtual ~Base() {} };
struct Deriverd :Base {
	virtual void name() {}
};
void testDyn() {
	Base* b1 = new Base;
	//���ת�����ɹ� �򷵻ؿ�ָ��
	if (Deriverd* d = dynamic_cast<Deriverd*>(b1)) {
		cout << "�ɹ�ת�� 1" << endl;
	}
	Base* b2 = new Deriverd;
	if (Deriverd* d = dynamic_cast<Deriverd*>(b2)) {
		cout << "�ɹ�ת�� 2" << endl;
	}

	Base bb;
	Deriverd& cc = dynamic_cast<Deriverd&>(bb);//���ʧ�����׳��쳣
}

//else

//enum
//enum Color{red, green, blue};
//enum Hate {red,blue};//���������ռ������ ��ʱ�ᱨ�� red blue
//����c++11��enum class int��Ĭ��Ԫ�صĴ�С�����Ը��ģ�Ҳ����ʡ�ԣ�
enum class Color : int {red, green, blue};
void showEnum() {
	Color color = Color::red;
	switch (color)
	{
	case Color::red:
		break;
	case Color::green:
		break;
	case Color::blue:
		break;
	default:
		break;
	}
	//������������ת�� ���ε�����
	int a = static_cast<int>(color);
}

//explicit ��ֹ��ʽ����
struct A {
	A(int){}
	A(int, int) {}
	operator int()const { return 0; }
};
struct B
{
	explicit B(int) {}
	explicit B(int, int) {}
	explicit operator int()const { return 0; }
};
void testExpl() {
	A a1 = 1;//A a1 = A(1)
	//B b1 = 2;//����
	A a2(2);//Ĭ�Ϲ���
	B b2(2);
	A a3 = { 3,4 };//C++11�ӵĹ��� A a3 = A(4,5);
	//B b3 = { 1,2 };//����
	int na1 = a1;
	//int nb1 = b2;//����
	int na2 = static_cast<int>(a1);
	int nb2 = static_cast<int>(b2);//����ʹ��ǿ��ת���ſ�
}

//export ������ʹ��

//extern 

//false ture

//float 4���ֽ�

//for ѭ�� 11��������չ

//firend ��Ԫ �ǵ����

//goto 

//if

//inline ������Ӻ�����չ�����ÿռ任ʱ�䣩ֻ�ܶ�����ͷ�ļ���
inline int add(int a, int b) { return a + b; }
//���еĺ���Ĭ��Ҳ��inline ����ȥ��
//ģ�巽��Ҳһ��

//int 4���ֽ� signed

//long ��С����С��int 8�ֽ�

//mutable �ɱ�� �ڳ��������пɱ�

//namespace �����ռ�
namespace YGroup {
	class A1 {
		int value;
	};
}
namespace XGroup {
	class A1 {
		int value;
	};
	class B {

	};
}
class A1 {
	int value;
};
void testNamespace() {
	XGroup::A1 a;
	YGroup::A1 a1;
}

//new ���ض����ָ��

//noexcept ���׳��쳣
void f() noexcept {
	//����׳��쳣 ������
	terminate();//������
	abort();
	exit(0);
}

//not !

//not_eq !=

//nullprt ��ָ��
//��һ������ nullprt_t

//operator ����+ - = ����

//or ||

//or_eq |=

//privete 
//protected  //���Ա��Ȩ��
//public

//register�������ĳ������ ���뵽�Ĵ����У� ���� 

//reinterpret_cast ת��
void testReinter() {
	int a;
	//reinterpret_cast
	//static_cast
	//const_cast
	//dynamic_cast 
	//c like cast ����dynamic_cast ����������ʵ��
	auto pp = (char*)(&a);
}

//requires

//return ����

//short ���� ��intС

//signed �з���

//sizeof 

//static ����ļ��е�static��һ��
static int globalA = 0;//�����ڱ���ʱ�ͷ����ڴ���
void printInfo() {
	static int localStatic = 0;//ֻ�е�һ�ε���ʱ�Ż�ִ��
}

//static_assert ��assert�������ƣ���static_assert�ڱ����ڽ���
void testStaticAssert() {
	static_assert(sizeof(int) == 4, "��int������4ʱ��ӡ��仰");
	int a = 3;
	int b = 4;
	//��ʹ�� assertʱ ֻ��ʹ��assert ������static_assert
	assert(a == b, "");//�������ֻ��������ʱ��
	//static_assert(a==b,)//��ʱ�Ǳ����
}

//static_cast

//struct �ṹ��

//switch case defalut

//template ģ�� ģ�庯�� ģ����

//this ���� ���ö����ָ��

//thread_local ���߳�ʱʹ�õ�

// throw �׳��쳣

// true

// try catch

// typedef ��һ���������ֶ���ɶ̵�����
typedef unsigned long ulong;

//typeid 

//typename 

//union

//unsigned

//using

//virtual �麯�� ��̳�

//void 

//volatile �ñ�������Ҫ�Ż�

//wchar_t 

//while ѭ��
void showWhile() {
	int num = 0;
	while (true) {
		num++;
		if (num == 5)break;
	}
}

//xor ^ ��λ��� 0 1Ϊ1
void testXor() {
	int a = 2;// 0000 0000 0000 0010
			  // 0000 0000 0000 1010
	int b = a ^ 10;
	cout << b << endl;
}
//xor_eq ^=


int main() {
	//showAuto();
	//showChar();
	//testBool();
	//testDyn();
	testXor();
	system("pause");
	return 0;
}