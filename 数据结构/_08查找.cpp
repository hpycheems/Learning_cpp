#include <iostream>
#include <vector>
/*
*	查找概论：
*		查找表是由同一类型的数据元素构成的集合。
*		关键字是数据元素中某个数据项的的值，又称为键值。
*		若此关键字可以唯一地标识一个记录，则称此关键字为主关键字。
*		可以识别多个数据元素的关键字，称为次关键字。
*	查找：
*		根据给定的某个值，在查找表中确定一个其关键字等于给定值的数据元素。
*	静态查找表：只作查找操作的查找表。
*	动态查找表：在查找过程中同时插入查找表中不存在的数据元素，或者从查找表中
*		删除已经存在的某个数据元素。
* 
*	顺序表查找：
*		又叫线性查找，是最基本的查找技术，它的查找过程是：从表中第一个记录开始，
*		逐个进行记录的关键字和给定值比较，若某个记录的关键字和给定值相等，则查找成功，
*		找到所查找的记录；如果直到最后一个记录，其关键字和给定值比较都不等时，
*		则表中没有所查找的记录，查找不成功。
* 
*	有序表查找：
*		折半查找：又称二分查找。它的前提是线性表中的记录必须是关键码有序，线性表
*		必须采用顺序存储。折半查找的基本思想是：在有序表中，取中间记录为比较对象，
*		若给定值与中间记录的关键字相等，则查找成功；若给定值小于中间记录的关键字，
*		则在中间记录的左半区继续查找；若给定值大于中间记录的关键字，则在中间记录
*		的右半区继续查找。不断重复，直到查找成功，或所查找区域无记录，查找失败为止。
*		
*		差值查找：根据要查找的关键字key与查找表中最大最小记录的关键字比较后的查找方法，
*		其核心就在于差值的计算公式：mind = low + (high - low) * (key - a[low]) / (a[high] - a[low])
*		
*		斐波那契查找：利用黄金分割率原理实现
*	
*	线性索引查找：
*		
* 
*	二叉排序树：
* 
*	平衡二叉树：
* 
*	多路查找树（B树）：
*	
*	散列表查找（哈希表）：
* 
*/

//顺序表查找算法
int Sequntial_Search(std::vector<int> v, int num) {
	int i;
	for (i = 0; i <= v.size(); ++i) {
		if (v[i] == num)
			return i;
	}
	return 0;
}
//优化
int Sequntial_Search2(std::vector<int> v, int num) {
	int i;
	i = v.size();
	while(v[i] != num) {
		--i;
	}
	return i;
}

//折半查找
int Binary_Seach(std::vector<int> v, int key) {
	int low, high, mid;
	low = 0;
	high = v.size() - 1;
	while (low < high)
	{
		mid = (low + high) / 2;
		if (key < v[mid])
			high = mid - 1;
		else if (key > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return 0;
}
//差值查找
int Diffrernce_Seach(std::vector<int> v, int key) {
	int low, high, mid;
	low = 0;
	high = v.size() - 1;
	while (low < high) {
		mid = low + (high - low) * (key - v[low]) / (v[high] - v[low]);
		if (key < v[mid])
			high = mid - 1;
		else if (key > v[mid])
			low = mid + 1;
		else
			return mid;
	}
}

int main() {
	
	return 0;
}