#pragma once

#include <cstdio>
#include <cstdlib>
#include <cstring>

/// <summary>
/// ������Ϣ��
/// </summary>
class chat_message
{
public :
	//constexpr �������ʽ �ڱ���ʱ����� �ڳ��������ڼ�����֪�� �����ڱ���ʱ�����Ż�
	//��ͷ���� 
	static constexpr std::size_t header_length = 4;
	//������󳤶�
	static constexpr std::size_t max_body_lenght = 512;

	chat_message() : body_length_{0} {}

	const char* data() const{
		return data_;
	}

	char* data() {
		return data_;
	}

	std::size_t length()const {
		return header_length + body_length_;
	}
	const char* body()const {
		return data_ + header_length;//data_��һ����ַ + header_length	�൱��index�±�+header_length
	}
	char* body() {
		return data_ + header_length;
	}

	std::size_t body_length() const{
		return body_length_;
	}
	void body_length(std::size_t new_length) {
		body_length_ = new_length;
		if (body_length_ > max_body_lenght) {
			body_length_ = max_body_lenght;
		}
	}

	bool decode_header() {
		char header[header_length + 1] = "";//����C���Ե��ַ��� ������� \0��βռһ���ַ�����+1
		//�� data_ ��ָ����ַ���׷�ӵ� header ��ָ����ַ����Ľ�β��ֱ�� n �ַ�����Ϊֹ��
		strncat_s(header, data_, header_length);
		//�Ѳ��� str ��ָ����ַ���ת��Ϊһ������
		body_length_ = std::atoi(header);
		if (body_length_ > max_body_lenght) {
			body_length_ = 0;
			return false;
		}
		return true;
	}

	void encode_header() {
		char header[header_length + 1] = "";
		//��body_length_��ʽ�����ַ���д�� header
		sprintf_s(header, "%4d", static_cast<int>(body_length_));
		//�Ӵ洢�� header ���� header_length ���ֽڵ��洢�� data_��
		//���Ŀ������destin�����������ݣ�ִ��memcpy�����󣬽�����ԭ�����ݣ���า��n����
		std::memcpy(data_, header, header_length);
	}

private:
	char data_[header_length + max_body_lenght];
	std::size_t body_length_;
};

