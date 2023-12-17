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
*	����Ļ������
*	������n����¼������Ϊ{r1,r2,...,rn},����Ӧ�Ĺؼ��ֱַ�Ϊ{k1,k2,...,kn},��ȷ��1,2,...,n��һ������p1,p2,...,pn
*	ʹ����Ӧ�Ĺؼ�������kp1 <= kp2 <= ... <= kpn ��ϵ����ʹ���г�Ϊһ�����ؼ������������{rp1,rp2,...,rpn},�����Ĳ����ͳ�Ϊ����
* 
*	������ȶ��ԣ��������ȵ�Ԫ������֮���˳��û�з����ı䣬�����ȶ��ģ���֮�ǲ��ȶ���
* 
*	��������������
*	�����������������������У�����������м�¼ȫ�����������ڴ��С�
*	����������������ļ�¼����̫�࣬����ͬʱ�������ڴ棬�������������Ҫ�������֮���ν������ݲ��ܽ��С�
* 
*	����ֱ�Ϊ�� ��������
				��������
				ѡ������
				�鲢����
*/

#pragma region ð������ O(n^2)
/*
*	ð������һ�ֽ����������Ļ���˼���ǣ������Ƚ����ڼ�¼�Ĺؼ��֣���������򽻻���ֱ��û�з����¼Ϊֹ��
*/

//������ʵ��
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
//ð������
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
//�Ľ�ð��
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

#pragma region ��ѡ������ O(n^2)��Ҫ����ð��
/*
*	��ѡ���������ͨ��n-i�ιؼ��ּ�ıȽϣ���n-i+1����¼��ѡ���ؼ�����С�ļ�¼�����͵�i����¼������
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

#pragma region ֱ�Ӳ�������
/*
*	ֱ�Ӳ�������Ļ��������ǽ�һ����¼���뵽�Ѿ��ź����������У��Ӷ��õ�һ���µġ���¼����1�������
*/
void InserSlot(vector<int>& nums) {
	int temp, j;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] < nums[i - 1]) {
			temp = nums[i];
			//sb���� j >= 0
			for (j = i - 1; j >= 0 && temp < nums[j]; j--)
			{
				nums[j + 1] = nums[j];
			}
			nums[j + 1] = temp;
		}
	}
}
#pragma endregion

#pragma region ϣ������
/*
*	��ԭ���д�����¼���ļ�¼���з��顣�ָ�����ɸ������У���ʱÿ�������д�����ļ�¼�����ͱȽ����ˣ�
*	Ȼ������Щ�������ڷֱ����ֱ�Ӳ������򣬵��������л�������ʱ���ٶ�ȫ���¼����һ��ֱ�Ӳ�������
*	�������򣬾���С�Ĺؼ��ֻ�����ǰ�棬��Ļ����ں��棬����С�����м䡣
* 
*	��Ծ�ָ���ԣ������ĳ�����������ļ�¼���һ�������У��������ܱ�֤���������ڷֱ����ֱ�Ӳ��������õ��Ľ���ǻ�����������Ǿֲ�����
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
				//��һ��Ϊ��������
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

#pragma region ������
/*
*	���Ǿ����������ʵ���ȫ��������ÿ������ֵ�����ڻ���������Һ��ӽ���ֵ����Ϊ�󶥶�
*	ÿ������ֵ��С�ڻ���������ӽ���ֵ����ΪС���ѡ�
* 
*	����˼�룺������������й����һ���󶥶ѡ���ʱ���������е����ֵ���ǶѶ��ĸ���㡣
*	�������ߣ�������������ĩβԪ�ؽ�������ʱĩβԪ�ؾ������ֵ����Ȼ��ʣ���n-1������
*	�ظ������һ���ѣ������ͻ�õ�n��Ԫ���д�Сֵ����˷���ִ�У����ܵõ�һ�����������ˡ�
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

#pragma region �鲢����
/*
*  �鲢����������ù鲢��˼��ʵ�ֵ����򷽷���
*	�����ʼ���к���n����¼������Կ�����n������������У�ÿ�������еĳ�����1��Ȼ�������ϲ����õ�[n/2]������Ϊ2��1���������У�
*	�����鲢��...,����ظ���ֱ���õ�һ������Ϊn����������Ϊֹ�����ַ���������·�鲢����
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
		m = (s + t) / 2;//��SL[s...t]�ָ�ΪSL[s...m]��SL[m+1 ... t]
		MSort(SL, TL2, s, m);//�ݹ齫SL[s...m]�鲢Ϊ�����TL2[s...m]
		MSort(SL, TL2, m + 1, t);//�ݹ齫SL[m+1...t]�鲢Ϊ�����TL2[m+1...t]
		Merge(TL2, TL1, s, m, t);//��TL2[s..m]��TL2[m+1...t]�鲢��TL1[s..t]
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


#pragma region ��������
/*
*	��������Ļ���˼���ǣ�ͨ��һ�����򽫴��ż�¼�ָ�ɶ����������֣�
*	����һ���ּ�¼�Ĺؼ��־�����һ���ּ�¼�Ĺؼ���С����ɷֱ���������ּ�¼�������������Դﵽ�������������Ŀ��
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
		pivot = Partition(L, low, high);//��ȡ���е�һ���ؼ��֣�Ȼ���뾡�취�����ŵ�һ��λ�ã�ʹ����ߵ�ֵ��С�������ұߵ�ֵ��������������ؼ��ֳ�Ϊ����

		QSort(L, low, pivot - 1); //�Ե��ӱ�ݹ�
		QSort(L, pivot + 1, high);//�Ը��ӱ�ݹ�
	}
}
int Partition(std::vector<int>& L, int low, int high) {
	int pivotkey;
	pivotkey = L[low]; //���ӱ�ĵ�һ��Ԫ���������¼
	while (low < high) {//�ӱ�����˽������м�ɨ��
		while (low < high && L[high] >= pivotkey)
			high--;

		//���������¼С�ļ�¼�������Ͷ�
		int temp = L[low];
		L[low] = L[high];
		L[high] = temp;
		while (low < high && L[low] <= pivotkey)
			low++;

		//���������¼��ļ�¼�������߶�
		temp = L[low];
		L[low] = L[high];
		L[high] = temp;
	}
	return low;
}
//����������Ż���
// 1.�Ż�ѡȡ���᣺��1�����ѡȡ���ᡣ ��2����λ��ȡ�з�{��ˣ��м䣬�Ҷ�}
// 2.�Ż�����Ҫ�Ľ�������pivotkey���ݣ�Ȼ����֮ǰ��swapʱ��ֻ���滻����������low��high��ϣ��ڽ����ݵ����鸳ֵ��L[low]
// 3.�Ż�С����ʱ�����򷽰�������������Сʱ��ֱ��ʹ��ֱ�Ӳ������򼴿�
// 4.�Ż��ݹ����:��ѭ���У�low < hight�� ��ʵ��β�ݹ飨QSort(L, low, pivot - 1)�� low = pivot + 1;
		
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