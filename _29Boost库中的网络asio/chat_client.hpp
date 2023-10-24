#pragma once
#include "chat_message.hpp"
#include "New_chat_message.hpp"

#include <boost/asio.hpp>

#include <iostream>
#include <thread>
#include <deque>

//#include <cstdlib>
using boost::asio::ip::tcp;

using chat_message_queue = std::deque<chat_message>;
using New_chat_message_queue = std::deque<New_chat_message>;

class chat_client {
public:
	chat_client(boost::asio::io_context& io_context,
		const tcp::resolver::results_type& endpoints) :
		io_context_{ io_context }, socket_{ io_context } {
		do_connect(endpoints);
	}
	void write(const chat_message& msg) {
		//使用 post的原因， run是跑在 t线程下的，所有使用post 注册一个function 让它自己来跑
		boost::asio::post(io_context_, [this, msg]() {
			bool write_in_progress = !write_msgs_.empty();
			write_msgs_.push_back(msg);
			if (!write_in_progress) {
				do_write();
			}
			});
	}
	void write(const New_chat_message& msg) {
		boost::asio::post(io_context_, [this, msg]() {
			bool write_in_progress = !New_write_msgs_.empty();
			New_write_msgs_.push_back(msg);
			if (!write_in_progress) {
				do_write();
			}
			});
	}
	void close() {
		boost::asio::post(io_context_, [this]() {socket_.close(); });
	}
private:

	void do_connect(const tcp::resolver::results_type& endpoints) {
		boost::asio::async_connect(socket_, endpoints,
			[this](boost::system::error_code ec, tcp::endpoint) {
				if (!ec) {
					do_read_header();
				}
			});
	}
	void do_read_header() {
		boost::asio::async_read(socket_, boost::asio::buffer(read_msg_.data(),
			chat_message::header_length),
			[this](boost::system::error_code ec, std::size_t) {
				if (!ec && read_msg_.decode_header()) {
					do_read_body();
				}
				else {
					socket_.close();//当前的事情是在 t线程下跑的 所用不用post
				}
			});
	}
	void New_do_read_header() {
		boost::asio::async_read(socket_, boost::asio::buffer(New_read_msg_.data(),
			New_chat_message::header_length),
			[this](boost::system::error_code ec, std::size_t) {
				if (!ec && New_read_msg_.decode_header()) {
					New_do_read_body();
				}
				else {
					socket_.close();//当前的事情是在 t线程下跑的 所用不用post
				}
			});
	}
	void New_do_read_body() {
		boost::asio::async_read(socket_,
			boost::asio::buffer(New_read_msg_.body(), New_read_msg_.body_length()),
			[this](auto ec, std::size_t) {
				if (!ec) {
					std::cout.write(New_read_msg_.body(), read_msg_.body_length());
					std::cout << "\n";
					New_do_read_header();
				}
				else {
					socket_.close();
				}
			});
	}
	void do_read_body() {
		boost::asio::async_read(socket_,
			boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
			[this](auto ec, std::size_t) {
				if (!ec) {
					std::cout.write(read_msg_.body(), read_msg_.body_length());
					std::cout << "\n";
					do_read_header();
				}
				else {
					socket_.close();
				}
			});
	}

	void do_write() {

		boost::asio::async_write(socket_, boost::asio::buffer(write_msgs_.front().data(),
			write_msgs_.front().length()),
			[this](auto ec, std::size_t) {
				if (!ec) {
					write_msgs_.pop_front();
					if (!write_msgs_.empty()) {
						do_write();
					}
				}
				else {
					socket_.close();
				}
			});
	}
	void New_do_write() {
		boost::asio::async_write(socket_, boost::asio::buffer(New_write_msgs_.front().data(),
			New_write_msgs_.front().length()),
			[this](auto ec, std::size_t) {
				if (!ec) {
					write_msgs_.pop_front();
					if (!write_msgs_.empty()) {
						do_write();
					}
				}
				else {
					socket_.close();
				}
			});
	}

	boost::asio::io_context& io_context_;
	tcp::socket socket_;
	chat_message read_msg_;
	chat_message_queue write_msgs_;
	New_chat_message New_read_msg_;
	New_chat_message_queue New_write_msgs_;
};