//Copyright 2022 Andrey Karagodin

#include <gtest.h>
#include "../lib_lstack/lstack.h"

TEST(test_lib_Lstack, can_create_stack) {
	ASSERT_NO_THROW(LStack<int> s1(10));
}

TEST(test_lib_Lstack, cant_create_stack_with_negative_size) {
	ASSERT_ANY_THROW(LStack<int> s1(-1));
}

TEST(test_lib_Lstack, can_correctly_return_top) {
	LStack<int> st(5);
	st.push(3);
	int res;
	res = st.top();
	EXPECT_EQ(res, 3);
	EXPECT_FALSE(st.isEmpty());
}

TEST(test_lib_Lstack, can_correctly_pop) {
	LStack<int> st(5);
	st.push(3);
	int res;
	res = st.pop();
	EXPECT_EQ(res, 3);
	EXPECT_TRUE(st.isEmpty());
}

TEST(test_lib_Lstack, can_get_top) {
	LStack<int> st(5);
	st.push(3);
	ASSERT_NO_THROW(st.top());
}

TEST(test_lib_Lstack, cant_get_top_when_stack_empty) {
	LStack<int> st(5);
	ASSERT_ANY_THROW(st.top());
}

TEST(test_lib_Lstack, can_get_pop) {
	LStack<int> st(5);
	st.push(3);
	int a;
	ASSERT_NO_THROW(a = st.pop());
}

TEST(test_lib_Lstack, cant_get_pop) {
	LStack<int> st(5);
	ASSERT_ANY_THROW(st.pop());
}

TEST(test_lib_Lstack, cant_push_when_stack_full) {
	LStack<int> s(1);
	s.push(1);
	ASSERT_ANY_THROW(s.push(2));
}

TEST(test_lib_Lstack, can_push_correctly) {
	LStack<int> st(1);
	st.push(3);
	int res;
	res = st.top();
	EXPECT_EQ(res, 3);
	EXPECT_TRUE(st.isFull());
}

TEST(test_lib_Lstack, can_push) {
	LStack<int> st(1);
	EXPECT_NO_THROW(st.push(3));
}

TEST(test_lib_Lstack, can_detect_is_full_true) {
	LStack<int> st(1);
	st.push(3);
	EXPECT_TRUE(st.isFull());
}

TEST(test_lib_Lstack, can_detect_is_full_false) {
	LStack<int> st(1);
	EXPECT_FALSE(st.isFull());
}

TEST(test_lib_Lstack, can_detect_is_empty_false) {
	LStack<int> st(1);
	st.push(3);
	EXPECT_FALSE(st.isEmpty());
}

TEST(test_lib_Lstack, can_detect_is_empty_true) {
	LStack<int> st(1);
	EXPECT_TRUE(st.isEmpty());
}
