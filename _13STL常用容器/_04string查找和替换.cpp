#include <iostream>
using namespace std;
#include <string>

//string ���Һ��滻
/* �ҵ�����λ�� �Ҳ�������-1
* //����str��һ�γ���λ�ã���pos��ʼ����
int find(const string& str,int pos = 0) const;
int find(const char* s,int pos = 0)const;
//��posλ�ò���s��ǰn���ַ���һ��λ��
int find(const char* s,int pos = 0, int n)const;
�����ַ�c��һ�γ��ֵ�λ��
int find(cosnt char ,int pos = 0) const;

//����������� ���غ�findһ��
int rfind(const string& str,int pos = 0)

string& replace(int pos, int n ,const string& str);//�滻��pos��ʼn���ַ�Ϊ�ַ���str
string& replace(int pos, int n, const char* c);
*/

void test4_1() {
	string s1("abcdefgde");

	//find �������Ҳ���
	int pos = s1.find("de");
	if (pos == -1) {
		cout << "δ�ܲ��ҵ�" << endl;
	}
	else {
		cout << "pos = " << pos << endl;
	}
	//rfind �����������
	int pos1 = s1.rfind("de");
	cout <<"rPos = "<< pos1 << endl;
}

void test4_2() {
	string s1("abcdefg");
	s1.replace(1, 3, "111111");
	cout << s1 << endl;
}

int main4() {
	test4_1();
	test4_2();
	system("pause");
	return 0;
}