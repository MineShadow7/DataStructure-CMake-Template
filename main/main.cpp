// Copyright 2022 Marina Usova

#include <stdio.h>
#include "../lib_stack/stack.h"
#include "../lib_example/example.h"

void main() {
	Stack<int> st;
	st.push(3);
	st.push(9);
	st.push(371);
	std::cout << st;

}
