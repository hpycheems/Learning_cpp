#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>


void printVector(const vector<int>& v) {

	for (auto val : v) {
		cout << val << " ";
	}
	cout << "\n";
}

#pragma region √∞≈›≈≈–Ú O(n^2)
//ºÚµ•≈≈–Ú µœ÷
void BubbleSort0(vector<int>& nums) {
	int lenght = nums.size() - 1;
	for (size_t i = 0; i < lenght; i++)
	{
		for (size_t j = i + 1; j <= lenght; j++)
		{
			if (nums[i] > nums[j]) {
				swap(nums[i], nums[j]);
			}
		}
	}
}
//√∞≈›≈≈–Ú
void BubbleSort1(vector<int>& nums) {
	int length = nums.size();
	for (int i = 0; i < length; i++)
	{
		for (int j = length - 1; j > 0 ; j--)
		{
			if (nums[j] < nums[j - 1]) {
				swap(nums[j], nums[j - 1]);
			}
		}
	}
}
//∏ƒΩ¯√∞≈›
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


#pragma region ºÚµ•—°‘Ò≈≈–Ú O(n^2)µ´“™”≈”⁄√∞≈›
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

#pragma region ÷±Ω”≤Â»Î≈≈–Ú
void InserSlot(vector<int>& nums) {
	int temp,j;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] < nums[i - 1]) {
			temp = nums[i];
			//sb≈≈–Ú j >= 0
			for (j = i - 1; j >= 0 && temp < nums[j]; j--)
			{
				nums[j + 1] = nums[j];
			}
			nums[j + 1] = temp;
		}
	}
}
#pragma endregion

#pragma region œ£∂˚≈≈–Ú
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
				//’‚“ª∂ŒŒ™≤Â»Î≈≈–Ú
				for (j = i - increment; j > 0 && temp < nums[j]; j-=increment)
				{
					nums[j + increment] = nums[j];
				}
				nums[j + increment] = temp;
			}
		}
	} while (increment > 1);
}
#pragma endregion

int main() {

	vector<int> v;
	v.push_back(0);
	v.push_back(9);
	v.push_back(1);
	v.push_back(5);
	v.push_back(8);
	v.push_back(3);
	v.push_back(7);
	v.push_back(4);
	v.push_back(6);
	v.push_back(2);

	//BubbleSort2(v);
	//printVector(v);
	//SelectSort(v);
	//InserSlot(v);
	ShellSort(v);
	
	printVector(v);
	system("pause");
	return 0;
}