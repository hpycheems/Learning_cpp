#include <iostream>
using namespace std;
//��ģ����̳�
template<class T>
class Base {
	T obj;
};
// ����Ҫ֪�������е�T���ͣ����ܼ̳и���
class Son1 :public Base<int> {

};

// ���������ָ��������T���ͣ� ����Ҳ��Ҫ����ģ��
template<class T>
class Son2 :public Base<T> {
public:
	Son2() {
		cout << "T ����������" << typeid(T).name() << endl;
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