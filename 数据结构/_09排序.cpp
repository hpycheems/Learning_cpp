#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <assert.h>

void printVector(const vector<int>& v) {

	for (auto val : v) {
		cout << val << " ";
	}
	cout << "\n";
}

/*
*	排序的基本概念：
*	假设有n个记录的序列为{r1,r2,...,rn},其相应的关键字分别为{k1,k2,...,kn},需确定1,2,...,n的一种排列p1,p2,...,pn
*	使其相应的关键字满足kp1 <= kp2 <= ... <= kpn 关系，即使序列成为一个按关键字有序的序列{rp1,rp2,...,rpn},这样的操作就称为排序。
* 
*	排序的稳定性：排序后，相等的元素它们之间的顺序没有发生改变，则是稳定的，反之是不稳定的
* 
*	内排序与外排序：
*	内排序是在排序整个过程中，待排序的所有记录全部被放置在内存中。
*	外排序是由于排序的记录个数太多，不能同时放置在内存，整个排序过程需要在内外存之间多次交换数据才能进行。
* 
*	排序分别为： 插入排序
				交换排序
				选择排序
				归并排序
*/

#pragma region 冒泡排序 O(n^2)
/*
*	冒泡排序一种交换排序，它的基本思想是：两两比较相邻记录的关键字，如果反序则交换，直到没有反序记录为止。
*/

//简单排序实现
void BubbleSort0(vector<int>& nums) {
	int lenght = nums.size() - 1;
	for (size_t i = 0; i < lenght; i++)
	{
		for (size_t j = 1; j <= lenght; j++)
		{
			if (nums[j] < nums[j-1]) {
				swap(nums[j], nums[j-1]);
			}
		}
	}
}
//冒泡排序
void BubbleSort1(vector<int>& nums) {
	int length = nums.size();
	for (int i = 0; i < length; i++)
	{
		for (int j = length - 1; j > 0; j--)
		{
			if (nums[j] < nums[j - 1]) {
				swap(nums[j], nums[j - 1]);
			}
		}
	}
}
//改进冒泡
void BubbleSort2(vector<int>& nums) {
	bool haveChange = false;
	int length = nums.size();
	for (int i = 0; i < length; i++)
	{
		haveChange = false;
		for (int j = length - 1; j > 0; j)
		{
			if (nums[j] < nums[j - 1]) {
				haveChange = true;
				swap(nums[j], nums[j - 1]);
			}
		}
		if (!haveChange) {
			break;
		}
	}
}
#pragma endregion

#pragma region 简单选择排序 O(n^2)但要优于冒泡
/*
*	简单选择排序就是通过n-i次关键字间的比较，从n-i+1个记录中选出关键字最小的记录，并和第i个记录交换。
*/

void SelectSort(vector<int>& nums) {
	if (nums.size() < 1) {
		return;
	}
	int min = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		min = i;
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[min] > nums[j]) {
				min = j;
			}
		}
		if (min != i) {
			swap(nums[min], nums[i]);
		}
	}
}
#pragma endregion

#pragma region 直接插入排序
/*
*	直接插入排序的基本操作是将一个记录插入到已经排好序的有序表中，从而得到一个新的、记录数增1的有序表
*/
void InserSlot(vector<int>& nums) {
	int temp, j;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] < nums[i - 1]) {
			temp = nums[i];
			//sb排序 j >= 0
			for (j = i - 1; j >= 0 && temp < nums[j]; j--)
			{
				nums[j + 1] = nums[j];
			}
			nums[j + 1] = temp;
		}
	}
}
#pragma endregion

#pragma region 希尔排序
/*
*	将原本有大量记录数的记录进行分组。分割成若干个子序列，此时每个子序列待排序的记录个数就比较少了，
*	然后在这些子序列内分别进行直接插入排序，当整个序列基本有序时，再对全体记录进行一次直接插入排序。
*	基本有序，就是小的关键字基本在前面，大的基本在后面，不大不小的在中间。
* 
*	跳跃分割策略：将相距某个“增量”的记录组成一个子序列，这样才能保证在子序列内分别进行直接插入排序后得到的结果是基本有序而不是局部有序
*/
void ShellSort(vector<int>& nums) {
	int temp = 0;
	int i, j;
	int increment = nums.size();
	do {
		increment = increment / 3 + 1;
		for (i = increment + 1; i < nums.size(); i++)
		{
			if (nums[i] < nums[i - increment]) {
				temp = nums[i];
				//这一段为插入排序
				for (j = i - increment; j > 0 && temp < nums[j]; j -= increment)
				{
					nums[j + increment] = nums[j];
				}
				nums[j + increment] = temp;
			}
		}
	} while (increment > 1);
}
#pragma endregion

#pragma region 推排序
/*
*	堆是具有下列性质的完全二叉树：每个结点的值都大于或等于其左右孩子结点的值，称为大顶堆
*	每个结点的值都小于或等于其左孩子结点的值，称为小顶堆。
* 
*	基本思想：将待排序的序列构造成一个大顶堆。此时，整个序列的最大值就是堆顶的根结点。
*	将它移走（将其与堆数组的末尾元素交换，此时末尾元素就是最大值），然后将剩余的n-1个序列
*	重复构造成一个堆，这样就会得到n个元素中次小值。如此反复执行，便能得到一个有序序列了。
*/

void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void HeapAdjust(vector<int>& nums, int s, int m) {

	int temp = nums[s];

	for (int j = s * 2; j <= m; j = j * 2)
	{
		if (j < m&& nums[j] < nums[j + 1]) {
			j++;
		}
		if (temp >= nums[j]) {
			break;
		}
		nums[s] = nums[j];
		s = j;
	}
	nums[s] = temp;
}
void HeapSort(vector<int>& nums) {
	for (int i = (nums.size() - 1) / 2; i > 0; i--)
	{
		HeapAdjust(nums, i, nums.size() - 1);
	}

	for (int i = nums.size() - 1; i > 1; i--)
	{
		Swap(nums[1], nums[i]);
		HeapAdjust(nums, 1, i - 1);
	}
}
#pragma endregion

#pragma region 归并排序
/*
*  归并排序就是利用归并的思想实现的排序方法。
*	假设初始序列含有n个记录，则可以看成是n个有序的子序列，每个子序列的长度是1，然后两两合并，得到[n/2]个长度为2或1的有序序列；
*	两两归并，...,如此重复，直到得到一个长度为n的有序序列为止，这种方法叫做二路归并排序
*/
void MSort(std::vector<int> SL, std::vector<int> TL1, int s, int t);
void Merge(std::vector<int> SL, std::vector<int> TL, int i, int m, int n);
void MargeSort(std::vector<int> L) {
	MSort(L, L, 0, L.size() - 1);
}
void MSort(std::vector<int> SL, std::vector<int> TL1, int s, int t) {
	int m;

	std::vector<int> TL2(20);

	if (s == t)
		TL1[s] = SL[s];

	else {
		m = (s + t) / 2;//将SL[s...t]分割为SL[s...m]和SL[m+1 ... t]
		MSort(SL, TL2, s, m);//递归将SL[s...m]归并为有序的TL2[s...m]
		MSort(SL, TL2, m + 1, t);//递归将SL[m+1...t]归并为有序的TL2[m+1...t]
		Merge(TL2, TL1, s, m, t);//将TL2[s..m]和TL2[m+1...t]归并到TL1[s..t]
	}
}

void Merge(std::vector<int> SL, std::vector<int> TL, int i, int m, int n) {
	int j, k, l;
	for (j = m + 1, k = i; i <= m && j <= n; ++k) {
		if (SL[i] < SL[j]) {
			TL[k] = SL[i++];
		}
		else {
			TL[k] = SL[j++];
		}
	}

	if (i <= m) {
		for (l = 0; l <= m - 1; ++l) {
			TL[k + 1] = SL[i + l];
		}
	}

	if (j <= n) {
		for (l = 0; l <= n - j; ++l) {
			TL[k + 1] = SL[j + 1];
		}
	}
}
#pragma endregion


#pragma region 快速排序
/*
*	快速排序的基本思想是：通过一趟排序将待排记录分割成独立的两部分，
*	其中一部分记录的关键字均比另一部分记录的关键字小，则可分别对这两部分记录继续进行排序，以达到整个序列有序的目的
*/
void QSort(std::vector<int>& L, int low, int high);
int Partition(std::vector<int>& L, int low, int high);
void QuickSort(std::vector<int> L) {
	QSort(L, 0, L.size() - 1);

	//for (auto num : L) {
	//	std::cout << num << "\n";
	//}
}
void QSort(std::vector<int>& L, int low, int high) {
	int pivot;
	if (low < high) {
		pivot = Partition(L, low, high);//先取当中的一个关键字，然后想尽办法将它放到一个位置，使得左边的值都小于它，右边的值都大于它，这个关键字称为枢轴

		QSort(L, low, pivot - 1); //对低子表递归
		QSort(L, pivot + 1, high);//对高子表递归
	}
}
int Partition(std::vector<int>& L, int low, int high) {
	int pivotkey;
	pivotkey = L[low]; //用子表的第一个元素作枢轴记录
	while (low < high) {//从表的两端交替向中间扫描
		while (low < high && L[high] >= pivotkey)
			high--;

		//将比枢轴记录小的记录交换到低端
		int temp = L[low];
		L[low] = L[high];
		L[high] = temp;
		while (low < high && L[low] <= pivotkey)
			low++;

		//将比枢轴记录大的记录交换到高端
		temp = L[low];
		L[low] = L[high];
		L[high] = temp;
	}
	return low;
}
//快速排序的优化：
// 1.优化选取枢轴：（1）随机选取枢轴。 （2）三位数取中法{左端，中间，右端}
// 2.优化不必要的交换：将pivotkey备份，然后在之前是swap时，只是替换工作，最终low与high会合，在将备份的数组赋值回L[low]
// 3.优化小数组时的排序方案：当数据量较小时，直接使用直接插入排序即可
// 4.优化递归操作:在循环中（low < hight） 中实现尾递归（QSort(L, low, pivot - 1)） low = pivot + 1;
		
#pragma endregion



int main9() {

	vector<int> v = { 0, 50, 10, 90,30,70, 40,80 ,60, 20 };
	//v.push_back(0);
	//v.push_back(9);
	//v.push_back(1);
	//v.push_back(5);
	//v.push_back(8);
	//v.push_back(3);
	//v.push_back(7);
	//v.push_back(4);
	//v.push_back(6);
	//v.push_back(2);


	//BubbleSort2(v);
	//printVector(v);
	//SelectSort(v);
	//InserSlot(v);
	//HeapSort(v);

	//printVector(v);

	vector<int> v1 = { 50, 10, 90, 30, 70, 40, 80, 60, 20 };
	MargeSort(v1);


	system("pause");
	return 0;
}