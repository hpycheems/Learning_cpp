#include <iostream>
using namespace std;

int main12() {
//һά����
// 	   ����һ���������ڴ�ռ� ÿ��Ԫ�ض�����ͬ����������
	
	//���巽ʽ
	// 1
	int array1[5];
	array1[0] = 1;
	array1[1] = 1;
	array1[2] = 1;
	array1[3] = 1;
	array1[4] = 1;
	for (int i = 0; i < 5; i++) {
		cout << array1[i] << endl;
	}

	// 2
	int array2[5] = { 10,20,30,40,50};
	for (int i = 0; i < 5; i++) {
		cout << array2[i] << endl;
	}
	// 3
	int array3[] = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 9; i++) {
		cout << array3[i] << endl;
	}
	// �������Ƶ���;
	// 1.ͨ���������� ͳ�������������ڴ��еĳ��� sizeof(arr)
	// 2.ͨ���������� ��ȡ�������ڴ��е��׵�ַ
	// �������ǳ���
	cout << sizeof(array3) << endl;

	cout << sizeof(array3) / sizeof(array3[0]) << endl;

	cout << (int)array3 << endl;
	cout << (int)&array3[0] << endl;
	cout << (int)&array3[1] << endl;
	
	//����
	int array[] = { 500,300,400,100,350 };
	int max = 0;
	for (int i = 0; i < 5; i++) {
		if (max < array[i]) {
			max = array[i];
		}
	}
	cout << "MAX = " << max << endl;
	//Ԫ������
	int arr[] = { 1,3,2,5,4};
	//for (int i = 0, j = 4;; i++, j--) {
	//	
	//	if (i == j || i == j -1) {
	//		break;
	//	}
	//}
	int start = 0;
	int end = sizeof(arr) / sizeof(arr[0]) - 1;
	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
	for (size_t i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}


//ð������
	//1.�Ƚ����ڵ�����Ԫ�أ������һ���ȵڶ����󣬾ͽ�������
	//2.��ÿһ�����ڵ�Ԫ����ͬ���Ĺ�����ִ����ϣ��ҵ���һ�����ֵ
	//3.�ظ����ϲ��裬ÿ�αȽϴ���-1��֪������Ҫ�Ƚ�
	cout << "ð������" << endl;
	int array4[] = { 3,1,2,7,5,4,8,9,6,0 };
	int length = sizeof(array4) / sizeof(array4[0]);
	bool hasChange = false;

	for (int i = 0; i < length; i++) {
		for (int j = length - 2; j > -1 ; j--) {

			if (array4[j] > array4[j + 1]) {
				int temp = array4[j];
				array4[j] = array4[j + 1];
				array4[j + 1] = temp;
				hasChange = true;
			}
		}
		if (!hasChange) {
			break;
		}
	}
	for (size_t i = 0; i < length; i++)
	{
		cout << array4[i] << endl;
	}

// ��ά���� 
	cout << "��ά���飺" << endl;
	//����
	int arr2_1[2][3]; //= { {1,2,3},{4,5,6} };
	arr2_1[0][0] = 1;
	arr2_1[0][1] = 2;
	arr2_1[0][2] = 3;
	arr2_1[1][0] = 4;
	arr2_1[1][1] = 5;
	arr2_1[1][2] = 6;
	//cout << arr2_1[0][0] << endl;
	//cout << arr2_1[1][0] << endl;

	int arr2_2[2][3] = { {1,2,3},{4,5,6} };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++)
		{
			//cout << arr2_2[i][j] << endl;
		}
	}

	int arr2_3[2][3] = { 1,2,3,4,5,6 };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++)
		{
			//cout << arr2_3[i][j] << endl;
		}
	}

	int arr2_4[][3] = { 1,2,3,4,5,6 };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++)
		{
			cout << arr2_4[i][j] << endl;
		}
	}
// ��ά������������
	// �鿴��ά������ռ�ڴ�ռ�
	// �鿴��ά������׵�ַ
	cout << "��ά����ռ�õ��ڴ�ռ䣺" << sizeof(arr2_4) << endl;
	cout << "��ά�����һ��ռ�õ��ڴ�ռ䣺" << sizeof(arr2_4[0]) << endl;
	cout << "��ά�����һ��Ԫ��ռ�õ��ڴ�ռ䣺" << sizeof(arr2_4[0][0]) << endl;

	int arr_length = sizeof(arr2_4) / sizeof(arr2_4[0]) * sizeof(arr2_4[0]) / sizeof(arr2_4[0][0]);
	cout << "����" << arr_length << endl;
	cout << (int)arr2_4 << endl;
	cout << (int)arr2_4[0] << endl;
	cout << (int) & arr2_4[0][0] << endl;
	cout << (int)arr2_4[1] << endl;

	// ����
	int score[][3] = { 100,100,100,90,50,100,60,70,80 };
	string str[] = { "����","����","����" };
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum = 0;
		for (int j = 0; j < 3; j++)
		{
			sum += score[i][j];
		}
		cout << str[i] <<"���˵��ܳɼ���" << sum << endl;
	}


	system("pause");
	return 0;
}