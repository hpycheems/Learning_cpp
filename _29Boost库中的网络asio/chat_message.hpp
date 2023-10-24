#pragma once

#include <cstdio>
#include <cstdlib>
#include <cstring>

/// <summary>
/// 房间消息类
/// </summary>
class chat_message
{
public :
	//constexpr 常量表达式 在编译时计算的 在程序运行期间是已知的 并且在编译时进行优化
	//包头长度 
	static constexpr std::size_t header_length = 4;
	//包体最大长度
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
		return data_ + header_length;//data_是一个地址 + header_length	相当于index下标+header_length
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
		char header[header_length + 1] = "";//根据C语言的字符串 后面会以 \0结尾占一个字符所以+1
		//把 data_ 所指向的字符串追加到 header 所指向的字符串的结尾，直到 n 字符长度为止。
		strncat_s(header, data_, header_length);
		//把参数 str 所指向的字符串转换为一个整数
		body_length_ = std::atoi(header);
		if (body_length_ > max_body_lenght) {
			body_length_ = 0;
			return false;
		}
		return true;
	}

	void encode_header() {
		char header[header_length + 1] = "";
		//将body_length_格式化成字符串写入 header
		sprintf_s(header, "%4d", static_cast<int>(body_length_));
		//从存储区 header 复制 header_length 个字节到存储区 data_。
		//如果目标数组destin本身已有数据，执行memcpy（）后，将覆盖原有数据（最多覆盖n）。
		std::memcpy(data_, header, header_length);
	}

private:
	char data_[header_length + max_body_lenght];
	std::size_t body_length_;
};

