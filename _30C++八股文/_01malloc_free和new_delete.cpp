#include <iostream>

/* 
	malloc\free �� new delete ������
		
	������malloc��free ��C�����п⺯����new��delete��C++�в�����
	a. new�Զ�������������ڴ��С��malloc��Ҫ�ֶ����㣨sizeof��
	b. new���ص��Ƕ������͵�ָ�룬malloc���ص��� void* ֮�������ת��
	c. new����ʧ�ܻ��׳��쳣�� malloc����ʧ�ܷ��ص��� NULL
	d. new����free store�������ڴ������Ϸ����ڴ�{��û������new������ʱ���ڶ��Ϸ���}��malloc�ڶ��Ϸ���
	e. delete��Ҫ�������͵�ָ�룬 free�� void* ���͵�ָ�룻

	new
	1. operator new
	2. �����㹻�Ŀռ�
	3. ���ù��캯������ʼ����Ա����
	delete
	1.�ȵ�����������
	2.operator delete
	3.�ͷſռ�

	malloc����ô�����ڴ�ģ�
	malloc������������ڴ滹�������ڴ棿
	malloc���ú��Ƿ������õ������ڴ棿
	free(p) ��ô֪�����ͷŶ��Ŀռ䣿
	free�ͷ��ڴ���ڴ滹����

	malloc����С��128k���ڴ棬���ỹ������ϵͳ��������malloc�ڲ���������
	malloc�����ڴ���ڵ���128k���ͷ��ڴ棬�����˲���ϵͳ��
*/
void test_1() {

	int* numA = (int*)malloc(sizeof(int));

	int* numB = new int(10);
}

int main() {
	


	system("pause");
	return 0;
}