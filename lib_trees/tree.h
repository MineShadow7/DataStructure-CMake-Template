//Copyright 2022 Andrey Karagodin

#ifndef LIB_TREES_TREE_H_
#define LIB_TREES_TREE_H_

#include <iostream>
#include <ostream>

template <class T> class TNode;
template <class T> class Tree;

using namespace std;

template <typename T>
class TNode {
    T data;
    TNode* left;
    TNode* right;
    TNode* parent;

public:
    TNode(T _data) {
        data = _data;
        left = nullptr;
        right = nullptr;
    }

    void setright(TNode* newptr) {
        cout << data << " -> ";
    }

    void setleft(TNode* newptr) {
        cout << data << " -> ";
    }
    friend class Tree<T>;
};

template <typename T>
class Tree {
    TNode* root;

    Tree() {
        root = null;
    }

    bool isEmpty() {
        return root == null;
    }
protected:
    TNode* insert(TNode* node, T newdata) {
        if (node == NULL)
        {
            node = new TNode(newdata);
        }
        else if (node->data < newdata) {
            node->setright(insert(node->right, newdata));
            node->right->parent = node;
        }
        else {
            node->setleft(insert(node->left, newdata));
            node->left->parent = node;
        }

        return node;
    }

    TNode* Search(TNode* node, T data) {
        if (node == NULL) {
            return NULL;
        }
        else if (node->data == data) {
            return data;
        }
        else if (node->data < data) {
            return Search(node->right, data);
        }
        else {
            return Search(node->left, data);
        }
    }

    TNode* Remove(TNode* node, T data) {
        if (node == NULL) {
            return NULL;
        }
        // Небольшое пояснение: Если лист - спокойно удаляем.
        if (node->data == data) {
            if (node->left == NULL && node->right == NULL)
                node = NULL;
        }
        else if (node->left == NULL && node->right != NULL) {
            // Единственный нод который прикреплен снизу будет прикреплен к паренту
            // сверху вниз: 8-9-10 -> 8-10
            node->right->parent = node->parent;
            node = node->right;
        }
        else if (node->left != NULL && node->right == NULL) {
            node->left->parent = node->parent;
            node = node->left;
        }
        else {
            //todo: доделать (https://medium.com/swlh/binary-search-trees-c-484377f0d349)
        }
    }

public:
    void insert(int key) {
        root = insert(root, key);
    }
    bool Search(int data) {
        TNode* res = Search(root, data);
        if (res == NULL) {
            return false;
        }
        else {
            return true;
        }
    }
    void Remove(int val) {
        root = Remove(root, val);
    }
};

#endif // LIB_TREES_TREE_H_