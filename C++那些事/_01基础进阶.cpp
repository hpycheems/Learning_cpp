#include <iostream>

//��
#define exp(s) printf("test s is:%s\n", s);
#define exp1(s) printf("test s is:%s\n", #s);
#define exp2(s) #s

#define MAX 100
#pragma region const��Щ��
namespace Const {
	//1.const���壺��������ָʹ���������η�const˵�������ͣ������͵ı���������ֵ�ǲ��ܱ����µġ�
	//2.const���ã�
	//��1�����峣�� (���������޸ġ����������ʼ��)
	const int constNumber = 100;
	//��2�����ͼ�飺const�����������ͣ����������Խ��а�ȫ��飻
	// #define�궨��û���������ͣ�ֻ�Ǽ򵥵��ַ����滻�����ܽ��а�ȫ��顣
	
	// const����ı���ֻ������Ϊ������ö�٣����Գ������ʽ��ʼ��ʱ������Ϊ�������ʽ��
	// �����������ֻ��һ�� const �޶��ı�������Ҫ���볣��������
	//��3����ֹ�޸ģ��𵽱������ã���ǿ����׳��
	void constFunction(const int i) {
		//i++;//����
	}

	// (4)��ʡ�ռ䣬���ⲻ��Ҫ���ڴ����
	/*
	* const���峣���ӻ��ĽǶ�������ֻ�Ǹ����˶�Ӧ���ڴ��ַ����������#defineһ������������������
	* ���ԣ�const����ĳ����ڳ������й�����ֻ��һ�ݿ�������#define����ĳ������ڴ��������ɸ�������
	*/

	//3.const����Ĭ��Ϊ�ļ��ֲ�����
	/*��const����Ĭ��Ϊextern��
	* Ҫʹconst�����ܹ��������ļ��з��ʣ��������ļ�����ʽ��ָ����Ϊextern��
	
	//δ��const���εı����ڲ�ͬ�ļ��ķ���
	//file.cpp
	int ext;
	//file2.cpp
	extern int ext;
	int main() { std::cout << (ext + 10) << std::endl; }

	//const�����ڲ�ͬ�ļ��ķ���
	//file.cpp
	extern const int ext = 12;
	//file2.cpp
	extern const int ext;
	int main() {
		std::cout << ext << std::endl;
	}
	���Է���δ��const���εı�������Ҫextern��ʽ������
	��const������Ҫ��ʽ����extern��������Ҫ����ʼ������Ϊ�����ڶ����Ͳ��ܱ��޸ģ����Զ���ʱ�����ʼ����
	*/
	
	//4.ָ����const
	const char* a;//����ָ��
	char const* a;//ָ�볣��
	char* const a;
	const char* const a;
	/*
	* ���constλ��*����࣬��const������������ָ����ָ��ı�����
	* ��ָ��ָ��Ϊ���������constλ��*���Ҳ࣬const��������ָ�뱾����ָ�뱾���ǳ�����
	*/
	//(1)����ָ�루ָ������ָ�룩
	const int* ptr;
	//*ptr = 10;
	/*
	* ptr��һ��ָ��int����const�����ָ�룬const�������int���ͣ�
	* Ҳ����ptr��ָ��Ķ������ͣ�������ptr��������ptr���Բ��ø���ʼֵ��
	* ���ǲ���ͨ��ptrȥ�޸���ָ�����ֵ��
	* 
	* ����֮�⣬Ҳ����ʹ��void*ָ�뱣��const����ĵ�ַ��
	* ����ʹ��const void*���͵�ָ�뱣��const����ĵ�ַ��
	* 
	* ����ѷ�const����ĵ�ַ����ָ��const�����ָ�롣
	* 
	* ����ָ������ָ�룬����ͨ��ָ�����޸Ķ����ֵ��
	*/
	const int p = 10;
	const void* vp = &p;
	//void* vo = &p;

	const int* p;
	int b = 10;
	//p = &b;
	//���ǲ���ͨ��ptrָ�����޸�val��ֵ����ʹ��ָ����Ƿ�const����!

	//��2����ָ��
	int num = 0;
	int* const ptr = &num;


	//(5)������ʹ��const
	//const���κ�������ֵ
	const int func1();//������������壬��Ϊ�������ر�����Ǹ�ֵ�������ı�����
	const int* func2(); //ָ��ָ������ݲ��䡣
	int* const func3();//ָ�뱾���ɱ䡣


	//��6������ʹ��const
	/*
	* ��һ�����У��κβ����޸����ݳ�Ա�ĺ�����Ӧ������Ϊconst���͡�
	*/
}
#pragma endregion

#pragma region Static��Щ��
namespace Static {
	/*
	* ���벻ͬ����һ��ʹ��ʱ��Static�ؼ��־��в�ͬ�ĺ��塣
	* ��̬�����������еı��������еı���
	* ��̬��ĳ�Ա�����������еĺ���
	* 
	*/
	//�����еľ�̬����
	//����������Ϊstaticʱ���ռ佫�ڳ�������������ڷ��䡣
	//��ʹ��ε��øú�������̬�����Ŀռ�Ҳֻ����һ�Σ�ǰһ�ε����еı���ֵͨ����һ�κ������ô��ݡ�
	void demo() {
		static int count = 0;
		count++;
	}

	//���еľ�̬����
	//��������Ϊstatic�ı���ֻ����ʼ��һ�Σ���Ϊ�����ڵ����ľ�̬�洢�з����˿ռ䣬
	//������еľ�̬�����ɶ��������ڲ�ͬ�Ķ��󣬲�������ͬ��̬�����Ķ��������
	class Apple {
	public :
		static  int i;
	};
}
#pragma endregion

#pragma region This

#pragma endregion

#pragma region ���ú�ָ��
/*
* ���ã������ʼ��    ����Ϊ��   ���ܸ���Ŀ��
* ָ�룺���Բ���ʼ��  ����Ϊ��	   ���Ը���Ŀ��
*/
#pragma endregion


#pragma region ��
/*
* 1.���а���������ţ� # ,## ,\
* (1)�ַ�������������#��
*	#�ǡ��ַ�����������˼�������ں궨���е�#�ǰѸ��ں���Ĳ���ת����һ���ַ�����
* ע�⣺��ֻ�������д�������ĺ궨���У��ұ������ں궨�����еĲ�����ǰ
*/
void HongTest() {
	exp("hello");
	exp1("hello");
}

//(2)�������Ӳ�������##��

#pragma endregion


int main() {

	system("pause");
	return 0;
}