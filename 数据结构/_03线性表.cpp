#include <iostream>
#define MAXSIZE 30

/*
*  线性表：零个或多个数据元素的有限序列
*	线性表元素个数n定义为线性表的长度，当n=0时，称为空表。
* 
*	线性表的顺序存储结构：
*		用一段连续的存储单元依次存储线性表的数据元素。
*	获取线性表的元素
*	插入
*	删除
* 
*	线性表的链式存储结构：
*	
*/

//顺序存储的结构代码
typedef int ElemType;
typedef struct {
	ElemType data[MAXSIZE];
	int length;
}SqList;



int main() {
	
}