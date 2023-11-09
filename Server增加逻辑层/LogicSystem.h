#pragma once
#include "Singleton.h"

#include <iostream>
#include <thread>
#include <queue>
#include <map>
#include <functional>
#include <memory>
class CSession;
class LogiNode;


typedef std::function<void(std::shared_ptr<CSession>, short msg_id, std::string msg)> FunCallback;

//logicNode - (shared_ptr<CSession>, shared_ptr<RecvNode>)
class LogicNode;

class LogicSystem :public SingleTon<LogicSystem> {
	friend class SingleTon<LogicSystem>;
public:
	~LogicSystem();
	void PostMsgToQue(std::shared_ptr<LogicNode> msg);
private:
	LogicSystem();
	void DealMsg();
	void RegisterCallback();
	void HelloWorldCallback(std::shared_ptr<CSession> session, short msg_id, std::string msg);

	std::thread _worker_thread;
	std::queue<std::shared_ptr<LogicNode>> _msg_que;
	std::mutex _mutex;
	std::condition_variable _cv;
	bool _b_stop;
	std::map<short, FunCallback> _fun_callbacks;
};