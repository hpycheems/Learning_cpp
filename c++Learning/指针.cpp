#include <iostream>
using namespace std;

void swap01(int* a, int* b);

void bubbleSort(int* arr, int lenght);
void printArr(int* arr, int length);

//ͨ��ָ���������ַ
int main16() {
	int a;
	//1 ����ָ��
	int* p;
	// ��¼��ַ
	p = &a;
	cout << "a�ĵ�ַΪ��" << &a << endl;
 	cout <<"ָ��pΪ��" << p << endl;

	//2 ʹ��ָ�� *p
	*p = 1000;
	cout << "a = " << a << endl;
	cout << "*p = " << *p << endl;

//ָ����ռ�õ��ڴ�ռ� 32(x86)λռ4���ֽ� 64(x64)ռ8���ֽ�
	int* x;
	x = &a;

	int* y = &a;
	cout << "sizeof int * " << sizeof(int*) << endl;
	cout << "sizeof int * " << sizeof(float*) << endl;
	cout << "sizeof int * " << sizeof(char*) << endl;

//��ָ�� ָ���ڴ���Ϊ0�Ŀռ�
	// ��ʼ��ָ�� ���ɷ��� 0~255 �ڴ���ϵͳռ�� 
	int* p1 = NULL;
	//cout << *p1 << endl;

//Ұָ��
	//ָ��ָ��Ƿ����ڴ�ռ� ��������
	int* p2 = (int*)0x1111;
	cout << *p << endl;

//const ����ָ��
	//const����ָ�� -- ����ָ��
	//�ص� ָ���ָ������޸ģ�ָ��ָ���ֵ�����޸�
	int b = 20;
	const int* p3 = &a;
	//*p3 = 30;
	p3 = &b;

	//ָ�볣�� ָ���ָ�򲻿��Ըģ�ָ��ָ���ֵ�����޸�
	int* const p4 = &a;
	*p4 = 20;
	//*p4 = &b;

	//������ָ�룬�����γ��� ָ���ָ�򲻿��Ըģ�ָ��ָ���ֵ�������޸�
	const int* const p5 = &a;
	//*p5 = 20;
	//p5 = &b;

//ָ������� ����ָ����������е�ÿ��Ԫ��
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "�����еĵ�һ��Ԫ�أ�"<< arr[0] << endl;

	int* p_1 = arr;
	cout << "����ָ�������ʵ�һ��Ԫ�أ�" << *p_1 << endl;

	*p_1++;
	cout << "����ָ����ʵڶ���Ԫ�أ�"<< *p_1 <<endl;
 
	cout << "����" << endl;
	int* p_2 = arr;
	for (int i = 0; i < 10; i++)
	{
		//cout << arr[i] << endl;
		cout << *p_2 << endl;
		p_2++;
	}

//ָ��ͺ���
	int number1 = 20;
	int number2 = 10;
	//1 ֵ����
	//swap01(&number1, &number2);
	cout << number1 << endl;
	cout << number2 << endl;

	//2 ��ַ����
	swap01(&number1, &number2);
	cout << number1 << endl;
	cout << number2 << endl;


// ����
	int arr2[] = { 3,6,1,7,4,8,2,5,9,0 };

	int lenght = sizeof(arr2) / sizeof(arr2[0]);
	bubbleSort(arr2, lenght);
	printArr(arr2, lenght);


	system("pause");
	return 0;
}

void swap01(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int* arr, int lenght) {
	bool hasChange = true;
	for (int i = 0; i < lenght; i++)
	{
		hasChange = false;
		for (int  j = lenght - 2; j > -1; j--)
		{
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				hasChange = true;
			}
		}
		if (!hasChange) {
			break;
		}
	}
}

void printArr(int* arr,int length) {

	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << endl;
	}
}