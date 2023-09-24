#pragma once

template<class T>
class MyArray {
public:
	MyArray(int capacity) {
		m_Capacity = capacity;
		m_Size = 0;
		pAddress = new T[m_Capacity];
	}

	MyArray(const MyArray& m) {
		this->m_Capacity = m.m_Capacity;
		this->m_Size = m.m_Size;

		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
		}

		this->pAddress = new T[m_Capacity];
		for (int i = 0; i < m_Size; i++)
		{
			this->pAddress[i] = m.pAddress[i];
		}
	}

	MyArray& operator=(const MyArray & m) {
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;

			this->m_Capacity = m.m_Capacity;
			this->m_Size = m.m_Size;
		}
		this->pAddress = new T[m_Capacity];
		for (int i = 0; i < m_Size; i++)
		{
			this->pAddress[i] = m.pAddress[i];
		}
		return *this;
	}

	T& operator[](int index) {
		return this->pAddress[index];
	}

	void Push_Back(const T & val) {
		if (m_Size == m_Capacity) {
			return;
		}
		this->pAddress[m_Size++] = val;
	}

	void Pop_Bakc(){
		if (m_Size == 0) {
			return;
		}
		m_Size--;
	}

	int getCapaciity() {
		return m_Capacity;
	}

	int getSize() {
		return m_Size;
	}

	~MyArray() {
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

private :
	int m_Size;
	int m_Capacity;
	T* pAddress;
};