//Copyright 2022 Andrey Karagodin

#ifndef LIB_STACK_LISTQUEUE_H_
#define LIB_STACK_LISTQUEUE_H_

#include <iostream>
#include <ostream>
#include "../lib_list/list.h"

using namespace std;

template<class T>
class ListQueue {
	CList data;
	size_t size;

public:

	ListQueue() {
		size = 0;
	}

	T End() {
		if (this.isEmpty())
		{
			throw logic_error("Stack is empty");
		}
		CNode* copy = data.getlast();
		return copy.getdata();
	}

	T Top() {
		if (this->isEmpty())
		{
			throw logic_error("Stack is empty");
		}
		CNode* copy = data.getfirst();
		return copy.getdata();
	}

	T Pop() {
		if (!isEmpty()) {
			CNode* copy = data.getfirst();
			data.pop_head();
			size--;
			return copy.getdata();
		}
		else {
			throw logic_error("Stack is empty");
		}
	}

	void push(const T val)
	{
		size++;
		data.push_back(val);
	}

	bool isEmpty() { return size == 0; }
};
#endif // LIB_STACK_STACK_H_
