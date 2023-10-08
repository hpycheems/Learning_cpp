#include <iostream>
using namespace std;
#include <array>
#include <vector>
#include <deque>
#include <cstring>


template<class T>
void containerAllInterface(T& a, T& b) {
	T c; //����
	T d(a); // copy 
	T e = a; // copy
	T f(move(e)); // ת�����e�в�����Ԫ��
	auto iterB = b.begin();
	auto iterE = b.end();
	T g(iterB, iterE);//copy
	b.size();// �����е�Ԫ�ظ��� forward_list���ṩ
	b.empty();// b.size() == 0
	b.max_size();//������װ�µ��������Ԫ��

	if (b == c) {
		//�ȱȽ�Ԫ�ظ���
		//�ڱȽ�Ԫ��
	}

	if (b != d) {}//����b == c��

	if (b < e) {}//unordered_set unordered_map �Ȳ��ɱȽ�

	e = b;// = ��ֵ����
	e = moev(b);
	e.swap(g);//array �����Եģ��������01
	swap(e, g);// 01 ����array

	e.cbegin(); // -> const_iterator
	e.cend();
	auto ea = e.cbegin();
	auto eaa = e.begin();
	// *ea -> const &
	// *eaa -> cosnt &(����һ��const ������ʱ��), &

	e.clear();//��� Ԫ�ض�������������� arrayû��
}

//array ����
void arrayPart() {
	/*
		array ʵ�����Ƕ�c/c++������ԭ��������еķ�װ
		namespace std{
			template<class T, size_t N>
			class array;
		}
		�ص㣺�ڴ������ջ��stack�������Բ������·��䣬�������Ԫ��
	*/
	int abc[100];
	array<int, 100> a;
	array<int, 100> b = {};//���г�ʼ��

	array<int, 5> obj = { 1,2,3,4,5 };
	array<int, 5> obj2 = { 1,0 };//���油0

	//interface
	a.empty();
	a.size();
	a.max_size();
	// operator == < != > <= >=
	auto aa = a;
	aa.swap(a);
	swap(aa, a);

	//����Ԫ��
	a[1];//�������±�
	a.at(1);//����±��Ƿ�Ϸ� ���Ϸ�ʱ�׳��쳣
	a.front();//��һ��Ԫ��
	a.back();//���һ��Ԫ��

	//���������
	a.begin();
	a.end();//ָ������������һ��Ԫ�ص���һ��Ԫ��
	a.cbegin();
	a.cend();
	a.rbegin();//��β��ʼ
	a.rend();//��ͷ

	//��c�Ľӿڻ���
	array<char, 100> carr;
	strcpy(&carr[0], "hello world!\n");//����ʹ�� carr.data()
	strcpy(carr.data(), "hello world!\n");

	//����
	carr.fill(0);//�������е�����Ԫ�� ��ֵΪ0

	//�쳣
	// c.at(pos);
	// copy move swap
}

void vectorPart() {
	/*
		vector ��c++98������Ķ�̬���飨dynamic array��
		namespace std{
			template<class T, typename Allocator = allocator<T> >
			class vector;
		}
		�ص��������Ԫ�أ�ĩ�����ɾ��Ԫ��Ч�ʸߡ�ǰ�˺��м�ɾ�������Ԫ��Ч�ʵ͡�
		���ڵ�ǰ������С�������Ĺ�ϵ
		�ڴ����
	*/
	using Group = vector<float>;

	Group a;//��������
	Group b = a;// ��������
	Group c(a);//��������
	Group d(10);//���ٴ�СΪ10 ������
	Group e(10, 1.0f);//���ٴ�СΪ10 ����Ԫ�ض�Ϊ1.0f
	Group f(e.begin(), e.end());
	Group g({ 1.0f, 2.0f, 3.0f });
	Group h = { 1.0f,2.0f, 3.0f };//c++11 initialize list

	d.empty();
	d.size();
	d.max_size();//���������container ����ֵ���ҪС ����array
	d.capacity();
	d.reserve(100);//Ԥ���ռ�
	d.shrink_to_fit();
	//operator == != < > <= >=

	//��ֵ
	b = g;
	b.assign(g.begin(), g.end());
	b.assign(3, 1.0f);//{ 1.0f, 2.0f, 3.0f }
	b.assign({ 1.0f, 2.0f, 3.0f });

	//����
	b.swap(a);
	swap(b, a);

	//Ԫ�ط���
	b[0];
	b.at(0);// exception out_of_range
	if (b.empty()) {
		b.front();//undefine ����ʱ��δ�����
		b.back();//undefine ����ʱ��δ�����
	}

	//���������
	a.begin();
	a.end();
	a.cbegin();
	a.cend();
	a.rbegin();
	a.rend();
	a.crbegin();
	a.crend();

	a.pop_back();// ���ܻ���� undefine
	//single thread 
	//multithread maybe wrong
	if (a.empty())a.pop_back();

	//ɾ��Ԫ��
	auto iterAfter = b.erase(b.begin());//����ɾ�����Ԫ�ص���һ��λ�ã�û����Ϊend
	iterAfter = b.erase(b.begin(), b.end());//��Ҫ���������Ƿ�ʧЧ

	b.push_back(10.0f);//β����
	b.pop_back();//βɾ
	auto iter = b.insert(b.begin(), 10);//�������Ԫ�صĵ�����
	iter = b.insert(b.end(), h.begin(), h.end());//����һ�����䣬���ظ��������һ��Ԫ�صĵ�����
	b.emplace(b.end(), 10.0f);//c++11 ����Ԫ��
	b.emplace_back(10.0f);// ��β�����в���

	b.resize(10);//���ԭ��������Ԫ�ض���10,������Ԫ�ض����ɵ���
	b.resize(100, 10);//���ɳ�����Ԫ�� ��ֵΪ 10
	b.resize(100000);
	b.clear();// ��������� ������capacity���ή��
	b.shrink_to_fit();//��������������Խ���capacity�� C++11

	//��c�Ľӿڻ���
	vector<char> carr(100, 0);
	strcpy(carr.data(), "hello world");
	printf("%s", carr.data());

	//�쳣
	// (1) push_back
	// (2) Ԫ��move/copyû���쳣�Ļ���insert emplace emplace_back push_backҲ�������쳣
	// (3) pop_back
	// (4) Ԫ��move/copy û���쳣�Ļ��� erase
	// (5) swap clear

	//���Բ�Ҫ�� vector��bool remenber
}


void dequePart() {
	/*
		deque ��c++98 ������Ķ�̬���飨dynamic array��
		namespace std{
			template<class T, typename Allocator = allocator<T>>
			class deque;
		}
		�ص��������Ԫ�أ�ĩ�˺�ͷ����Ӻ�ɾ��Ԫ��Ч�ʸߣ��м���Ӻ�ɾ��Ԫ��Ч�ʵ�
		Ԫ�ط��ʺ͵�����vectorҪ������������������ͨ��ָ��
	*/

	using Group = deque<int>;

	Group a; //����
	Group b = a; // ��������
	Group c(a); // ����

	Group d(10);
	Group e(10, 1);
	Group f(e.begin(), e.end());
	Group g({ 1,2,3 });
	Group h = { 1,2,3 };

	d.empty();
	d.size();
	d.max_size();
	
	d.shrink_to_fit();//c++11

	//��ֵ
	b = g;
	b.assign(3, 10);//3 ��10
	b.assign(g.begin(), g.end());
	b.assign({ 1,2,3 });

	//����
	b.swap(g);
	swap(b, g);

	//Ԫ�ط���
	b[0];
	b.at(0);//����±�

	//���������
	b.begin();
	b.end();
	b.cbegin();
	b.cend();
	//������

	b.pop_back();// maybe wrong
	if (b.empty()) b.pop_back();

	auto iterAfter = b.erase(b.begin());
	iterAfter = b.erase(b.begin(), b.end());

	b.push_back(10);
	b.pop_back();
	b.push_front(1);
	b.pop_front();
	b.emplace(b.begin(), 1);
	b.emplace_back(10);
	b.emplace_front(1);
	
	auto iter = b.insert(b.end(), 1);
	iter = b.insert(b.end(), 10, -10);//���� 10 �� -10

	b.insert(b.end(), h.begin(), h.end());
	b.resize(10);
	b.resize(100, 10);
	b.clear();
	b.shrink_to_fit();

	//�쳣
	// (1)push_bakc push_front
	// (2)Ԫ�� move/copy û���쳣�Ļ��� insert emplace_back push_back emplace_front
	// (3)pop_back pop_front
	// (4)Ԫ�� move/copyû���쳣�Ļ� erase
	// ��5��swap clara
	//

	//dequeʹ�ó���
	/*using Buffer = vector<char>;
	using BufferGroup = deque<Buffer>;
	BufferGroup group;
	Buffer buffer;
	auto ok = readFromCline(socket, &buffer);
	if (ok) {
		group.emplace_back(move(buffer));
	}
	else {

	}

	while (!group.empty()) {
		auto ok = sendToClient(socket, group.front());
		if (ok) {
			group.pop_front();
		}
		else {

		}
	}*/
}

int main() {
	//STL��һ����ܣ������ݽṹ���㷨��һ������
	//�������㷨��������
	//Container
	//1 ����ʽ���� array\vector\deque\list\forward_list ���� ����ָ��
	//2 ����ʽ���� set\map\multi_map\multi_set ������ ����� 
	// hash_map\hash_set 
	//3 ��˳������ unordered_map/unordered_set/unordered_multimap/unordered_multiset
	//
	// stack
	// queue
	// priority_queue(�����ȼ��Ķ���)
	// string
	// bitset
	// 
	// regex��������ʽ�� 
	// thread async future time

	//
	// ������Ԫ�ص�����
	// (1)������Ը��ƻ��߰��ƣ��������������ڿ����Ͱ��ƵĹ�����Ӧ��û�и����ã�
	// (2)Ԫ�ر�����Ա���ֵ���������ƻ��߰��ƣ���Ϊ�������㷨�Ը�д��Ҫ��
	// (3)Ԫ�ؿ��Ա�����
	// ��ͬ����������Ҫ��
	// ���������ʽ������Ԫ�ر�����Ĭ�ϵĹ��캯��
	// ���ĳЩ������Ԫ�ر��붨�� == 
	// ���ڹ���ʽ����������׼��Ĭ�ϵ��� < less
	// ��������������Ҫ�ṩһ��hash���� == 
	// stl������������Ԫ�ص�ֵ����������
	//
	// 
	//  
	// STL�����ԭ����Ч�����ȡ���ȫΪ��
	system("pause");
	return 0;
}