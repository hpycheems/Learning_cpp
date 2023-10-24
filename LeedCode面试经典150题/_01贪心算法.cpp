#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


/*
* ̰���㷨��̰���㷨��̰��˼�����̰�ĵĲ��ԣ���֤ÿ�β������Ǿֲ����ŵģ�
* �Ӷ�ʹ���õ��Ľ����ȫ�����ŵġ�
*/
#pragma region ̰���㷨
///��������
/*
* Assign Cookies:
* ��һȺ���Ӻ�һ�ѱ��ɣ�ÿ��������һ�������ȣ�ÿ�����ɶ���һ����С��ÿ������ֻ�ܳ�
* һ�����ɣ���ֻ�б��ɵĴ�С��С�ں��ӵļ�����ʱ��������Ӳ��ܳԱ����������ж��ٺ���
* ���ԳԱ���
*/
int findContentChildren(std::vector<int>& children, std::vector<int>& cookies) {
	/*��Ϊ��������С�ĺ��������׳Ա������������ȿ���������ӡ�Ϊ�˾���ʹ��ʣ�µı��ɿ�
	 *�����㼢���ȸ���ĺ��ӣ���������Ӧ�ðѴ��ڵ���������Ӽ����ȵġ��Ҵ�С��С�ı��ɸ���
	 *�����ӡ��������������֮�����ǲ�ȡͬ���Ĳ��ԣ�����ʣ�º����Ｂ������С�ĺ��ӣ�ֱ��
	 *û�����������ı��ɴ��ڡ�
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
* һȺ����վ��һ�ţ�ÿһ���������Լ������֡�������Ҫ����Щ���ӷ��ǹ������������һ
* �����ӵ����ֱ��Լ����Ե�һ������Ҫ�ߣ���ô������Ӿͱ���õ������Ժ��Ӹ�����ǹ�����
* �к�������Ҫ��һ���ǹ������������Ҫ���ٸ��ǹ���
*
* �����к��ӵ��ǹ�����ʼ��Ϊ 1��
* �ȴ������ұ���һ�飬����ұߺ��ӵ����ֱ���ߵĸߣ����ұߺ��ӵ��ǹ�������Ϊ��ߺ��ӵ�
* �ǹ����� 1���ٴ����������һ�飬�����ߺ��ӵ����ֱ��ұߵĸߣ�����ߺ��ӵ�ǰ���ǹ���
* �������ұߺ��ӵ��ǹ���������ߺ��ӵ��ǹ�������Ϊ�ұߺ��ӵ��ǹ����� 1��ͨ�������α�����
* ������ǹ��Ϳ���������ĿҪ���ˡ�
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

//��������
/*
* ����������䣬��������Щ���以���ص�����Ҫ�Ƴ���������ٸ�������ֹ���������ص���
* ������һ�����飬�����ɶ�����ȹ̶�Ϊ 2 ��������ɣ���ʾ����Ŀ�ʼ�ͽ�β�����һ��
* ��������ʾ��Ҫ�Ƴ�������������
*
*
* ����ʵ�ַ���Ϊ���Ȱ����䰴�ս�β�Ĵ�С������������ÿ��ѡ���β��С�Һ�ǰһ��ѡ
* ������䲻�ص������䡣
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
//�ֻ�����
bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
	return false;
}

//�����������ļ���������
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

//������ĸ����
/*
* �ڵõ�ÿ����ĸ���һ�γ��ֵ��±�λ��֮�󣬿���ʹ��̰�ĵķ������ַ�������Ϊ�����ܶ��Ƭ��
* 
*/
std::vector<int> partitionLabels(std::string s) {
	int list[26];
	int n = s.size();
	for (int i = 0; i < n; ++i)//����ÿ����ĸ�����ֵ��±�
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
//������Ʊ�����ʱ�� II ���ڽ��״����������ƣ�����ʹ��̰���㷨
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