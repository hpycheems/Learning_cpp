#include <iostream>
#include <string>
using namespace std;

//�������ʹ��ڵ�����
//������ʵ��ڴ�ռ�

int main07() {

//����
	// 1�������� ռ2�ֽ� 
	short num1 = 10;

	// 2.���� ռ4�ֽ�
	int num2 = 10;

	// 3. ������ ռ4�ֽ�
	long num3 = 10;

	// 4.�������� ռ8�ֽ�
	long long num4 = 10;

	cout << num1 << endl; 
	cout << num2 << endl; 
	cout << num3 << endl;
	cout << num4 << endl;

	//sizeof(��������/����)�ؼ���
	cout << "shortռ���ڴ�ռ䣺" << sizeof(short) << endl;
	cout << "intռ���ڴ�ռ䣺" << sizeof(num2) << endl;
	cout << "longռ���ڴ�ռ䣺" << sizeof(num3) << endl;
	cout << "long longռ���ڴ�ռ䣺" << sizeof(num4) << endl;
	// short < int <= long < long long 

//������ 
	//������ flot ռ4���ֽ� 7λ��Ч����
	//Ĭ������� ���С�� ֻ����ʵ6����Ч����
	float f1 = 3.1415626f;//����f����˫����
	cout << "f1 =" << f1 << endl;

	//˫���� double ռ8���ֽ�
	double d1 = 3.1415626;
	cout << "d1 =" << d1 << endl;
	cout << "flotռ�õ��ڴ�ռ䣺" << sizeof(float) << endl;

	cout << "doubleռ�õ��ڴ�ռ䣺" << sizeof(double) << endl;

	//��ѧ������
	float f2 = 3e2; //3 * 10^2
	cout << "f2 = " << f2 << endl;
	float f3 = 3e-2;
	cout << "f3 = " << f3 << endl;

//�ַ��� char
	//������ʾ�����ַ� ռ1���ֽ�
	cout << "char ռ���ڴ�ռ䣺" << sizeof(char) << endl;
	
	char ch = 'a';//��������ֻ�� ����һ���ַ�
	cout << ch << endl;

	//��������
	//char ch2 = "a" ʹ�õ�����
	//char ch2 = 'abcdef'; ֻ�ܴ���һ���ַ�

	//�ַ��ͱ�����ӦASCII���� �ײ��ŵ���ASCII��
	// �ַ��ͱ��������ǰ��ַ�����ŵ��ڴ��д洢�����ǽ���Ӧ��ASCII�������洢��Ԫ
	//a 97
	//A 65
	cout << (int)ch << endl;

//ת���ַ� ���ڱ�ʾһЩ������ʾ������ASCII�ַ�
	// \n ����
	printf("���� ת���ַ� \n");

	// \\ ����һ����б��
	cout << "\\" << endl;

	// \t ˮƽ�Ʊ� 8��λ�� �����������
	cout << "aa\t" << "ˮƽ�Ʊ�" << endl;
	cout << "aaaaa\t" << "ˮƽ�Ʊ�" << endl;
	cout << "aaa\t" << "ˮƽ�Ʊ�" << endl;

//�ַ�����
	//c��� char name[] = "�ַ���ֵ";
	char str1[] = "Hello World";
	cout << str1 << endl;

	// string name = "�ַ���ֵ"
	// ����ͷ�ļ� #include <string>
	string str2 = "Hello C++";
	cout << str2 << endl;

//������������ bool
	//bool����ֻ������ֵ ռ1���ֽ�
	// 1 ������ 0�����
	// true
	// false
	cout << "bool ռ�õ��ڴ�ռ䣺" << sizeof(bool) << endl;

	bool b1 = true;
	cout << b1 << endl;
	b1 = false;
	cout << b1 << endl;

//���ݵ�����
	//�ؼ��� cin

	// 1.����
	int a = 0;
	cout << "������ͱ���a��ֵ��" << endl;
	//cin >> a;
	cout << "���ͱ���a = " << a << endl;

	// 2. ������
	float f = 0.0f;
	cout << "����������f��ֵ��" << endl;
	//cin >> f;
	cout << "�������f = " << f << endl;

	// 3.�ַ���
	char c = 'a';
	cout << "����ַ�����c��ֵ��" << endl;
	//cin >> c;
	cout << "�ַ�����c = " << c << endl;

	//�ַ���
	string s = "";
	cout << "����ַ�������s��ֵ��" << endl;
	//cin >> s;
	cout << "�ַ�������s = " << s << endl;

	//��������
	bool b = "";
	cout << "����ֲ�������b��ֵ��" << endl;
	cin >> b;//����0Ϊ�� ������Ϊ��
	cout << "��������b = " << b << endl;

	system("pause");
	return 0;
}