#include <iostream>
#include <vector>
#include <cassert>

/*
* 算法解释：
* 双指针主要用于遍历数组，两个指针指向不同的元素，从而协同完成任务。也可以延伸到多个数组的多个指针。
* 若两个指针指向同一数组，遍历方向相同且不会相交，则也称为滑动窗口（两个指针包围的区域即为当前的窗口），经常用于区间搜索
* 若两个指针指向同一数组，但是变量方向相反，则可以用来进行搜索，待搜素的数组往往是排序好的。
*/
//指针与常量
int x;
int* p1 = &x; // 指针可以被修改，值也可以被修改
const int* p2 = &x; // 指针可以被修改，值不可以被修改（const int）
int* const p3 = &x; // 指针不可以被修改（* const），值可以被修改
const int* const p4 = &x; // 指针不可以被修改，值也不可以被修改

//指针函数与函数指针
int* addition(int a, int b) { //指针函数 返回类型是一个指针的函数
	int* sum = new int(a + b);
	return sum;
}
int substraction(int a, int b) {
	return a - b;
}
//minus是函数指针 指向函数的指针
int (*minus)(int, int) = substraction;

//Tow Sum 
/*
* 在一个增序的整数数组里找到两个数，使它们的和为给定值。已知有且只有一对解。
* 
* 思路：因为数组有序，从头以及从尾便利，当两个数相加小于给定值时，left向右移动，反之right向左移动
*/
std::vector<int> towSum(std::vector<int>& numbers, int target) {
	int length = numbers.size();
	assert(length >= 2);
	int left = 0, right = length - 1;
	int sum = 0;
	while (left <= right) {
		sum = numbers[left] + numbers[right];
		if (sum == target) {
			break;
		}
		if (sum < target) ++left;
		else --right;
	}
	return { left + 1, right + 1 };
}

//归并两个数组
/*
* 给定两个有序数组，把两个数组合并为一个。
* 因为这两个数组已经排好序，我们可以把两个指针分别放在两个数组的末尾，即 nums1 的
* m − 1 位和 nums2 的 n − 1 位。每次将较大的那个数字复制到 nums1 的后边，然后向前移动一位。
* 因为我们也要定位 nums1 的末尾，所以我们还需要第三个指针，以便复制。
*/
void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
	int pos = m-- + n-- - 1;
	while (m >= 0 && n >= 0) {
		nums1[pos--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
	}
	while (n >= 0) {
		nums1[pos--] = nums2[n--];
	}
}

//快慢指针
/*
* 给定一个链表，如果有环路，找出环路的开始点。
* 对于链表找环路的问题，有一个通用的解法——快慢指针（Floyd 判圈法）。给定两个指针，
* 分别命名为 slow 和 fast，起始位置在链表的开头。每次 fast 前进两步，slow 前进一步。如果 fast
* 可以走到尽头，那么说明没有环路；如果 fast 可以无限走下去，那么说明一定有环路，且一定存
* 在一个时刻 slow 和 fast 相遇。当 slow 和 fast 第一次相遇时，我们将 fast 重新移动到链表开头，并
* 让 slow 和 fast 每次都前进一步。当 slow 和 fast 第二次相遇时，相遇的节点即为环路的开始点。
*/
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* detectCycle(ListNode* head) {
	ListNode* slow = head, * fast = head;
	do {
		if (!fast || !slow) return nullptr;
		slow = slow->next;
		fast = fast->next->next;
	} while (fast != slow);//当 slow与fast相遇，即说明存在环，
	fast = head;
	while (fast != slow) {
		slow = slow->next;
		fast = fast->next;
	}
	return fast;
}

//滑动窗口
/*
* 给定两个字符串 S 和 T，求 S 中包含 T 所有字符的最短连续子字符串的长度，同时要求时间
* 复杂度不得超过 O(n)。
*/


//平方数之和
/*
*	给定一个非负整数c,你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 
*/
bool judgeSquareSum(int c) {
	long left = 0, right = sqrt(c);
	while (left <= right)
	{
		if (left * left + right * right > c)
			--right;
		else if (left * left + right * right < c)
			++left;
		else return true;
	}
	return false;
}

//验证回文||
/*
* 一个字符串s，最多个删除一个字符
*/
bool isValid(std::string s, int i, int j);
bool validPalindrome(std::string s) {
	int left = 0, right = s.size() - 1;
	while (left <= right) {
		if (s[left] != s[right]) {
			return (isValid(s, left + 1, right) || isValid(s, left, right - 1));
		}
		++left;
		--right;
	}
	return true;
}
bool isValid(std::string s, int i, int j) {
	while (i < j)
	{
		if (s[i] != s[j]) {
			return false;
		}
		--j;
		++i;
	}
	return true;
}

int main3() {

	std::cout << judgeSquareSum(3) <<std::endl;
	return 0;
}