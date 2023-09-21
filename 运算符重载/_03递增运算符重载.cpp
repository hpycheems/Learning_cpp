#include<iostream>
using namespace std;
#include<string>
//�������������

class MyInteger {
	friend ostream& operator<<(ostream& cout, const MyInteger& m);
public:
	MyInteger() {
		m_Num = 0;
	}
	// ǰ�õ������������ ++m_Num
	// ��������Ϊ��һֱ��һ�����ݽ��е�������
	MyInteger& operator++() {
		//�ȵ���
		m_Num++;

		//�ٷ���
		return *this;
	}

	//���õ������������ m_Num++
	// C++�в�������ʱ�����ǲ����޸ĵģ���Ĭ��Ϊconst�ģ�
	// ��cosnt����ֻ�ܰ󶨵��������ͬ���͵Ķ���
	MyInteger operator++(int) {
		//�ȼ�¼
		MyInteger temp = *this;
		//�ٵ���
		m_Num++;
		//��󷵻ؼ�¼�ľֲ�����
		return temp;
	}
	//ǰ�õݼ�
	MyInteger& operator--() {
		m_Num--;
		return *this;
	}
	//���õݼ�
	MyInteger operator--(int) {
		MyInteger temp = *this;
		m_Num--;
		return temp;
	}

private:
	int m_Num;
};

ostream& operator<<(ostream& cout, const MyInteger& m) {
	cout << "m_Num = " << m.m_Num;
	return cout;
}


void test3_1() {

	MyInteger m;
	cout << ++(++m) << endl;
	cout << m << endl;
}

void test3_2() {
	MyInteger m;
	// operator<<(cout, MyInteger)
	cout << m++ << endl;
	cout << m << endl;

}

void test3_3() {
	MyInteger m;

	cout << --(--m) << endl;

	cout << m-- << endl;
	cout << m << endl;
}

// �ܽ᣺ǰ�õ����������� ���õ�������ֵ
int main3() {
	//test3_1();

	//test3_2();
	test3_3();

	system("pause");
	return 0;
}