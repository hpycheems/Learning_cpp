#pragma once
#include "chat_message.hpp"

#include <boost/asio.hpp>

#include <deque>
#include <iostream>
#include <list>
#include <memory>
#include <utility>//该头文件中包含了许多与通用工具相关的函数和类模板。
#include <set>

#include <cstdlib>
using boost::asio::ip::tcp;

//-------------------------------------------------------------------
using chat_message_queue = std::deque<chat_message>;
//-------------------------------------------------------------------

class chat_participant {//抽象类
public:
	virtual ~chat_participant() {}
	virtual void deliver(const chat_message& msg) = 0;
};
using chat_participant_ptr = std::shared_ptr<chat_participant>;
//-------------------------------------------------------------------

class chat_room {
public:
	void join(chat_participant_ptr participant) {
		participants_.insert(participant);//房间中的人员列表
		for (const auto& msg : recent_msgs_) {
			participant->deliver(msg);//将旧的消息发送给新连接进来的客户端
		}
	}

	void leave(chat_participant_ptr participant) {//离开房间（断开连接）
		participants_.erase(participant);
	}
	void deliver(const chat_message msg) {
		recent_msgs_.push_back(msg);//将发表的消息插入消息列表的尾部
		while (recent_msgs_.size() > max_recent_msgs) {//如果消息列表满了， 删除头部的消息
			recent_msgs_.pop_front();
		}
		for (auto& participants : participants_) {//使用引用 auto是因为可以减少 auto的拷贝
			participants->deliver(msg);
		}
	}
private:
	std::set<chat_participant_ptr> participants_;
	enum { max_recent_msgs = 100 };
	chat_message_queue recent_msgs_;//保存的旧的消息
};

//-------------------------------------------------------------------
//继承自enable_shared_from_this 相当于使用智能指针管理这个类
class chat_session :public chat_participant, public std::enable_shared_from_this<chat_session> {
public:
	chat_session(tcp::socket socket, chat_room& room) :socket_(std::move(socket)), room_(room) {}
	void start() {
		room_.join(shared_from_this());//加入房间
		do_read_header();
	}
	void deliver(const chat_message& msg) {
		bool write_in_progress = !write_masg_.empty();
		write_masg_.push_back(msg);
		if (!write_in_progress) {
			do_write();
		}
	}
private:
	void do_read_header() {
		auto self(shared_from_this());
		boost::asio::async_read(socket_,
			boost::asio::buffer(read_msg_.data(), chat_message::header_length),
			[this, self](boost::system::error_code ec, std::size_t)
			{
				if (!ec && read_msg_.decode_header()) {
					do_read_body();
				}
				else {
					room_.leave(shared_from_this());
				}
			});
	}

	void do_read_body() {
		auto self(shared_from_this());
		boost::asio::async_read(socket_,
			boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
			[this, self](boost::system::error_code ec, size_t) {
				if (!ec) {
					room_.deliver(read_msg_);
					do_read_header();
				}
				else {
					room_.leave(shared_from_this());
				}
			}
		);
	}

	void do_write() {
		auto self(shared_from_this());
		boost::asio::async_write(socket_,
			boost::asio::buffer(write_masg_.front().data(), write_masg_.front().length()),
			[this, self](auto ec, size_t) {
				if (!ec) {
					write_masg_.pop_front();
					if (!write_masg_.empty()) {
						do_write();
					}
				}
				else {
					room_.leave(shared_from_this());
				}
			}
		);
	}

	tcp::socket socket_;
	chat_room& room_;
	chat_message read_msg_;
	chat_message_queue write_masg_;
};

//-------------------------------------------------------------------
class chat_server {
public:
	chat_server(boost::asio::io_context& io_context, const tcp::endpoint& endpoint) :
		acceptor_{ io_context,endpoint } {
		do_accept();
	}
private:
	void do_accept() {
		acceptor_.async_accept(
			[this](boost::system::error_code ec, tcp::socket socket) {//连接进来的客户端socket
				if (!ec) {
					auto newSession = std::make_shared<chat_session>(std::move(socket), room_);
					newSession->start();
				}
				do_accept();
			});
	}
	tcp::acceptor acceptor_;
	chat_room room_;
};
//-------------------------------------------------------------------