//Copyright 2022 Andrey Karagodin

#ifndef LIB_STACK_LIST_H_
#define LIB_STACK_LIST_H_

#include <iostream>
#include <ostream>

using namespace std;

template <class T>
class CNode {
	T data;
	CNode* next;

public:
	CNode(T _data) {
		data = _data;
		next = nullptr;
	}

	void setnext(CNode* newptr) {
		next = newptr;
	}

	void print() {
		cout << data << " -> ";
	}

	CNode* getnext() {
		return next;
	}

	T getdata() {
		return data;
	}

	friend class CList;
};

template <class T>
class CList {
	CNode* head;
	CNode* tail;

public:
	CList() {
		CNode* head = new CNode();
		CNode* tail = new CNode();
	}

	size_t getsize() {
		size_t len = 0;
		CNode* head_copy = head;
		while (head_copy != nullptr) {
			head_copy = head_copy->next;
			len += 1;
		}
		return len;
	}

	void push_back(T val) {
		CNode* newnode = new CNode(val);
		if (!is_Empty()) {
			CNode* newnode = new CNode(val);
			tail->next = newnode;
			tail = newnode;
		}
		else {
			head->next = newnode;
			tail->next = newnode;
			head = newnode;
			tail = newnode;
		}
	}

	void push_front(T val) {
		CNode* newnode = new CNode(val);
		if (!isEmpty()) {
			newnode->next = head;
			head = newnode;
		}
		else {
			head->next = newnode;
			tail->next = newnode;
			head = newnode;
			tail = newnode;
		}
	}

	void insert(CNode* pos, T val) {
		CNode* newnode = new CNode(val);
		if (pos == nullptr) {
			throw logic_error("Position cannot be null.")
		}
		else {
			newnode->next = pos->next;
			pos->next = newnode;
			if (newnode->next == nullptr)
				tail = newnode;
		}
	}

	void pop_head() {
		if (!isEmpty()) {
			CNode* todel = head;
			head = head->next;
			delete todel;
			if (isEmpty()) {
				tail = 0;
			}
		}
		else {
			throw logic_error("List is Empty.");
		}
	};

	void pop_back() {
		CNode* tailcpy = tail;
		tail = head;
		while (tail->next != tailcpy) {
			tail = tail->next;
		}
		delete tailcpy;
	};

	CNode* getlast() {
		return tail;
	}
	
	CNode* getfirst() {
		return head;
	}

	bool isEmpty() { return head == 0; }
};

#endif // LIB_LIST_LIST_H