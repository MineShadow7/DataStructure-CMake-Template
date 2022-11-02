//Copyright 2022 Karagodin Andrey

#include <gtest.h>
#include "../lib_queue/queue.h"

TEST(test_lib_queue, can_create_queue) {
	ASSERT_NO_THROW(Queue<int> q1(10));
}

TEST(test_lib_queue, cant_create_queue_with_negative_size) {
	ASSERT_ANY_THROW(Queue<int> q1(-1));
}

TEST(test_lib_queue, can_correctly_return_top) {
	Queue<int> q(5);
	q.push(3);
	int res;
	res = q.gettop();
	EXPECT_EQ(res, 3);
	EXPECT_FALSE(q.isEmpty());
}

TEST(test_lib_queue, can_correctly_return_end) {
	Queue<int> q(5);
	q.push(3);
	q.push(4);
	int res;
	res = q.getend();
	EXPECT_EQ(res, 4);
	EXPECT_FALSE(q.isEmpty());
}

TEST(test_lib_queue, can_correctly_pop) {
	Queue<int> q(5);
	q.push(3);
	int res;
	res = q.pop();
	EXPECT_EQ(res, 3);
	EXPECT_TRUE(q.isEmpty());
}

TEST(test_lib_queue, can_get_top) {
	Queue<int> q(5);
	q.push(3);
	ASSERT_NO_THROW(q.gettop());
}

TEST(test_lib_queue, can_get_end) {
	Queue<int> q(5);
	q.push(3);
	ASSERT_NO_THROW(q.getend());
}

TEST(test_lib_queue, cant_get_top_when_queue_empty) {
	Queue<int> q(5);
	ASSERT_ANY_THROW(q.gettop());
}

TEST(test_lib_queue, can_get_pop) {
	Queue<int> q(5);
	q.push(3);
	int a;
	ASSERT_NO_THROW(a = q.pop());
}

TEST(test_lib_queue, cant_get_pop) {
	Queue<int> q(5);
	ASSERT_ANY_THROW(q.pop());
}

TEST(test_lib_queue, cant_push_when_queue_full) {
	Queue<int> q(1);
	q.push(1);
	ASSERT_ANY_THROW(q.push(2));
}

TEST(test_lib_queue, can_push_correctly) {
	Queue<int> q(1);
	q.push(3);
	int res;
	res = q.gettop();
	EXPECT_EQ(res, 3);
	EXPECT_TRUE(q.isFull());
}

TEST(test_lib_queue, can_push) {
	Queue<int> q(1);
	EXPECT_NO_THROW(q.push(3));
}

TEST(test_lib_queue, can_detect_is_full_true) {
	Queue<int> q(1);
	q.push(3);
	EXPECT_TRUE(q.isFull());
}

TEST(test_lib_queue, can_detect_is_full_false) {
	Queue<int> q(1);
	EXPECT_FALSE(q.isFull());
}

TEST(test_lib_queue, can_detect_is_empty_false) {
	Queue<int> q(1);
	q.push(3);
	EXPECT_FALSE(q.isEmpty());
}

TEST(test_lib_queue, can_detect_is_empty_true) {
	Queue<int> q(1);
	EXPECT_TRUE(q.isEmpty());
}
