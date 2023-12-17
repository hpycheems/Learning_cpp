#include <iostream>
using namespace std;
#include <map>
#include <algorithm>
#include <vector>
#include<algorithm>
#include <functional>
#include <string>

void printVector(const vector<int>& v) {
	for (auto val : v) {
		cout << val << " ";
	}
	cout << "\n";
}

#pragma region �ϲ�������������
class Solution1 {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		/*vector<int>::iterator pos = nums1.begin() + m;
		for (vector<int>::iterator it = nums2.begin(); it != nums2.end(); it++)
		{
			nums1.at(*pos) = *it;
			pos++;
		}
		sort(nums1.begin(), nums1.end());

		for (vector<int>::iterator it = nums1.begin(); it != nums1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;*/

		int i = nums1.size() - 1;
		m--;
		n--;
		while (n >= 0)////��nums2 ������Ϊ����
		{
			while (m >= 0 && nums1[m] > nums2[n]) {//nums1 ����nums1 ����λ��
				swap(nums1[i--], nums1[m--]);
			}
			swap(nums1[i--], nums2[n--]);
		}

		//merge(nums1, m - nums2.size(), nums2, nums2.size());
	}
};
void test_1() {
	vector<int> num1;
	vector<int> num2;
	num2.push_back(2);
	num2.push_back(5);
	num2.push_back(6);
	
	num1.push_back(1);
	num1.push_back(2);
	num1.push_back(3);

	int resizeNum = num1.size() + num2.size(); 
	num1.resize(resizeNum);
	Solution1 s;
	s.merge(num1, num1.size() - num2.size(), num2, num2.size());
}
#pragma endregion

#pragma region �Ƴ�Ԫ��
class Solution2 {
public:
	int removeElement(vector<int>& nums, int val) {
		//�Լ��ķ���
		/*int num = 0;
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
		{
			if (*it == val) {
				*it = 0;
				num++;
			}
		}
		sort(nums.begin(),nums.end(), greater<int>());
		return nums.size() - num;*/

		//����������
		//return remove(nums.begin(), nums.end(), val) - nums.begin();


		//�ٷ��ķ��� ˫ָ��
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			if (nums[left] == val) {
				nums[left] = nums[right--];
			}
			else {
				left++;
			}
		}
		return left;


		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
		

		
		//return nums.size();
	}
};
void test_2() {
	vector<int> num1;
	num1.push_back(3);
	num1.push_back(2);
	num1.push_back(2);
	num1.push_back(3);
	Solution2 s;
	cout << s.removeElement(num1, 3) << endl;
}
#pragma endregion

#pragma region ɾ�����������е��ظ���(ʹÿ��Ԫ�� ֻ����һ�� )
int removeDuplicates(vector<int>& nums) {
	//�ٷ� ˫ָ�� 
	int n = nums.size();
	if (n == 0) {
		return 0;
	}
	int fast = 1, slow = 1;
	while (fast < n) {
		if (nums[fast] != nums[fast - 1]) {
			nums[slow] = nums[fast];
			slow++;
		}
		fast++;
	}
	return slow;

	//����������
	int idx = 1;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] != nums[i - 1])
			nums[idx++] = nums[i];
	}
	return idx;
}
#pragma endregion

#pragma region ɾ�����������е��ظ���(ʹ�ó��ִ����������ε�Ԫ��ֻ�������� )
int removeDuplicatesl(vector<int>& nums) {
	/*int n = nums.size();
	if (n <= 0) {
		return 0;
	}
	bool isEque = false;
	int fast = 1, slow = 1;
	while (fast < n) {
		if (nums[fast] == nums[fast - 1]) {
			if(isEque == false){
				isEque = !isEque;
				fast++;
				slow++;
			}
			else {
				fast++;
			}
		}
		else {
			if (isEque == true) {
				fast++;
				slow++;
				isEque = false;
				continue;
			}
			nums[slow] = nums[fast];
			slow++;
		}
	}
	return slow - 1;*/
	
	//���������� 
	int len = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (len < 2 || nums[len - 2] != nums[i])
			nums[len++] = nums[i];
	}
	return len;
}
#pragma endregion

#pragma region ����Ԫ��

int majorityElement(vector<int>& nums) {
	if (nums.size() < 2) {
		return nums[0];
	}
	sort(nums.begin(), nums.end());
	int result = 0;
	int count = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] == nums[i - 1]) {
			count++;
		}
		if (count >= nums.size() / 2) {
			result = nums[i];
			count = 0;
		}
	}
	return result;

	//
	sort(nums.begin(), nums.end());
	return nums[nums.size() / 2];
}

#pragma endregion

#pragma region ��ת����
void rotate_(vector<int>& nums, int k) {
	//�Լ� Leedcode������rotate
	int pos = nums.size() - k % nums.size();
	if (pos == 0) {
		return;
	}
	rotate(nums.begin(), nums.begin() + pos, nums.end());

	// 
	//�ٷ�
	int n = nums.size();
	vector<int> newV(n);
	for (int i = 0; i < n; i++)
	{
		newV[(i + k) % n] = nums[i];
	}
	nums.assign(newV.begin(), newV.end());
}
#pragma endregion

#pragma region ���Ʊ�����ʱ��
int maxProfit(vector<int>& prices) {
	int length = prices.size();
	int result = 0;
	for (int i = length - 1; i >= 0; i--)
	{
		for (int j = i; j >= 0; j--)
		{
			if (result < prices[i] - prices[j]) {
				result = prices[i] - prices[j];
			}
		}
	}
	return result;

	//��¼����С��
	int inf = 1e9;
	int minprice = inf, maxprofit = 0;
	for (int price : prices) {
		maxprofit = max(maxprofit, price - minprice);
		minprice = min(price, minprice);
	}
	return maxprofit;
}
#pragma endregion

#pragma region ���Ʊ�����ʱ��II
int maxProfit_(vector<int>& prices) {
	//̰��
	int anx = 0;
	int n = prices.size();
	for (int i = 1; i < n; i++)
	{
		anx += max(0, prices[i] - prices[i - 1]);
	}
	return anx;
}
#pragma endregion



int main1() {
	//test_2();
	Solution1 p;
	vector<int> a = { 1,3,5,7 };
	vector<int> aa = { 2,4,6,8 };
	p.merge(a, 8, aa, 4);

	/*vector<int> v = { -1,-100,3,99 };
	rotate_(v, 6);
	printVector(v);

	vector<int> v1 = { 7,6,4,3,1 };
	cout <<  maxProfit(v1) << endl;*/
	//cout <<  << "\n";
	system("pause");
	return 0;
}