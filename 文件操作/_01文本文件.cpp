#include <iostream>
using namespace std;
#include <fstream>
//��������ʱ���������ݶ�������ʱ���ݣ�����һ�����н������ᱻ�ͷ�
// ͨ���ļ����Խ����ݳ־û�
// C++�ж��ļ�������Ҫ����ͷ�ļ� <fstream>


// �ļ����ͷ�Ϊ���֣�
// �ı��ļ����ı����ı���ASCAII����ʽ�洢�ڼ������
// �������ļ����ļ����ı��Ķ�������ʽ�洢�ڼ�����

//�����ļ��������ࣺ
// ofstream д����
// ifstream ������
// fstream ��д����

//д�ļ�
// step1 :����ͷ�ļ� #include <fstream>
// step2 :�������ļ� ofstream ofs;
// step3 :���ļ� ofs.open("�ļ�·��",�򿪷�ʽ)
// step4 :д���� ofs << "д�������"
// step5 :�ر��ļ� ofs.close();

void test1_1() {

	//����ͷ�ļ�
	//����������
	ofstream ofs;
	//���ļ�
	ofs.open("test.txt", ios::out);
	//д����
	ofs << "����:����" << endl;
	ofs << "�Ա�:��" << endl;
	ofs << "����:20" << endl;
	//�ر��ļ�
	ofs.close();
}

int main1() {
	test1_1();
	system("pause");
	return 0;
}