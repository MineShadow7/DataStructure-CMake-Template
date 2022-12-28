//Copyright 2022 Andrey Karagodin

#ifndef LIB_LSTACK_LSTACK_H_
#define LIB_LSTACK_LSTACK_H

#include "../lib_list/list.h"
#include <iostream>
#include <ostream>

template <class T> class LStack;

using namespace std;

template <class T>
class LStack {
private:
    CList<T> data;
    int topv;
    int size;

public:
    LStack(int _size) {
        if (_size < 1) {
            throw std::logic_error("Size can't be lower than 1");
        }
        topv = -1;
        size = _size;
    }
    ~LStack() {
        topv = -1;
        size = 0;
    }
    void push(const T& value) {
        if (!isFull()) {
            topv++;
            data.push_back(value);
        }
        else {
            throw std::logic_error("Stack is full.");
        }
    }

    T top() {
        if (isEmpty()) {
            throw std::logic_error("Stack is empty.");
        }
        CList<T> copy;
        copy = data;
        T value = copy.pop_back();
        return value;
    }

    T pop() {
        T value;
        if (!isEmpty()) {
            value = data.pop_back();
            topv--;
        }
        else {
            throw std::logic_error("Stack is empty.");
        }
        return value;
    }

    bool isFull() { return topv == (size - 1); };

    bool isEmpty() { return topv == -1;  };
};

#endif // LIB_LSTACK_LSTACK_H
