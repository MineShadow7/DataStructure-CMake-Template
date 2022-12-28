//Copyright 2022 Karagodin Andrey

#include <gtest.h>
#include "../lib_stack/stack.h"

TEST(test_lib_stack, can_create_stack) {
	ASSERT_NO_THROW(Stack<int> s1(10));
}

TEST(test_lib_stack, cant_create_stack_with_negative_size) {
	ASSERT_ANY_THROW(Stack<int> s1(-1));
}

TEST(test_lib_stack, can_correctly_return_top) {
	Stack<int> st(5);
	st.push(3);
	int res;
	res = st.gettop();
	EXPECT_EQ(res, 3);
	EXPECT_FALSE(st.isEmpty());
}

TEST(test_lib_stack, can_correctly_pop) {
	Stack<int> st(5);
	st.push(3);
	int res;
	res = st.pop();
	EXPECT_EQ(res, 3);
	EXPECT_TRUE(st.isEmpty());
}

TEST(test_lib_stack, can_get_top) {
	Stack<int> st(5);
	st.push(3);
	ASSERT_NO_THROW(st.gettop());
}

TEST(test_lib_stack, cant_get_top_when_stack_empty) {
	Stack<int> st(5);
	ASSERT_ANY_THROW(st.gettop());
}

TEST(test_lib_stack, can_get_pop) {
	Stack<int> st(5);
	st.push(3);
	int a;
	ASSERT_NO_THROW(a = st.pop());
}

TEST(test_lib_stack, cant_get_pop) {
	Stack<int> st(5);
	ASSERT_ANY_THROW(st.pop());
}

TEST(test_lib_stack, cant_push_when_stack_full) {
	Stack<int> s(1);
	s.push(1);
	ASSERT_ANY_THROW(s.push(2));
}

TEST(test_lib_stack, can_push_correctly) {
	Stack<int> st(1);
	st.push(3);
	int res;
	res = st.gettop();
	EXPECT_EQ(res, 3);
	EXPECT_TRUE(st.isFull());
}

TEST(test_lib_stack, can_push) {
	Stack<int> st(1);
	EXPECT_NO_THROW(st.push(3));
}

TEST(test_lib_stack, can_detect_is_full_true) {
	Stack<int> st(1);
	st.push(3);
	EXPECT_TRUE(st.isFull());
}

TEST(test_lib_stack, can_detect_is_full_false) {
	Stack<int> st(1);
	EXPECT_FALSE(st.isFull());
}

TEST(test_lib_stack, can_detect_is_empty_false) {
	Stack<int> st(1);
	st.push(3);
	EXPECT_FALSE(st.isEmpty());
}

TEST(test_lib_stack, can_detect_is_empty_true) {
	Stack<int> st(1);
	EXPECT_TRUE(st.isEmpty());
}
