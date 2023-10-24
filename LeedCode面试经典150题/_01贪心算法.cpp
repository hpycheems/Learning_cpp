#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


/*
* 贪心算法：贪心算法或贪心思想采用贪心的策略，保证每次操作都是局部最优的，
* 从而使最后得到的结果是全局最优的。
*/
#pragma region 贪心算法
///分配问题
/*
* Assign Cookies:
* 有一群孩子和一堆饼干，每个孩子有一个饥饿度，每个饼干都有一个大小。每个孩子只能吃
* 一个饼干，且只有饼干的大小不小于孩子的饥饿度时，这个孩子才能吃饱。求解最多有多少孩子
* 可以吃饱。
*/
int findContentChildren(std::vector<int>& children, std::vector<int>& cookies) {
	/*因为饥饿度最小的孩子最容易吃饱，所以我们先考虑这个孩子。为了尽量使得剩下的饼干可
	 *以满足饥饿度更大的孩子，所以我们应该把大于等于这个孩子饥饿度的、且大小最小的饼干给这
	 *个孩子。满足了这个孩子之后，我们采取同样的策略，考虑剩下孩子里饥饿度最小的孩子，直到
	 *没有满足条件的饼干存在。
	*/
	std::sort(children.begin(), children.end());
	std::sort(cookies.begin(), cookies.end());
	int child = 0, cookie = 0;
	while (child < children.size() && cookie < cookies.size()) {
		if (children[child] <= cookies[cookie]) {
			++child;
		}
		++cookie;
	}
	return child;
}

/*
* Candy:
* 一群孩子站成一排，每一个孩子有自己的评分。现在需要给这些孩子发糖果，规则是如果一
* 个孩子的评分比自己身旁的一个孩子要高，那么这个孩子就必须得到比身旁孩子更多的糖果；所
* 有孩子至少要有一个糖果。求解最少需要多少个糖果。
*
* 把所有孩子的糖果数初始化为 1；
* 先从左往右遍历一遍，如果右边孩子的评分比左边的高，则右边孩子的糖果数更新为左边孩子的
* 糖果数加 1；再从右往左遍历一遍，如果左边孩子的评分比右边的高，且左边孩子当前的糖果数
* 不大于右边孩子的糖果数，则左边孩子的糖果数更新为右边孩子的糖果数加 1。通过这两次遍历，
* 分配的糖果就可以满足题目要求了。
*/
int candy(std::vector<int>& ratings) {
	int size = ratings.size();
	if (size < 2) {
		return size;
	}
	std::vector<int> num(size, 1);
	for (int i = 1; i < size; ++i)
	{
		if (ratings[i] > ratings[i - 1]) {
			num[i] = num[i - 1] + 1;
		}
	}
	for (int i = size - 1; i >= 0; --i)
	{
		if (ratings[i] < ratings[i - 1]) {
			num[i - 1] = std::max(num[i] + 1, num[i - 1]);
		}
	}
	return std::accumulate(num.begin(), num.end(), 0);
}

//区间问题
/*
* 给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。起止相连不算重叠。
* 输入是一个数组，数组由多个长度固定为 2 的数组组成，表示区间的开始和结尾。输出一个
* 整数，表示需要移除的区间数量。
*
*
* 具体实现方法为，先把区间按照结尾的大小进行增序排序，每次选择结尾最小且和前一个选
* 择的区间不重叠的区间。
*/
class Pare {
public:
	bool operator()(std::vector<int>& a, std::vector<int>& b) {
		return a[1] < b[1];
	}
};
int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
	if (intervals.empty())return 0;
	int n = intervals.size();
	std::sort(intervals.begin(), intervals.end(), Pare());
	int total = 0, prev = intervals[0][1];
	for (int i = 1; i < n; ++i)
	{
		if (intervals[i][0] < prev) {
			++total;
		}
		else {
			prev = intervals[i][1];
		}
	}
	return total;
}
//种花问题
bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
	return false;
}

//用最少数量的箭引爆气球
int findMinArrowShots(std::vector<std::vector<int>>& points) {
	int n = points.size();
	if(n < 2) {
		return 1;
	}
	std::sort(points.begin(), points.end(), [](std::vector<int>& a, std::vector<int>& b) {
		return a[1] < b[1];
		});
	int total = 1, pevr = points[0][1];
	for (int i = 1; i < n; ++i) {
		if (points[i][0] > pevr) {
			++total;
			pevr = points[i][1];
		}
	}
	return total;
}

//划分字母区间
/*
* 在得到每个字母最后一次出现的下标位置之后，可以使用贪心的方法将字符串划分为尽可能多的片段
* 
*/
std::vector<int> partitionLabels(std::string s) {
	int list[26];
	int n = s.size();
	for (int i = 0; i < n; ++i)//计算每个字母最后出现的下标
	{
		list[s[i] - 'a'] = i;
	}
	std::vector<int> partition;
	int start = 0, end = 0;
	for (int i = 0; i < n; ++i)
	{
		end = std::max(end, list[s[i] - 'a']);
		if (i == end) {
			partition.push_back(end - start + 1);
			start = end + 1;
		}
	}
	return partition;
}
//买卖股票的最佳时机 II 由于交易次数不受限制，可以使用贪心算法
int maxProfit(std::vector<int>& prices) {
	int len = prices.size();
	if (len < 2) {
		return 0;
	}
	int ans = 0;
	for (int i = 1; i < len; ++i)
	{
		ans += std::max(0, prices[i] - prices[i - 1]);
	}

	return ans;
}

#pragma endregion

int main2() {

	std::vector<std::vector<int>> v{ {1,2 },{3, 4 }, {5, 6},{7, 8} };
	std::cout << findMinArrowShots(v) << std::endl;

	system("pause");
	return 0;
}