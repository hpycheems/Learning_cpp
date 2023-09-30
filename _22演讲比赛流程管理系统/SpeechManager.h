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
	//默认构造
	SpeechManager();

	//显示菜单
	void show_Menu();

	//退出系统
	void exitSystem();

	//创建选手
	void createSpeaker();

	//比赛流程控制
	void startSpeech();

	//抽签
	void sheechDraw();

	//开始比赛
	void startConpete();

	//显示晋级
	void showScore();

	//保存到文件
	void saveRecord();

	//读文件
	void readRecord();

	//显示往届记录
	void showRecord();

	//清空记录
	void clearRecord();

	//析构
	~SpeechManager();

	//初始化
	void Init();

	//成员变量
	vector<int> v1;//比赛选手 容器 12
	vector<int > v2; //第一轮晋级容器 6
	vector<int> vVictory; //胜利前三名容器
	map<int, Speaker> m_Speaker;//存放选手 及编号 
	int m_Index;//比赛轮数

	map<int, vector<string>> m_Record;
	bool fileEmpty;
};

