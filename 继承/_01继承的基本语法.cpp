#include <iostream>
using namespace std;
#include <string>
//�̳������������������֮һ
// �̳еĺô��������ظ�����
// �﷨�� class ���ࣺ�̳з�ʽ ����
// class A��public B
// A�ࣨ���ࡢ�����ࣩ B�ࣨ���ࡢ���ࣩ

class BasePage {
public:
	void header() {
		cout << "��ҳ�������Ρ���¼��ע�ᡣ������" << endl;
	}
	void footer() {
		cout << "�������ġ�����" << endl;
	}

	void left() {
		cout << "Java��Php" << endl;
	}
};

class Java :public BasePage {

public:
	void content() {
		cout << "Javaѧϰ��Ƶ��" << endl;
	}

};
class CPP :public BasePage {

public:
	void content() {
		cout << "C++ѧϰ��Ƶ��" << endl;
	}

};
class PHP :public BasePage {

public:
	void content() {
		cout << "Phpѧϰ��Ƶ��" << endl;
	}

};

void test1_1() {
	cout << "===================JAVA===================" << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();

	cout << "===================C++===================" << endl;
	CPP cpp;
	cpp.header();
	cpp.footer();
	cpp.left();
	cpp.content();

	cout << "===================PHP===================" << endl;
	PHP php;
	php.header();
	php.footer();
	php.left();
	php.content();

}


int main1() {

	test1_1();


	system("pause");
	return 0;
}