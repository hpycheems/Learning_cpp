#pragma once
#include <iostream>
#include <mutex>
#include <memory>

template<class T>
class SingleTon {
protected:
	SingleTon() = default;
	SingleTon(const SingleTon<T>&) = delete;
	SingleTon& operator=(const SingleTon<T>& st) = delete;

	static std::shared_ptr<T> _instance;
public:
	static std::shared_ptr<T> GetInstance() {
		static std::once_flag s_flag;
		std::call_once(s_flag, [&]() {
			_instance = std::shared_ptr(new T);
		});
		return _instance;
	}

	void PrintAddress() {
		std::cout << _instance.get() << "\n";
	}
	~SingleTon() {
		std::cout << "~SingletonÎö¹¹\n";
	}

};
template<class T>
std::shared_ptr<T> SingleTon<T>::_instance = nullptr;