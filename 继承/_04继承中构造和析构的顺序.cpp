#include <iostream>
using namespace std;
#include <string>
//�̳��й����������˳��
// ����̳и���� ������������� Ҳ����ø���Ĺ��캯��

// �ȹ��츸�� �ٹ�������
// �����빹���෴

class Base {
public:
	Base() {
		cout << "Base �Ĺ��죡" << endl;
	}
	~Base() {
		cout << "Base ��������" << endl;
	}
};

class Sum :public Base {
public:
	Sum() {
		cout << "Sum �Ĺ��죡" << endl;
	}
	~Sum() {
		cout << "Sum ��������" << endl;
	}
};

void test4_1() {
	Sum s;
}

int main() {
	test4_1();

	system("pause");
	return 0;
}