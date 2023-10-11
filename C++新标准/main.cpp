#include <iostream>
#include <vector>
#include <initializer_list>

//������
void newType() {

	//C++11������
	long long l = 1.0;
	unsigned long long l1 = 1.0;
	char16_t c = 'a';
	char32_t c1 = 'b';
}

//ͳһ�ĳ�ʼ��
//������н�ģ��std::initializer_list��Ϊ�����Ĺ��캯������ֻ�иù��캯������ʹ���б��ʼ����ʽ��
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
	//1.��խ
	//��ʼ���б��﷨���Է�ֹ��խ������ֹ����ֵ�����޷��洢����������ֵ������
	//���ʹ�ó�ʼ���б��﷨������������ֹ��������������ת��������ֵ�洢��������խ���ı�����
	//char c1 = { 1.57e27 };//����������
	double c2 = { 456789123 };
	//����ת��Ϊ��������͡�ֻҪֵ�ڽ�խ��ֵ���͵�ȡֵ��Χ�ڣ�����ת��Ϊ��խ������Ҳ�������
	char c1 = { 66 };//66��int����
	double d2 = { 66 };

	//2��std::initializer_list
	//C++11�ṩ��ģ���� initializer_list���ɽ����������캯���Ĳ�����
	std::vector<int> a1(10);
	std::vector<int> a2(10);
	std::vector<int> a3{ 4,5,6 };

	//ͷ�ļ�initializer_list�ṩ�˶�ģ����initializer_list��֧�֣�����������Ա����begin(),end(),������
	//��Ϥ�б�ķ�Χ�������ڹ��캯���⣬���ɽ�initializer_list�������溯���Ĳ�����

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

//����
void test_02() {

	//1.auto�ؼ��֣� C++11��auto����ʵ���Զ������ƶϡ���Ҫ�������ʽ��ʼ�����ñ������ܹ�����������������Ϊ��ʼֵ������
	auto maton = 112; // int
	auto pt = &maton; // int *
	//double fm(double, int);
	//auto pf = fm; // double (*)(double,int)
	//std::cout << typeid(pf).name() << "\n";
	//auto�ؼ��ֻ����Լ�ģ������
	std::vector<int> v;
	for(auto it = v.begin(); it != v.end(); ++it){}

	//2.decltype�ؼ��֣� ����������������Ϊ���ʽָ��������
	//decltype(x) y;//��y��������x��ͬ
	double x;
	int n;
	decltype(x * n) q;// double
	decltype(&x) pd; // int *
	//decltype ָ�������Ϳ���Ϊ���ú�const
	int j = 3;
	int& k = j;
	const int& nl = j;
	decltype(nl) i1 = 1;// const int &
	decltype(j) i2 = 10;// int 
	decltype((j)) i3 = i2;// int &
	std::cout << i3 << "\n";
	decltype(k + 1) i4;//int
	
	//3.�������ͺ���
	//C++11������һ�ֺ��������﷨���ں������Ͳ����б����ָ����������
	double f1(double, int);
	auto f2(double, int) -> double;


	//4.ģ�������using =
	//�����߳����ӵı�ʶ�����ܹ������������ܷ��㣬��ǰ��C++Ϊ���ṩ�� typedef
	typedef std::vector<std::string>::iterator itType;
	//C++11�ṩ����һ�ִ����������﷨
	using Group = std::vector<int>;

	//5.nullptr
	//��ָ���ǲ���ָ����Ч���ݵ�ָ�롣
	int* aaa = nullptr;
}
//2 decltype ����ģ��ʱ���ô�
template<class T, class U>
void of(T t, U u) {
	decltype(t * u) tu;
}
//3 ����ʹ��decltype��ָ�������ķ�������
//template<typename T, typename U>
//auto eff(T t, U u) -> decltype(T * U) {}
// 
//4 ������� ģ�岿�� ���廰
template<class T>
using arr = std::vector<T, int>;

//����ָ��
void test_03() {

	//C++11������ auto_ptr,����������������ָ�룺 unique_ptr��shared_ptr ��weak_ptr
	//��������������ָ�붼����STL�������ƶ�����Эͬ������
}

//�쳣�淶������޸�
void func_04() noexcept {
	throw(1);
}
void test_04() {

	func_04();

	//C++�ṩ��һ���﷨��������ָ����������������Щ�쳣
	//void f501(int) throw();
	// �ؼ��� noexcept :ʹ���������׳��쳣
	//void f875() noexcept;

}

int main() {

	test_04();

	system("pause");
	return 0;
}