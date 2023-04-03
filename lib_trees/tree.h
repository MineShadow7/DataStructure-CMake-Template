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
public:
    T data;
    TNode<T>* left;
    TNode<T>* right;
    TNode<T>* parent;
    friend class Tree<T>;
};

template <typename T>
class Tree {
    TNode<T>* root;
    bool isEmpty() {
        return root == null;
    }
protected:
    TNode<T>* insert(TNode<T>* node, T data) {
        if (node == NULL)
        {
            TNode<T> *node = new TNode<int>();
            node->data = data;
            node->left = NULL;
            node->right = NULL;
            node->parent = NULL;
            return node;
        }
        else if (node->data < data) {
            node->right = insert(node->right, data);
            node->right->parent = node;
        }
        else {
            node->left = insert(node->left, data);
            node->left->parent = node;
        }
        return node;
    }

    TNode<T>* Search(TNode<T>* node, T data) {
        if (node == NULL) {
            return NULL;
        }
        else if (node->data == data) {
            return node;
        }
        else if (node->data < data) {
            return Search(node->right, data);
        }
        else {
            return Search(node->left, data);
        }
    }

    TNode<T>* Remove(TNode<T>* node, T data) {
        if (node == NULL)
            return NULL;

        // Ќебольшое по€снение: ≈сли лист - спокойно удал€ем.
        if (node->data == data) {
            if (node->left == NULL && node->right == NULL)
                node = NULL;

            else if (node->left == NULL && node->right != NULL) {
                // ≈динственный нод который прикреплен снизу будет прикреплен к паренту
                // сверху вниз: 8-9-10 -> 8-10
                node->right->parent = node->parent;
                node = node->right;
            }
            else if (node->left != NULL && node->right == NULL) {
                node->left->parent = node->parent;
                node = node->left;
            }
            else {
                T successorKey = Successor(data);
                node->data = successorKey;
                node->right = Remove(node->right, successorKey);
            }
        }
        else if (node->data < data) {
            node->right = Remove(node->right, data);
        }

        else
            node->left = Remove(node->left, data);
        return node;
    }

    T FindMin(TNode<T>* node) {
        if (node == NULL)
            return -1;
        else if (node->left == NULL)
            return node->data;
        else
            return FindMin(node->left);
    }

    T FindMax(TNode<T>* node) {
        if (node == NULL)
            return -1;
        else if (node->right == NULL)
            return node->data;
        else
            return FindMax(node->right);
    }

    T Successor(TNode<T>* node) {
        // successor это мин. значение правой ветки.
        if (node->right != NULL)
        {
            return FindMin(node->right);
        }
        //если нет правой ветки
        else {
            TNode<T>* parentNode = node->parent;
            TNode<T>* currentNode = node;
            //≈сли currentNode не рут и имеет правые ветви, то идем выше
            while ((parentNode != NULL) && (currentNode == parentNode->right)) {
                currentNode = parentNode;
                parentNode = currentNode->parent;
            }
            //≈сли parentNode != null тогда значение parentNode это successor нода.
            return parentNode == NULL ? -1 :
                parentNode->data;
        }
    }

    void print(TNode<T>* node) {
        if (node == NULL)
            return;
        print(node->left);
        std::cout << node->data << ' ';
        print(node->right);
    }

public:

    void insert(T data) {
        root = insert(root, data);
    }
    bool Search(T data) {
        TNode<T>* res = Search(root, data);
        if (res == NULL) {
            return false;
        }
        else {
            return true;
        }
    }
    void Remove(T val) {
        root = Remove(root, val);
    }

    T FindMin() {
        return FindMin(root);
    }

    T FindMax() {
        return FindMax(root);
    }

    T Successor(T data) {
        // ≈сть ли вообще этот нод в дереве.
        TNode<T>* keyNode = Search(root, data);

        // ¬озвращаем значение если найден или -1 если нет.
        return keyNode == NULL ? -1 :
            Successor(keyNode);
    }

    void print() {
        print(root);
        std::cout << std::endl;
    }
};

#endif // LIB_TREES_TREE_H_