// Copyright 2022 Andrey Karagodin

#include <stdio.h>
#include <string>
#include "../lib_trees/tree.h"
#include "main.h"

int main() {
    cout << "�������� ������ ������" << endl;

    Tree<int> *tree = new Tree<int>();
    // �������� ������� ������� � ������
    int values[] = { 23, 12, 31, 3, 15, 7, 29, 88, 53 };

    // ������� ��������
    for (const int& value : values)
        tree->insert(value);

    // �������� ��� �������� �� ������
    cout << "Tree values: ";
    tree->print();

    // ����� �������� 31
    // ������ ���� ������
    cout << "Search key 31: ";
    bool b = tree->Search(31);
    if (b)
        cout << "found";
    else
        cout << "NOT found";
    cout << endl;

    // ����� �������� 18
    // ������ ���� �� ������
    cout << "Search key 18: ";
    b = tree->Search(18);
    if (b)
        cout << "found";
    else
        cout << "NOT found";
    cout << endl;

    // ����������� � ������������ ��������
    cout << "Min. Key : " << tree->FindMin();
    cout << endl;
    cout << "Max. Key : " << tree->FindMax();
    cout << endl;


    // Successor(31) ������ ���� 53
    // Successor(15) ������ ���� 23
    // Successor(88) ������ ���� -1 or NULL
    cout << "Successor(31) = ";
    cout << tree->Successor(31) << endl;
    cout << "Successor(15) = ";
    cout << tree->Successor(15) << endl;
    cout << "Successor(88) = ";
    cout << tree->Successor(88) << endl;

    // ��������
    cout << "Removing value 31" << endl;
    tree->Remove(31);
    cout << "Removing value 15" << endl;
    tree->Remove(15);

    // �������� 31 � 15 ������ ���� ���� �������
    cout << "Tree values: ";
    tree->print();

    return 0;
}
