//Copyright 2022 Andrey Karagodin

#ifndef LIB_QUEUE_QUEUE_H_
#define LIB_QUEUE_QUEUE_H

template <class T>
class Queue {
	T* data;
	size_t size;
		int top, end;
public:

	Queue() {
		size = 25;
		top = 0;
		end = -1;
		data = new T[size];
	}

	explicit Queue(int _size) {
		if (_size < 1) {
			throw std::logic_error("Size must be greater than 0!");
		}
		size = _size;
		top = 0;
		end = -1;
		data = new T[size];
	}

	~Queue() {
		delete[] data;
	}

	T gettop() {
		if (isEmpty() == true) {
			throw std::logic_error("Empty Queue cannot return empty value");
		}
		return data[top];
	}

	T getend() {
		if (isEmpty() == true) {
			throw std::logic_error("Empty Queue cannot return empty value");
		}
		return data[end];
	}

	void push(const T& val) {
		if (!isFull()) {
			end++;
			data[end] = val;
		}
		else
			throw std::logic_error("Queue is full");
	}

	T pop() {
		T val = data[top];
		if (!isEmpty()) {
			top++;
			return val;
		}
		else
			throw std::logic_error("Queue is empty");
	}

	bool isFull() { return end == (size - 1); }

	bool isEmpty() { return end < top; }
};
#endif // LIB_QUEUE_QUEUE_H
