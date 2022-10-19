//Copyright 2022 Andrey Karagodin

#ifndef LIB_STACK_STACK_H_
#define LIB_STACK_STACK_H

#include <iostream>
#include <ostream>

using namespace std;
template <class T> class Stack;
template <class T> ostream& operator<<(ostream& os, const Stack<T>& st);

template <class T> 
class Stack {
	T* data;
	size_t size, top;
private:
	size_t getSize() { return size; }
public:

	Stack() {
		size = 25;
		top = -1;
		data = new T[size];
	}

	~Stack() {
		delete[] data;
	}

	void push(const T& val) {
		if (!isFull()) {
			top += 1;
			data[top] = val;
		}else
		throw std::logic_error("Stack is full");
	}

	void pop() {
		if (!isEmpty()) {
			top -= 1;
		}else
		throw std::logic_error("Stack is empty");
	}

	bool isFull() { return top == (size - 1); }

	bool isEmpty() { return top == 1; }

	friend ostream& operator<< <T>(ostream& os, const Stack<T>& st);
};

template <class T>
ostream& operator<<(ostream& os, const Stack<T>& st)
{
	for (int i = 0; i < st.top + 1; i++) {
		os << st.data[i] << " ";
	}
	return os;
}

#endif // LIB_STACK_STACK_H