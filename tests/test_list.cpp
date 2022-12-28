//Copyright 2022 Andrey Karagodin

#include <gtest.h>
#include <../lib_list/list.h>

TEST(test_lib_list, can_create_list) {
	ASSERT_NO_THROW(CList<int> l1());
}

TEST(test_lib_list, can_correctly_push_back) {
	CList<int> l;
	l.push_back(2);
	l.push_back(3);
	int res;
	res = l.pop_back();
	EXPECT_EQ(res, 3);
	EXPECT_FALSE(l.isEmpty());
}

TEST(test_lib_list, can_correctly_push_front) {
	CList<int> l;
	l.push_front(3);
	l.push_front(4);
	int res;
	res = l.pop_front();
	EXPECT_EQ(res, 4);
	EXPECT_FALSE(l.isEmpty());
}

TEST(test_lib_list, can_correctly_pop_back) {
	CList<int> l;
	l.push_back(2);
	l.push_back(3);
	int res;
	res = l.pop_back();
	EXPECT_EQ(res, 3);
	EXPECT_FALSE(l.isEmpty());
}

TEST(test_lib_list, can_correctly_pop_front) {
	CList<int> l;
	l.push_front(3);
	l.push_front(4);
	int res;
	res = l.pop_front();
	EXPECT_EQ(res, 4);
	EXPECT_FALSE(l.isEmpty());
}

TEST(test_lib_list, can_insert) {
	CList<int> l;
	l.push_front(3);
	l.push_front(5);
	ASSERT_NO_THROW(l.insert(1, 4));
}

TEST(test_lib_list, can_insert_correctly) {
	CList<int> l;
	l.push_front(3);
	l.push_front(5);
	l.insert(1, 4);
	int res;
	res = l.pop_back();
	res = l.pop_back();
	EXPECT_EQ(4, res);
}

TEST(test_lib_list, can_remove) {
	CList<int> l;
	l.push_front(3);
	l.push_front(5);
	ASSERT_NO_THROW(l.remove(1));
}

TEST(test_lib_list, can_get_size) {
	CList<int> l;
	l.push_front(1);
	ASSERT_NO_THROW(l.getSize());
}
