#include <iostream>
using namespace std;
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>

#include "Person.h"
#include "Position.h"

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
	//array<char, 100> carr;
	//strcpy(&carr[0], "hello world!\n");//����ʹ�� carr.data()
	//strcpy(carr.data(), "hello world!\n");

	//����
	//carr.fill(0);//�������е�����Ԫ�� ��ֵΪ0

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

	//std::remove(b.begin(), b.end(), 1);
	//��c�Ľӿڻ���
	//vector<char> carr(100, 0);
	//strcpy(carr.data(), "hello world");
	//printf("%s", carr.data());

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

void listPart() {
	/*
		list ��c++98�������˫���� ��double linked list��
		namespace std{
			template<class T, typename Allocator = allocator<T>>
		}
		�ص㲻֧���������Ԫ�أ� ����ͷ����β��Ԫ���ٶȿ�
		�κ�λ�ò���ɾ��Ԫ�ض��죬����ʱ�������
		�����ɾ��������ɵ�����ʧЧ
		�����쳣֧�֣������쳣����list���ԣ�Ҫ���ɹ���Ҫ��ʲôӰ�춼û��
	*/

	using Group = list<float>;

	//���� 
	Group a;
	Group b = a;
	Group c(a);
	Group d(10);
	Group e(10, 1);
	Group f(e.begin(), e.end());
	Group g({ 1,2,3 });
	Group h = { 1,2,3 };

	//interface
	d.empty();
	d.size();
	d.max_size();
	//���ṩ�Ľӿ�
	//d.capacity();
	//d.reserve(100)
	//d.shrink_to_fit();
	
	//operator == != < > >= <=

	//��ֵ 
	a = b;
	b.assign(3, 10);
	b.assign(c.begin(), c.end());
	b.assign({ 1,2,3 });

	//����
	b.swap(a);
	swap(a, b);

	//Ԫ�ط��� �����������
	// b[0]
	//b.at(0)
	b.front();
	b.back();

	//������
	b.begin();
	b.end();
	//...
	//�������ƶ�
	auto iterBegin = b.begin();
	advance(iterBegin, 4);//�ƶ�������λ
	//next(iterBegin, 1);//�˷���Ҳ��

	a.pop_back();
	if (!a.empty()) a.pop_back();

	//ɾ��
	b.erase(b.begin());
	b.erase(b.begin(), b.end());

	b.push_back(10);
	b.push_front(10);
	b.pop_back();
	b.pop_front();

	b.emplace(b.begin(), 1);
	b.emplace_back(1);
	b.emplace_front(1);
	auto iter = b.insert(b.end(), 10);
	iter = b.insert(b.end(), 10, 100);
	b.resize(10);
	b.resize(100, 1);

	//�㷨
	b.remove(1);//�Ƴ�����������Ϊ1��Ԫ��
	b.remove_if([](auto v) {return v > 5; });//���������Ƴ�
	b.reverse();//��ת 1 2 3 4 -�� 4 3 2 1
	b.sort();//Ĭ�� 
	//list ��֧�� ʹ��ͨ�õ� sort �㷨 ��Ϊ��֧���������

	g.sort();
	g.merge(b);//�ϲ� �����������

	b.unique();// Ԫ�ر������ź���� 1 1 2 2 3 3 4 4 -�� 1 2 3 4
	c.splice(c.begin(), b);// ��b��Ϊһ�� ���뵽 c��ĳ��λ��
}

void forward_listPart() {
	/*
		forward_list ��c++11������ĵ����У�singly linked list��
		namespace std{
		template<class T, typename Allocator = allocator<T>>
		class forward_list;
		}
		�ص� ��֧���������Ԫ�أ�����ͷ��Ԫ���ٶȿ�
		�κ�λ�ò���ɾ��Ԫ�ض��ܿ죬����ʱ�������
		�����ɾ��������ɵ�����ʧЧ
		�����쳣֧�ֺã������쳣����forward_list���ԣ�Ҫ���ɹ���Ҫ��ʲô�����ᷢ��
	*/

	using Group = forward_list<float>;

	//���� 
	Group a;
	Group b = a;
	Group c(a);
	Group d(10);
	Group e(10, 1);
	Group f(e.begin(), e.end());
	Group g({ 1,2,3 });
	Group h = { 1,2,3 };

	//interface
	d.empty();
	//d.size(); ���ṩsize
	d.max_size();
	//���ṩ�Ľӿ�
	//d.capacity();
	//d.reserve(100)
	//d.shrink_to_fit();

	//operator == != < > >= <=

	//��ֵ 
	a = b;

	b.assign(3, 10);
	b.assign(c.begin(), c.end());
	b.assign({ 1,2,3 });

	//����
	b.swap(a);
	swap(a, b);

	//Ԫ�ط��� �����������
	// b[0]
	//b.at(0)
	b.front();
	//b.back(); 

	//������
	b.begin();
	b.cbegin();
	b.end();
	b.cend();
	//auto iter = b.before_begin();
	//*iter undefine 
	b.before_begin();
	b.cbefore_begin();
	//�������ƶ�
	auto iterBegin = b.begin();
	advance(iterBegin, 4);//�ƶ�������λ
	//next(iterBegin, 1);//�˷���Ҳ��

	//ɾ��
	b.erase_after(b.before_begin());//return void
	b.erase_after(b.before_begin(), b.end());//return void


	b.pop_front();
	b.emplace_after(b.before_begin(), 1);
	b.push_front(10);
	b.emplace_front(1);
	auto iter = b.insert_after(b.before_begin(), 10);
	iter = b.insert_after(b.before_begin(), 10, 100);
	b.resize(10);
	b.resize(100, 1);

	//�㷨
	b.remove(1);//�Ƴ�����������Ϊ1��Ԫ��
	b.remove_if([](auto v) {return v > 5; });//���������Ƴ�
	//b.reverse();//��ת 1 2 3 4 -�� 4 3 2 1
	//b.sort();//Ĭ�� 
	//list ��֧�� ʹ��ͨ�õ� sort �㷨 ��Ϊ��֧���������
	g.merge(b);//�ϲ� �����������
	b.unique();// Ԫ�ر������ź���� 1 1 2 2 3 3 4 4 -�� 1 2 3 4
	//g.sort();
	//c.splice(c.begin(), b);// ��b��Ϊһ�� ���뵽 c��ĳ��λ��
	c.splice_after(c.before_begin(), b);

	auto iter_ = b.before_begin();
	//��ȡλ��
	for (int i = 0; i < 2; i++){++iter_;}
	b.insert_after(iter_, 10);
}
// ����ָ���� �Ŀ� ��Ҫ�� weak_ptr�����������
// ��Ϊ ��ʹ�õ�ʱ ��� ԭ�������� ��� 14������������


void serPart() {
	/*
		set multiset ��c++98������Ķ��������ݽṹ
		namespace std{
			template<typename T, typename Comapre = less<T>, typename Allocator = allocator<T>>
			class set;
		}

		namespace std{
			template<typename T, typename Comapre = less<T>, typename Allocator = allocator<T>>
			class multiset;
		}
		�ص��Զ���Ԫ������
		�����ɾ������֧���ϸ����˳��
		(1) x < y == true, y < x == false
		(2) x < y == true, y < z == true , x < z == true
		(3) x < x === false
		(4) a == b, b== c , c== a
		���ܸı�Ԫ�ص�ֵ

		������
		namespace std{
			template<typename T1, class T2>
			struct pair{
				T1 first,
				T2 second;
			}
		}

		���洢�����Լ�ʵ�ֵ����ʱ����Ҫ�ṩһ���Ƚϵ�����������֪������ʲô�������е�Ԫ�ؽ�������
		���������е�Ԫ���ǲ��ɱ�ģ��� const
		������ָ��Ԫ��ʱ�����ܻ����
		����ͨ������ == ʹ��stl�ṩ�� find����
	*/
	using Group = set<int>;

	Group a;//Ĭ�Ϲ���
	Group b = a;//��������
	Group c(a);//��������
	Group e(c.begin(), c.end());//copy
	Group f({ 1,2,3 });	 // C++11
	Group g = { 1,2,3 }; // C++11

	//interface
	c.empty();
	c.size();
	c.max_size();
	//operator == != < > <= >=
	//������
	auto keycomp = c.key_comp();
	auto valuecomp = c.value_comp();

	//��ֵ
	g = b;

	//����
	b.swap(c);//��������ṩ�Ľ�������������ʹ���ṩ�Ľ�����������ΪЧ�ʱȽϸ�
	swap(a, b);

	//������
	b.begin();
	b.end();
	//...

	//�㷨
	auto num = a.count(1);//ͳ��
	auto findIter = a.find(1);//���� ���ز��ҵ���Ԫ�صĵ����� ���򷵻�end()
	if (findIter == a.end()) {
		
	}
	else {
		*findIter;
	}

	auto lower = a.lower_bound(1);// >= ���ز����λ��
	auto upper = a.upper_bound(1);// >
	auto range = a.equal_range(1);// return make_pair(a.lower_bound(1), a.upper_bound(1))

	//���� ɾ��
	auto eraseInter = b.erase(b.begin());
	eraseInter = b.erase(c.begin(), c.end());
	b.clear();

	auto state = b.insert(1000);//state is a pair = make_pair<iterator,bool> ���ص���һ�� pair firstΪ������ secondΪ�Ƿ����ɹ�
	b.emplace(10);
	b.emplace_hint(b.end(), 1);
}

void mapPart() {
	/*
		map multimap ��C++98������Ķ��������ݽṹ
		namespace std{
			template<typename Key, typename T, typename Compare = less<Key>, 
			typename Allocator = allocator<pair<const Key, T>>>
			class map;

			template<typename Key, typename T, typename Compare = less<Key>,
			typename Allocator = allocator<pair<const Key, T>>>
			class multimap;
		}
		�ص��Զ���Ԫ������
		�����ɾ������O(logn)
		����keyԪ�ر���֧���ϸ����˳��
		(1) x < y == true, y < x == false
		(2) x < y == true, y < z == true , x < z == true
		(3) x < x === false
		(4) a == b, b== c , c== a
		���ܸı�KeyԪ�ص�ֵ
	*/
	using Group = map<int, string>;

	Group a;//Ĭ�Ϲ���
	Group b(a);//��������
	Group c = a;//��������
	Group d(a.begin(), a.end());//copy
	Group e({ {1,"l" },{2,"k"},{3,"x"} });//C++11

	d.empty();//�Ƿ�Ϊ��
	d.size();//������Ԫ�ظ���
	d.max_size();
	//opeator == != < > <= >=
	//��̫���õ�
	auto keycomp = c.key_comp();//����һ���Ƚϼ��ĺ�������
	auto valuecomp = c.value_comp();//����һ���Ƚ�ֻ�ĺ�������

	//��ֵ
	b = c;

	//����
	b.swap(c);
	
	//������
	a.begin();
	a.end();

	auto num = a.count(1);// ����key��ͳ�� ͳ��
	auto findIter = a.find(1);//����key������ ����
	if (findIter == a.end()) {

	}
	else {
		std::pair<int, std::string> obj;
		obj = *findIter;//������������ıȽ϶������ ��Ϊ int �� const int ��ͬ ��Ҫ���¿���һ��
		//*findIter // std::pair<const int, string>&
	}

	auto lower = a.lower_bound(1);// ����һ������λ�� >=
	auto upper = a.upper_bound(1);// ����һ������λ�� >
	auto range = a.equal_range(1);//return std::make_pair(a.lower_bound(1), a.upper_bound(1))

	//ɾ�� �Ͳ���
	auto eraseIter = b.erase(b.begin());
	eraseIter = b.erase(b.begin(), b.end());
	auto state = b.insert(std::make_pair(100, "good"));

	//auto insertIter = b.insert(c.begin(), c.end());
	b.emplace(std::make_pair(1, "ll"));
	b.emplace(11, std::string("a"));// b.emplace(std::pair<const int,std::string(10,"a")>)
	b.emplace(29, "asd");//b.emplace(std::pair<const int, std::strnig(10,"thrid")>);
	b.emplace_hint(b.begin(), std::make_pair(10, "p"));

	//����Ԫ��
	//[]
	//auto string
	auto& info = b[10];
	// []-> auto iter = b.insert(std::make_pair(13, std::string())).first; return (*iter).second
	b[13];//���Ҳ��ɹ�ʱ ���Զ�����һ��Ԫ�� ����ʹ��Ĭ�Ϲ��캯���� 

	//at //��������׳��쳣
	try {
		auto& findInfo = b.at(10);
	}
	catch (...) {

	}

	//����ķ��ʷ�ʽ
	auto findIter_ = b.find(10);
	if (findIter_ != b.end()) {
		auto& b = (*findIter_).second;
	}
	else {

	}
}

void unorderSetAndMap() {
	/*
		unordermulti_set unorder_set
		unordermulti_map unorder_map
		��C++11�� ��hash tableΪ�����ģ��ڲ�Ԫ��û����ȷ˳�������
		namespace std{
			template<typename Key, typename T, typename Hash = hash<Key>, typename EqPred = equal_to<Key>,
			typemane Allocator = allocator<pair<const Key, T>>>
			class unorder_map;

			template<typename Key, typename T, typename Hash = hash<Key>, typename EqPred = equal_to<Key>,
			typemane Allocator = allocator<pair<const Key, T>>>
			class unorder_multimap;

			template<typename T, typename Hash = hash<Key>, typename EqPred = equal_to<Key>,
			typemane Allocator = allocator<pair<T>>>
			class unorder_set;

			template<typename T, typename Hash = hash<Key>, typename EqPred = equal_to<Key>,
			typemane Allocator = allocator<pair<T>>>
			class unorder_multiset;
		}
		�����ɾ������O(1)
		���ܸı�KeyԪ�ص�ֵ
	*/
	using Group = std::unordered_map<Position, Person>;
	Group a;

}
//ʹ��unorder_map�洢�Զ������
//��ʱ��Ҫ�ṩһ��ģ������ػ�
//д������

int main() {
	//serPart();
	//set<int> s{2,3,1,4};
	//for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << "\n";
	//auto itre = s.lower_bound(3);//���ص���Ҫ����λ�õĵ�����
	//for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << "\n";
	//cout << *itre << endl;

	vector<int> v = { 1,2,2,3,4,4,5,6,7,8,8 };
	std::remove(v.begin(), v.end(), 4);
	for (auto value : v) {
		std::cout << value << " ";
	}


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
	// bitset ���ڴ洢 bool
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