//Copyright 2022 Andrey Karagodin

#ifndef LIB_LISTQUEUE_LISTQUEUE_H_
#define LIB_LISTQUEUE_LISTQUEUE_H_

#include <iostream>
#include <ostream>
#include "../lib_list/list.h"

template<class T> class ListQueue;

template <class T>
class ListQueue {
private:
    CList<T> data;
    int top1, end;
    size_t size;

public:
    ~ListQueue() {
        top1 = 0;
        end = -1;
        size = 0;
    }

    ListQueue(size_t _size) {
        if (_size < 1) {
            throw std::logic_error("Size of Queue must be greater than 0!");
        }
        size = _size;
        top1 = 0;
        end = -1;
    }

    void push(const T& val) {
        if (!isFull()) {
            end++;
            data.push_front(val);
        }
        else {
            if (isFull() && top1 != 0) {
                end = size - top1;
                data.push_front(val);
                top1 = 0;
            }
            else {
                throw std::logic_error("Can't push value. Queue is Full.");
            }
        }
    };

    T pop() {
        if (!isEmpty()) {
            T value;
            value = data.pop_back();
            top1++;
        }
        else {
            throw std::logic_error("Can't pop value. Queue is Empty.");
        }
        return value;
    };

    T top() {
        if (!isEmpty()) {
            throw std::logic_error("Can't return Top value. Queue is Empty.");
        }
        CList<T> copy;
        copy = data;
        T value = copy.pop_back();
        return value;
    };

    bool isFull() { return (end == size - 1); };

    bool isEmpty() { return (end - top1) < 0; };
};
#endif // LIB_LISTQUEUE_LISTQUEUE_H_
