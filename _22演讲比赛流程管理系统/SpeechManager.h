#pragma once
#include <iostream>
using namespace std;
#include<vector>
#include<map>
#include"Speaker.h"
#include <algorithm>
#include <deque>
#include <numeric>
#include <functional>
#include <fstream>
#include <string>

class SpeechManager
{
public:
	//Ĭ�Ϲ���
	SpeechManager();

	//��ʾ�˵�
	void show_Menu();

	//�˳�ϵͳ
	void exitSystem();

	//����ѡ��
	void createSpeaker();

	//�������̿���
	void startSpeech();

	//��ǩ
	void sheechDraw();

	//��ʼ����
	void startConpete();

	//��ʾ����
	void showScore();

	//���浽�ļ�
	void saveRecord();

	//���ļ�
	void readRecord();

	//��ʾ�����¼
	void showRecord();

	//��ռ�¼
	void clearRecord();

	//����
	~SpeechManager();

	//��ʼ��
	void Init();

	//��Ա����
	vector<int> v1;//����ѡ�� ���� 12
	vector<int > v2; //��һ�ֽ������� 6
	vector<int> vVictory; //ʤ��ǰ��������
	map<int, Speaker> m_Speaker;//���ѡ�� ����� 
	int m_Index;//��������

	map<int, vector<string>> m_Record;
	bool fileEmpty;
};

