#include <iostream>
using namespace std;
#include<string>
//��Ԫ
// ȫ�ֺ�������Ԫ
// ������Ԫ
// ��Ա��������Ԫ

class Building;

class GoodGay {
public:
	GoodGay();
	//void visit();

	void visit_1();
	void visit_2();
private:
	Building* building;
};

class Building {
	// ���߱����� goodGayȫ�ֺ�����Building��ĺ����ѣ����Է�������˽������
	friend void goodGay(Building& building);

	// ���߱������� GoodGay����Building��ĺ����ѣ����Է��ʵ�Building���˽������
	//friend class GoodGay;

	//���߱����� goodGay���е�visit_1��Ա������Building�ĺ����ѣ� ���Է���˽������
	friend 	void GoodGay::visit_1();

public :
	Building() {
		m_SittingRoom = "����";
		m_BedRoom = "����";
	}

	string m_SittingRoom;//����
private :
	string m_BedRoom;//����
};


GoodGay::GoodGay() {
	building = new Building;
}
//void GoodGay::visit() {
//	cout << "���ڷ��� ��" << building->m_SittingRoom<< endl;
//
//	cout << "���ڷ��� ��" << building->m_BedRoom<< endl;
//}

void GoodGay::visit_1() {
	cout << "���ڷ��� ��" << building->m_SittingRoom << endl;

	cout << "���ڷ��� ��" << building->m_BedRoom << endl;
}
void GoodGay::visit_2() {
	cout << "���ڷ��� ��" << building->m_SittingRoom << endl;
}


void goodGay(Building &building) {
	cout << "���ڷ��� ��" << building.m_SittingRoom << endl;

	cout << "���ڷ��� ��" << building.m_BedRoom << endl;
}

void test5_1() {
	Building b;
	goodGay(b);
}

void test5_2() {
	GoodGay g;
	//g.visit();
}

void test5_3() {
	GoodGay g;
	g.visit_1();
	g.visit_2();
}

int main5() {

	//test5_1();

	test5_3();

	system("pause");
	return 0;
}