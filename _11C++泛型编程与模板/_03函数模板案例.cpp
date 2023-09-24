#include <iostream>
using namespace std;

template<class T>
void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

//template<class T>
//void arraySort(T arr[], int len) {
//	int max = 0;
//	for (int i = 0; i < len; i++)
//	{
//		max = i;
//		for (int j = i; j < len; j++)
//		{
//			if (arr[max] < arr[j]) {
//				max = j;
//			}
//		}
//		if (max != i) {
//			Swap(arr[max], arr[i])
//		}
//	}
//}

template<class T>
void sortArray(T& arr, int len) {
	int max = 0;
	for (int i = 0; i < len; i++)
	{
		max = i;
		for (int j = i; j < len; j++)
		{
			if (arr[max] < arr[j]) {
				max = j;
			}
		}
		if (max != i) {
			Swap(arr[max], arr[i]);
		}
	}
}

template<class T>
void printArray(T& arr, int len) {
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test3_1() {
	char charArray[] = "deacfb";
	int len = sizeof(charArray) / sizeof(char);
	sortArray(charArray, len);
	printArray(charArray, len);
}

void test3_2() {
	int intArray[] = {3,2,5,7,1,8,4,9,6};
	int len = sizeof(intArray) / sizeof(int);
	sortArray(intArray, len);
	printArray(intArray, len);
}

int main3() {


	//test3_1();
	test3_2();
	system("pause");
	return 0;
}