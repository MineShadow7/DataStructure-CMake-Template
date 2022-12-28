// Copyright 2022 Andrey Karagodin

#include <gtest.h>
#include "../lib_priorityqueue/PQueue.h"
TEST(test_lib_queue_pr_in, can_create_queue) {
	ASSERT_NO_THROW(PQueueIn<int> q1(10));
}

TEST(test_lib_queue_pr_in, cant_create_queue_with_negative_size) {
	ASSERT_ANY_THROW(PQueueIn<int> q1(-1));
}

TEST(test_lib_queue_pr_in, can_correctly_return_top) {
	PQueueIn<int> s(5);
	std::pair<int, int> val5(123, 1);
	std::pair<int, int> val3(23, 2);
	std::pair<int, int> val4(176, 2);
	std::pair<int, int> val2(182, 2);
	std::pair<int, int> val(888, 3);
	s.push(val5);
	s.push(val);
	s.push(val3);
	s.push(val4);
	s.push(val2);
	std::pair<int, int> res;
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	res = s.top();
	EXPECT_EQ(res.first, 888);
	EXPECT_FALSE(s.isEmpty());
}

TEST(test_lib_queue_pr_in, can_correctly_return_pop) {
	PQueueIn<int> s(5);
	std::pair<int, int> val5(123, 1);
	std::pair<int, int> val3(23, 2);
	std::pair<int, int> val4(176, 2);
	std::pair<int, int> val2(182, 2);
	std::pair<int, int> val(888, 3);
	s.push(val5);
	s.push(val);
	s.push(val3);
	s.push(val4);
	s.push(val2);
	std::pair<int, int> res;
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	res = s.pop();
	EXPECT_EQ(res.first, 888);
	EXPECT_TRUE(s.isEmpty());
}



TEST(test_lib_queue_pr_in, cant_get_top_when_queue_empty) {
	PQueueIn<int> q(5);
	ASSERT_ANY_THROW(q.top());
}

TEST(test_lib_queue_pr_in, can_get_pop) {
	PQueueIn<int> q(5);
	std::pair<int, int> val(888, 3);
	q.push(val);
	std::pair<int, int> res;
	ASSERT_NO_THROW(res = q.pop());
}

TEST(test_lib_queue_pr_in, cant_get_pop) {
	PQueueIn<int> q(5);
	ASSERT_ANY_THROW(q.pop());
}

TEST(test_lib_queue_pr_in, cant_push_when_queue_full) {
	PQueueIn<int> q(1);
	std::pair<int, int> val(888, 3);
	std::pair<int, int> val2(88, 2);
	q.push(val);
	ASSERT_ANY_THROW(q.push(val2));
}

TEST(test_lib_queue_pr_in, can_detect_is_full_true) {
	PQueueIn<int> q(1);
	std::pair<int, int> val(888, 3);
	q.push(val);
	EXPECT_TRUE(q.isFull());
}

TEST(test_lib_queue_pr_in, can_detect_is_full_false) {
	PQueueIn<int> q(1);
	EXPECT_FALSE(q.isFull());
}

TEST(test_lib_queue_pr_in, can_detect_is_empty_false) {
	PQueueIn<int> q(1);
	std::pair<int, int> val(888, 3);
	q.push(val);
	EXPECT_FALSE(q.isEmpty());
}

TEST(test_lib_queue_pr_in, can_detect_is_empty_true) {
	PQueueIn<int> q(1);
	std::pair<int, int> val(888, 3);
	EXPECT_TRUE(q.isEmpty());
}

TEST(test_lib_queue_pr_out, can_create_queue) {
	ASSERT_NO_THROW(PQueueOut<int> q1(10));
}

TEST(test_lib_queue_pr_out, cant_create_queue_with_negative_size) {
	ASSERT_ANY_THROW(PQueueOut<int> q1(-1));
}

TEST(test_lib_queue_pr_out, can_correctly_return_top) {
	PQueueOut<int> s(5);
	std::pair<int, int> val5(123, 1);
	std::pair<int, int> val3(23, 2);
	std::pair<int, int> val4(176, 2);
	std::pair<int, int> val2(182, 2);
	std::pair<int, int> val(888, 3);
	s.push(val5);
	s.push(val);
	s.push(val3);
	s.push(val4);
	s.push(val2);
	std::pair<int, int> res;
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	res = s.top();
	EXPECT_EQ(res.first, 888);
	EXPECT_FALSE(s.isEmpty());
}

TEST(test_lib_queue_pr_out, can_correctly_return_pop) {
	PQueueOut<int> s(5);
	std::pair<int, int> val5(1248, 1);
	std::pair<int, int> val3(214, 2);
	std::pair<int, int> val4(63, 2);
	std::pair<int, int> val2(21, 2);
	std::pair<int, int> val(76, 3);
	s.push(val3);
	s.push(val);
	s.push(val5);
	s.push(val4);
	s.push(val2);
	std::pair<int, int> res;
	res = s.pop();
	res = s.pop();
	res = s.pop();
	res = s.pop();
	EXPECT_EQ(res.first, 21);
	EXPECT_FALSE(s.isEmpty());
}

TEST(test_lib_queue_pr_out, cant_get_top_when_queue_empty) {
	PQueueOut<int> q(5);
	ASSERT_ANY_THROW(q.top());
}

TEST(test_lib_queue_pr_out, can_get_pop) {
	PQueueOut<int> q(5);
	std::pair<int, int> val(888, 3);
	q.push(val);
	std::pair<int, int> res;
	ASSERT_NO_THROW(res = q.pop());
}

TEST(test_lib_queue_pr_out, cant_get_pop) {
	PQueueOut<int> q(5);
	ASSERT_ANY_THROW(q.pop());
}

TEST(test_lib_queue_pr_out, cant_push_when_queue_full) {
	PQueueOut<int> q(1);
	std::pair<int, int> val(888, 3);
	std::pair<int, int> val2(88, 2);
	q.push(val);
	ASSERT_ANY_THROW(q.push(val2));
}

TEST(test_lib_queue_pr_out, can_detect_is_full_true) {
	PQueueOut<int> q(1);
	std::pair<int, int> val(888, 3);
	q.push(val);
	EXPECT_TRUE(q.isFull());
}

TEST(test_lib_queue_pr_out, can_detect_is_full_false) {
	PQueueOut<int> q(1);
	EXPECT_FALSE(q.isFull());
}

TEST(test_lib_queue_pr_out, can_detect_is_empty_false) {
	PQueueOut<int> q(1);
	std::pair<int, int> val(888, 3);
	q.push(val);
	EXPECT_FALSE(q.isEmpty());
}

TEST(test_lib_queue_pr_out, can_detect_is_empty_true) {
	PQueueOut<int> q(1);
	std::pair<int, int> val(888, 3);
	EXPECT_TRUE(q.isEmpty());
}
