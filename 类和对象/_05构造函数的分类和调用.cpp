#include <iostream>
using namespace std;
#include<string>
//1 ���캯���ķ��༰����
// ���� 
// ���ղ������� �в� �޲Σ�Ĭ�Ϲ��죩 
// �������ͷ��� ��ͨ���캯�� �������캯��

class Pen {
public:
	int m_Age;
	//���캯��
	Pen() {
		cout << "Pen ���޲ι��캯��" << endl;
	}
	Pen(int a) {
		m_Age = a;
		cout << "Pen ���вι��캯��" << endl;
	}
	// �������캯��
	Pen(const Pen& p) {
		m_Age = p.m_Age;
		cout << "Pen �Ŀ����캯��" << endl;
	}

	~Pen() {
		cout << "Pen ����������" << endl;
	}
};
//����
void test02() {
	//���ŷ� ע�⣺����Ĭ�Ϲ��첻��Ҫ�ӣ��� ����������Ϊ��һ������������������Ϊ�ڴ�������
	//Pen p1; //Ĭ�Ϲ��캯������
	//Pen p2(10);
	//Pen p3(p2);

	//��ʾ��
	Pen p4;
	Pen p5 = Pen(10);
	Pen p6 = Pen(p5);
	Pen(20);// �������� �ص㣺��ǰ��ִ�н�����ϵͳ������������������
	//��Ҫ���ÿ������캯����ʼ����������
	//Pen(p5);// ��������Ϊ Pen��p5�� === Pen p5;��������

	//��ʽת����
	//Pen p7 = 10; //Pen p7 = Pen(10);
	//Pen p8 = p5; //Pen p8 = Pen(p5);

}

int main5() {

	test02();

	system("pause");
	return 0;
}