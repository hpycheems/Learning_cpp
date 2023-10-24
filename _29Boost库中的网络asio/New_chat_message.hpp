#pragma once

#include "structHeader.h"

#include <iostream>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

/// <summary>
/// ������Ϣ��
/// </summary>
class New_chat_message
{
public:
	//constexpr �������ʽ �ڱ���ʱ����� �ڳ��������ڼ�����֪�� �����ڱ���ʱ�����Ż�
	//��ͷ���� 
	enum {header_length = sizeof(Header) };
	//������󳤶�
	enum { max_body_lenght = 512 };

	New_chat_message(){}

	const char* data() const {return data_;}

	char* data() {return data_;}

	std::size_t length()const {
		return header_length + m_header.bodySize;
	}
	const char* body()const {
		return data_ + header_length;//data_��һ����ַ + header_length	�൱��index�±�+header_length
	}
	char* body() {
		return data_ + header_length;
	}

	int type()const { return m_header.type; }

	std::size_t body_length() const {
		return m_header.bodySize;
	}
	void setMessage(int messageType, const void* buffer, size_t bufferSize) {
		assert(bufferSize <= max_body_lenght);
		m_header.bodySize = bufferSize;
		m_header.type = messageType;
		std::memcmp(body(), buffer, bufferSize);
		std::memcpy(data(), &m_header, sizeof(m_header));
	}

	bool decode_header() {
		std::memcpy(&m_header, data(), header_length);
		if (m_header.bodySize > max_body_lenght) {
			std::cout << "body size:" << m_header.bodySize << " " 
				<< m_header.type << std::endl;
			return false;
		}
		return true;
	}
private:
	char data_[header_length + max_body_lenght];
	Header m_header;
};

