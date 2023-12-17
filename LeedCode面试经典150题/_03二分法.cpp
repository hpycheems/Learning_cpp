#include <iostream>
#include <vector>

/*
*	二分查找也常被称为二分法或者折半查找，每次查找时通过将待查找找区间分成两
*	部分并只取一部分继续查找，将查找的复杂度大大减少。对于一个长度为n的数组
*	，二分查找的时间复杂度为O(nlogn).
*/
//求开方
/*
*	给定一个非负整数，求它的开方，向下取整数
*/
//二分法
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

//牛顿迭代法：
//int mySqrt(int a) {
//	long x = a;
//	while (x * x > a) {
//		x = (x + a / x) / 2;
//	}
//}

//查找区间
/*
*	给定一个增序的整数数组和一个值，查找该值第一次和最后一次出现的位置。
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