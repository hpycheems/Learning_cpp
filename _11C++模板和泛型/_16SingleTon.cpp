#pragma once
#include <iostream>

template<typename T>
class Singleton {
protected:
	Singleton() = default;

	Singleton<T>& operator=(const Singleton&) = delete;
	Singleton(const SingleTon<T>&) = delete;

	static T instance;
public:
	static T getInstance() {
		static std::once_flag s_flag;
		std::call_once(s_flag, [&] {instance = new T; });
	}
};

template<typename T>
T Singleton<T>::instance = nullptr;	