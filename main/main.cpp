// Copyright 2022 Marina Usova

#include <stdio.h>
#include "../lib_list/list.h"
#include "main.h"

void main() {
	CNode<int> node1(5);
	CNode<int> node2(10);
	node2.print();

	node1.setnext(&node2);
	node1.print();

	node1.getnext()->print();
}
