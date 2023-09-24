#include <iostream>
using namespace std;
//类模板与继承
template<class T>
class Base {
	T obj;
};
// 必须要知道父类中的T类型，才能继承父类
class Son1 :public Base<int> {

};

// 如果想灵活的指定父类中T类型， 子类也需要变类模板
template<class T>
class Son2 :public Base<T> {
public:
	Son2() {
		cout << "T 的数据类型" << typeid(T).name() << endl;
	}
};

void test11_1(){
	Son2<int> s;
}

int main11() {

	test11_1();

	system("pause");
	return 0;
}