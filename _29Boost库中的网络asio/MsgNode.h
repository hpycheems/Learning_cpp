#pragma once
#define HEAD_LENGTH  2
#define MAX_LENGTH  1024

#include <iostream>

class MsgNode {
public:
	MsgNode(char* msg, short max_len) :_total_len(max_len + HEAD_LENGTH), _cur_len(0) {
		_data = new char[_total_len + 1];
		memcpy(_data, &max_len, HEAD_LENGTH);
		memcpy(_data + HEAD_LENGTH, msg, max_len);
		_data[_total_len] = '\0';
	}

	MsgNode(short max_lenth) : _total_len(max_lenth + HEAD_LENGTH), _cur_len(0) {
		_data = new char[_total_len];
	}

	~MsgNode() {
		delete[] _data;
	}

	void Clear() {
		memset(_data, 0, _total_len);
		_cur_len = 0;
	}

	int _cur_len;
	int _total_len;
	char* _data;
};