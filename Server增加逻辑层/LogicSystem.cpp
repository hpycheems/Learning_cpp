#include "LogicSystem.h"
#include "CSession.h"

LogicSystem::LogicSystem() :_b_stop(false){
	RegisterCallback();
	_worker_thread = std::thread(&LogicSystem::DealMsg, this);
}

void LogicSystem::RegisterCallback()
{
	_fun_callbacks[MSG_HELLO_WORLD] = std::bind(&LogicSystem::HelloWorldCallback, this, 
		std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
}
void LogicSystem::HelloWorldCallback(std::shared_ptr<CSession> session, short msg_id, std::string msg) {
	//处理接收到的消息
	std::cout << "receive data is " << msg << "\n";

	//
}
void LogicSystem::DealMsg() {
	while (true) {
		std::unique_lock<std::mutex> lock(_mutex);
		//_cv.wait(lock, [] {return });
		while (_msg_que.empty() && !_b_stop) {
			_cv.wait(lock);
		}

		if (_b_stop) {
			while (!_msg_que.empty()) {
				auto msg_node = _msg_que.front();
				std::cout << "recv_msg id is" << msg_node->_recvnode->_msg_id << "\n";
				auto call_back_iter = _fun_callbacks.find(msg_node->_recvnode->_msg_id);
				if (call_back_iter == _fun_callbacks.end()) {
					_msg_que.pop();
					continue;
				}
				call_back_iter->second(msg_node->_session, msg_node->_recvnode->_msg_id, 
					std::string(msg_node->_recvnode->_data, msg_node->_recvnode->_cur_len));
				_msg_que.pop();
			}
			break;
		}

		auto msg_node = _msg_que.front();
		std::cout << "recv_msg id is" << msg_node->_recvnode->_msg_id << "\n";
		auto call_back_iter = _fun_callbacks.find(msg_node->_recvnode->_msg_id);
		if (call_back_iter == _fun_callbacks.end()) {
			_msg_que.pop();
			continue;
		}
		call_back_iter->second(msg_node->_session, msg_node->_recvnode->_msg_id, 
			std::string(msg_node->_recvnode->_data, msg_node->_recvnode->_cur_len));
		_msg_que.pop();
	}
}
LogicSystem::~LogicSystem() {
	_b_stop = true;
	_cv.notify_one();
	_worker_thread.join();
}
void LogicSystem::PostMsgToQue(std::shared_ptr<LogicNode> msg) {
	std::unique_lock<std::mutex> lock(_mutex);
	_msg_que.push(msg);
	if (_msg_que.size() == 1) {
		_cv.notify_one();
	}
}

