#include <iostream>
#include <vector>

/*
*	���ֲ���Ҳ������Ϊ���ַ������۰���ң�ÿ�β���ʱͨ����������������ֳ���
*	���ֲ�ֻȡһ���ּ������ң������ҵĸ��Ӷȴ����١�����һ������Ϊn������
*	�����ֲ��ҵ�ʱ�临�Ӷ�ΪO(nlogn).
*/
//�󿪷�
/*
*	����һ���Ǹ������������Ŀ���������ȡ����
*/
//���ַ�
int mySqrt(int a) {
	if (a == 0) return a;
	int l = 1, r = a, sqrt, mid;
	while (l <= r) {
		mid = l + (r - 1) / 2;
		sqrt = a / mid;
		if (sqrt == mid)
			return mid;
		else if (mid > sqrt)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return r;
}

//ţ�ٵ�������
//int mySqrt(int a) {
//	long x = a;
//	while (x * x > a) {
//		x = (x + a / x) / 2;
//	}
//}

//��������
/*
*	����һ����������������һ��ֵ�����Ҹ�ֵ��һ�κ����һ�γ��ֵ�λ�á�
*/
int lower_bound(std::vector<int>& nums, int target);
int upper_bound(std::vector<int>& nums, int target);
std::vector<int> searchRange(std::vector<int>& nums, int target) {
	if (nums.empty()) return std::vector<int>{-1, -1};
	int lower = lower_bound(nums, target);
	int upper = upper_bound(nums, target) - 1;
	if (lower == nums.size() || nums[lower] != target) {
		return std::vector<int>{-1, -1};
	}
	return std::vector<int>{lower, upper};
}
int lower_bound(std::vector<int>& nums, int target) {
	int l = 0, r = nums.size(), mid;
	while (l < r) {
		mid = l + (r - 1) / 2;
		if (nums[mid] > target)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return l;
}
int upper_bound(std::vector<int>& nums, int target) {
	int l = 0, r = nums.size(), mid;
	while (l < r) {
		mid = l + (r - 1) / 2;
		if (nums[mid] > target)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return l;
}

int main() {
	std::vector<int> v{ 5,7,7,8,8,10 };
	searchRange(v, 8);
	return 0;
}