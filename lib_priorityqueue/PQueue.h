//Copyright 2022 Andrey Karagodin

#include "../lib_list/list.h"
#include <iostream>

template <class T> class PQueueOut;
template <class T> class PQueueIn;

template <class T>
class PQueueOut {
private:
    CList<std::pair<T, int>> data;
    int topv;
    int size;
    int end;
public:

    ~PQueueOut() {
        topv = 0;
        end = -1;
        size = 0;
    }

    PQueueOut(int _size) {
        if (_size < 1) {
            throw std::logic_error("Size can't be lower than 1");
        }
        size = _size;
        topv = 0;
        end = -1;
    }

    void push(const std::pair<T, int>& value) {
        if (!isFull()) {
            end++;
            data.push_front(value);
        }
        else {
            if (isFull() && topv != 0) {
                end = size - topv;
                data.push_front(value);
                topv = 0;
            }
            else {
                throw std::logic_error("Can't push value. Queue is Full.");
            }
        }
    }

    std::pair<T, int> pop() {
        int index = -1;
        std::pair<T, int> value;
        if (!isEmpty()) {
            CList<std::pair<T, int>> tempList;
            std::pair<T, int> tempVal;
            tempVal = std::make_pair(0, 0);
            tempList.copy(data);
            while (!tempList.isEmpty() && tempVal.second != 1) {
                tempVal = tempList.pop_back();
                index++;
                if (tempVal.second == 1) {
                    value = data.remove(index);
                    topv++;
                    return value;
                }
            }
            index = -1;
            tempVal = std::make_pair(0, 0);
            tempList.copy(data);
            while (!tempList.isEmpty() && tempVal.second != 2) {
                tempVal = tempList.pop_back();
                index++;
                if (tempVal.second == 2) {
                    value = data.remove(index);
                    topv++;
                    return value;
                }
            }
            index = -1;
            tempVal = std::make_pair(0, 0);
            tempList.copy(data);
            while (!tempList.isEmpty() && tempVal.second != 3) {
                tempVal = tempList.pop_back();
                index++;
                if (tempVal.second == 3) {
                    value = data.remove(index);
                    topv++;
                    return value;
                }
            }
        }
        else {
            throw std::logic_error("Can't pop value. Queue is empty.");
        }
        return value;
    }

    std::pair<T, int> top() {
        if (isEmpty()) {
            throw std::logic_error("Can't return top. Queue is Empty.");
        }
        CList<std::pair<T, int>> copy;
        copy = data;
        std::pair<T, int> value = copy.pop_back();
        return value;
    }

    bool isFull() { return end == (size - 1); };
    bool isEmpty() { return (end - topv) < 0; };
};

template <class T>
class PQueueIn {
private:
    CList<std::pair<T, int>> data;
    int topv;
    int size;
    int end;
public:
    ~PQueueIn() {
        topv = 0;
        end = -1;
        size = 0;
    }

    PQueueIn(int _size) {
        if (_size < 1) {
            throw std::logic_error("Size can't be lower than 1.");
        }
        size = _size;
        topv = 0;
        end = -1;
    }
    void push(const std::pair<T, int>& value) {
        CList<std::pair<T, int>> tempList;
        std::pair<T, int> tempVal;
        int index = -1;
        tempList.copy(data);
        if (!isFull()) {
            if (value.second == 1) {
                data.push_back(value);
            }
            else if (value.second == 2 && isEmpty() || value.second == 3 && isEmpty()) {
                data.push_back(value);
            }
            else if (value.second == 3) {
                data.push_front(value);
            }
            else if (value.second > tempVal.second) {
                while (value.second > tempVal.second && !tempList.isEmpty()) {
                    tempVal = tempList.pop_back();
                    index++;
                }
                data.insert(index, value);
            }
            else {
                data.push_front(value);
            }
            end++;
        }
        else {
            if (isFull() && topv != 0) {
                end = size - topv;
                data.push_front(value);
                topv = 0;
            }
            else {
                throw std::logic_error("Can't Push value. Queue is Full.");
            }
        }
    }

    std::pair<T, int> pop() {
        std::pair<T, int> value;
        if (!isEmpty()) {
            value = data.pop_back();
            topv++;
        }
        else {
            throw std::logic_error("Can't pop value. Queue is Empty.");
        }
        return value;
    }

    std::pair<T, int> top() {
        if (isEmpty()) {
            throw std::logic_error("Can't return top. Queue is Empty.");
        }
        CList<std::pair<T, int>> copy;
        copy = data;
        std::pair<T, int> value = copy.pop_back();
        return value;
    }

    bool isFull() { return end == (size - 1); };
    bool isEmpty() { return (end - topv) < 0; };

};