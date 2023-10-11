#include <iostream>
#include <vector>
#include <initializer_list>

//新类型
void newType() {

	//C++11增新了
	long long l = 1.0;
	unsigned long long l1 = 1.0;
	char16_t c = 'a';
	char32_t c1 = 'b';
}

//统一的初始化
//如果类有将模板std::initializer_list作为参数的构造函数，则只有该构造函数可以使用列表初始化形式。
class Stump {
public:
	Stump(int r, double w) :roots(r), weight(w) {}
private:
	int roots;
	double weight;
};

double sum(std::initializer_list<double> l1);
void test_01() {
	int x = { 5 };
	double y = { 10.0 };
	short arr[] = {1,2,3};
	int* ar = new int [4] {1, 2, 3, 4};

	Stump s1(1, 1.0);
	Stump s2 = { 1,1.0 };
	Stump s3({ 1,1.0 });
	//1.缩窄
	//初始化列表语法可以防止缩窄，即禁止将数值赋给无法存储它的数据数值变量，
	//如果使用初始化列表语法，编译器将禁止进行这样的类型转换，即将值存储到比它“窄”的变量中
	//char c1 = { 1.57e27 };//编译器报错
	double c2 = { 456789123 };
	//允许转换为更宽的类型。只要值在较窄的值类型的取值范围内，将其转换为较窄的类型也是允许的
	char c1 = { 66 };//66是int类型
	double d2 = { 66 };

	//2、std::initializer_list
	//C++11提供了模板类 initializer_list，可将其用作构造函数的参数。
	std::vector<int> a1(10);
	std::vector<int> a2(10);
	std::vector<int> a3{ 4,5,6 };

	//头文件initializer_list提供了对模板类initializer_list的支持，这个类包含成员函数begin(),end(),可用于
	//熟悉列表的范围。除用于构造函数外，还可将initializer_list用作常规函数的参数。

	auto tot = sum({ 1,2,3,4 });
	std::cout << tot << "\n";
}
double sum(std::initializer_list<double> l1) {
	double tot = 0;
	for (auto i = l1.begin(); i != l1.end(); i++)
	{
		tot += *i;
	}
	return tot;
}

//声明
void test_02() {

	//1.auto关键字： C++11将auto用于实现自动类型推断。这要求进行显式初始化，让编译器能够将变量的类型设置为初始值的类型
	auto maton = 112; // int
	auto pt = &maton; // int *
	//double fm(double, int);
	//auto pf = fm; // double (*)(double,int)
	//std::cout << typeid(pf).name() << "\n";
	//auto关键字还可以简化模板声明
	std::vector<int> v;
	for(auto it = v.begin(); it != v.end(); ++it){}

	//2.decltype关键字： 将变量的类型声明为表达式指定的类型
	//decltype(x) y;//让y的类型与x相同
	double x;
	int n;
	decltype(x * n) q;// double
	decltype(&x) pd; // int *
	//decltype 指定的类型可以为引用和const
	int j = 3;
	int& k = j;
	const int& nl = j;
	decltype(nl) i1 = 1;// const int &
	decltype(j) i2 = 10;// int 
	decltype((j)) i3 = i2;// int &
	std::cout << i3 << "\n";
	decltype(k + 1) i4;//int
	
	//3.返回类型后置
	//C++11新增了一种函数声明语法：在函数名和参数列表后面指定返回类型
	double f1(double, int);
	auto f2(double, int) -> double;


	//4.模板别名：using =
	//对于冗长或复杂的标识符，能够创建别名将很方便，以前，C++为此提供了 typedef
	typedef std::vector<std::string>::iterator itType;
	//C++11提供了另一种创建别名的语法
	using Group = std::vector<int>;

	//5.nullptr
	//空指针是不会指向有效数据的指针。
	int* aaa = nullptr;
}
//2 decltype 定义模板时的用处
template<class T, class U>
void of(T t, U u) {
	decltype(t * u) tu;
}
//3 可以使用decltype来指定函数的返回类型
//template<typename T, typename U>
//auto eff(T t, U u) -> decltype(T * U) {}
// 
//4 差别在于 模板部分 具体话
template<class T>
using arr = std::vector<T, int>;

//智能指针
void test_03() {

	//C++11摒弃了 auto_ptr,并新增了三种智能指针： unique_ptr、shared_ptr 、weak_ptr
	//所有新增的智能指针都能与STL容器和移动语义协同工作。
}

//异常规范方面的修改
void func_04() noexcept {
	throw(1);
}
void test_04() {

	func_04();

	//C++提供了一种语法，可用于指出函数可能引发哪些异常
	//void f501(int) throw();
	// 关键字 noexcept :使函数不会抛出异常
	//void f875() noexcept;

}

int main() {

	test_04();

	system("pause");
	return 0;
}