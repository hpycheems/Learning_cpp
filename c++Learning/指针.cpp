#include <iostream>
using namespace std;

void swap01(int* a, int* b);

void bubbleSort(int* arr, int lenght);
void printArr(int* arr, int length);

//通过指针来保存地址
int main16() {
	int a;
	//1 定义指针
	int* p;
	// 记录地址
	p = &a;
	cout << "a的地址为：" << &a << endl;
 	cout <<"指针p为：" << p << endl;

	//2 使用指针 *p
	*p = 1000;
	cout << "a = " << a << endl;
	cout << "*p = " << *p << endl;

//指针所占用的内存空间 32(x86)位占4个字节 64(x64)占8个字节
	int* x;
	x = &a;

	int* y = &a;
	cout << "sizeof int * " << sizeof(int*) << endl;
	cout << "sizeof int * " << sizeof(float*) << endl;
	cout << "sizeof int * " << sizeof(char*) << endl;

//空指针 指向内存编号为0的空间
	// 初始化指针 不可访问 0~255 内存编号系统占用 
	int* p1 = NULL;
	//cout << *p1 << endl;

//野指针
	//指针指向非法的内存空间 尽量避免
	int* p2 = (int*)0x1111;
	cout << *p << endl;

//const 修饰指针
	//const修饰指针 -- 常量指针
	//特点 指针的指向可以修改，指针指向的值不能修改
	int b = 20;
	const int* p3 = &a;
	//*p3 = 30;
	p3 = &b;

	//指针常量 指针的指向不可以改，指针指向的值可以修改
	int* const p4 = &a;
	*p4 = 20;
	//*p4 = &b;

	//即修饰指针，又修饰常量 指针的指向不可以改，指针指向的值不可以修改
	const int* const p5 = &a;
	//*p5 = 20;
	//p5 = &b;

//指针和数组 利用指针访问数组中的每个元素
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "数组中的第一个元素："<< arr[0] << endl;

	int* p_1 = arr;
	cout << "利用指针来访问第一个元素：" << *p_1 << endl;

	*p_1++;
	cout << "利用指针访问第二个元素："<< *p_1 <<endl;
 
	cout << "遍历" << endl;
	int* p_2 = arr;
	for (int i = 0; i < 10; i++)
	{
		//cout << arr[i] << endl;
		cout << *p_2 << endl;
		p_2++;
	}

//指针和函数
	int number1 = 20;
	int number2 = 10;
	//1 值传递
	//swap01(&number1, &number2);
	cout << number1 << endl;
	cout << number2 << endl;

	//2 地址传递
	swap01(&number1, &number2);
	cout << number1 << endl;
	cout << number2 << endl;


// 案例
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