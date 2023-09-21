#include <iostream>
using namespace std;

int main12() {
//一维数组
// 	   放在一块连续的内存空间 每个元素都是相同的数据类型
	
	//定义方式
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
	// 数组名称的用途
	// 1.通过数组名称 统计整个数组在内存中的长度 sizeof(arr)
	// 2.通过数组名称 获取数组在内存中的首地址
	// 数组名是常量
	cout << sizeof(array3) << endl;

	cout << sizeof(array3) / sizeof(array3[0]) << endl;

	cout << (int)array3 << endl;
	cout << (int)&array3[0] << endl;
	cout << (int)&array3[1] << endl;
	
	//案例
	int array[] = { 500,300,400,100,350 };
	int max = 0;
	for (int i = 0; i < 5; i++) {
		if (max < array[i]) {
			max = array[i];
		}
	}
	cout << "MAX = " << max << endl;
	//元素逆置
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


//冒泡排序
	//1.比较相邻的两个元素，如果第一个比第二个大，就交换它们
	//2.对每一对相邻的元素做同样的工作，执行完毕，找到第一个最大值
	//3.重复以上步骤，每次比较次数-1，知道不需要比较
	cout << "冒泡排序" << endl;
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

// 二维数组 
	cout << "二维数组：" << endl;
	//定义
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
// 二维数组名字作用
	// 查看二维数组所占内存空间
	// 查看二维数组的首地址
	cout << "二维数组占用的内存空间：" << sizeof(arr2_4) << endl;
	cout << "二维数组第一行占用的内存空间：" << sizeof(arr2_4[0]) << endl;
	cout << "二维数组第一个元素占用的内存空间：" << sizeof(arr2_4[0][0]) << endl;

	int arr_length = sizeof(arr2_4) / sizeof(arr2_4[0]) * sizeof(arr2_4[0]) / sizeof(arr2_4[0][0]);
	cout << "长度" << arr_length << endl;
	cout << (int)arr2_4 << endl;
	cout << (int)arr2_4[0] << endl;
	cout << (int) & arr2_4[0][0] << endl;
	cout << (int)arr2_4[1] << endl;

	// 案例
	int score[][3] = { 100,100,100,90,50,100,60,70,80 };
	string str[] = { "张三","李四","王五" };
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum = 0;
		for (int j = 0; j < 3; j++)
		{
			sum += score[i][j];
		}
		cout << str[i] <<"个人的总成绩：" << sum << endl;
	}


	system("pause");
	return 0;
}