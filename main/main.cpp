// Copyright 2022 Andrey Karagodin

#include <stdio.h>
#include <string>
#include "../lib_trees/tree.h"
#include "main.h"

int main() {
    cout << "Бинарное дерево поиска" << endl;

    Tree<int> *tree = new Tree<int>();
    // Значения которые вставим в дерево
    int values[] = { 23, 12, 31, 3, 15, 7, 29, 88, 53 };

    // Вставка значений
    for (const int& value : values)
        tree->insert(value);

    // Выписать все значения из дерева
    cout << "Tree values: ";
    tree->print();

    // Найти значение 31
    // Должен быть найден
    cout << "Search key 31: ";
    bool b = tree->Search(31);
    if (b)
        cout << "found";
    else
        cout << "NOT found";
    cout << endl;

    // Найти значение 18
    // Должен быть НЕ найден
    cout << "Search key 18: ";
    b = tree->Search(18);
    if (b)
        cout << "found";
    else
        cout << "NOT found";
    cout << endl;

    // Минимальные и максимальные значения
    cout << "Min. Key : " << tree->FindMin();
    cout << endl;
    cout << "Max. Key : " << tree->FindMax();
    cout << endl;


    // Successor(31) должен быть 53
    // Successor(15) должен быть 23
    // Successor(88) должен быть -1 or NULL
    cout << "Successor(31) = ";
    cout << tree->Successor(31) << endl;
    cout << "Successor(15) = ";
    cout << tree->Successor(15) << endl;
    cout << "Successor(88) = ";
    cout << tree->Successor(88) << endl;

    // Удаление
    cout << "Removing value 31" << endl;
    tree->Remove(31);
    cout << "Removing value 15" << endl;
    tree->Remove(15);

    // Значения 31 и 15 должны были быть удалены
    cout << "Tree values: ";
    tree->print();

    return 0;
}
