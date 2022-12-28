//Copyright 2022 Andrey Karagodin

#ifndef LIB_LIST_LIST_H_
#define LIB_LIST_LIST_H_

#include <iostream>
#include <ostream>
template <class T> class CNode;
template <class T> class CList;

using namespace std;

template <typename T>
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

	friend class CList<T>;
};

template <typename T>
class CList {
	CNode<T>* head;
	CNode<T>* tail;
	size_t size;

public:
	CList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	void push_back(T val) {
		CNode<T>* newnode = new CNode<T>(val);
		if (isEmpty()) {
			head = newnode;
			tail = newnode;
		}
		else {
			tail->next = newnode;
			tail = newnode;
		}
		size++;
	}

	void push_front(T val) {
		CNode<T>* newnode = new CNode<T>(val);
		if (isEmpty()) {
			head = newnode;
			tail = newnode;
		}
		else {
			newnode->next = head;
			head = newnode;
		}
		size++;
	}

	void insert(int index, T val) {
		size_t len = 0;
		len = this->size;
		if (index < 0 || index > len - 1)
			throw("Can't insert in nullprt.");
		else {
			CNode<T>* _pos = head;
			for (int i = 0; i < index; i++) {
				while (_pos->next != tail) {
					_pos = _pos->next;
				}
			}
			CNode<T>* new_node = new CNode<T>(val);
			new_node->next = _pos->next;
			_pos->next = new_node;
			if (new_node->next == nullptr) {
				tail = new_node;
			}
		}
		size++;
	}

	T pop_front() {
		CNode<T>* copy = head;
		T tempType = copy->data;
		if (!(head == nullptr)) {
			CNode<T>* toDel = head;
			head = head->next;
			delete toDel;
			return tempType;
		}
		if (head == nullptr) {
			tail = nullptr;
			return tempType;
		}
		size--;
	}

	T pop_back() {
		CNode<T>* copy = tail;
		T temp = copy->data;
		if (head != tail) {
			CNode<T>* toDel = head;
			while (toDel->next != tail) {
				toDel = toDel->next;
			}
			delete tail;
			tail = toDel;
			return temp;
		}
		else {
			tail = nullptr;
			head = nullptr;
			return temp;
		}
		size--;
	}

	void clear() {
		while (head != nullptr)
			pop_front();
	}

	void copy(const CList& obj) {
		clear();
		CNode<T>* tempNode = obj.head;
		for (int i = 0; i < obj.size && tempNode->next != nullptr; i++)
		{
			push_back(tempNode->data);
			tempNode = tempNode->next;
		}
		if (obj.size != 0 && tempNode == obj.tail) {
			push_back(tempNode->data);
		}
		size = obj.size;
	}

	T remove(int index) {
		size_t len = 0;
		len = size;
		if (index < 0 || index > len - 1){
			throw("Unable to remove with index equals nullpointer.");
		}
		if (index == 0) {
			size--;
			return this->pop_back();
		}
		else if (index == size - 1) {
			size--;
			return this->pop_front();
		}
		else {
			CNode<T>* _pos = head;
			CNode<T>* _pos2 = head;
			for (int i = 0; i < index - 1; i++) {
				_pos2 = _pos2->next;
			}
			for (int i = 0; i < index; i++) {
				_pos = _pos->next;
			}
			_pos2->next = _pos->next;
			CNode<T>* toRet = _pos;
			T tempType = toRet->data;
			delete _pos;
			size--;
			return tempType;
		}
	}
	int getSize() {
		return size;
	}
	bool isEmpty() { return head == nullptr; }
};

#endif // LIB_LIST_LIST_H