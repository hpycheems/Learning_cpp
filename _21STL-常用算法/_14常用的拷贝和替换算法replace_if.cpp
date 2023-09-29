#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>


/*
replace_if: ����������������Ԫ�أ��滻��ָ��Ԫ��
ԭ�ͣ�
replace_if(iterator beg, iterator end, _pared, newValue);
_pred ν��
*/

class MyPrint {

public:
	void operator()(int val) {
		cout << val << " ";
	}
};

class Greate30 {
public:
	bool operator()(int val) {
		return val >= 30;
	}

};

void test14_1() {

	vector<int> v;
	v.push_back(20);
	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(60);
	v.push_back(50);

	cout << "�滻ǰ" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	//�滻���ڵ���30 ��Ԫ��
	replace_if(v.begin(), v.end(), Greate30(), 3000);
	cout << "�滻��" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}


int main14() {

	test14_1();

	system("pause");
	return 0;
}