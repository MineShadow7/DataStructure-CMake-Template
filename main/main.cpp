// Copyright 2022 Marina Usova

#include <stdio.h>
#include "../lib_stack/stack.h"
#include "../lib_example/example.h"
#include "main.h"

void main() {
	Stack<int> st;
	st.push(3);
	st.push(9);
	st.push(371);
	std::cout << st;
	int a = st.gettop();
	cout << " " << a;
	int b;
	b = st.pop();
	cout << " " << b;

}
