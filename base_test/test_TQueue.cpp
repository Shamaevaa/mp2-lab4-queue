#include "TQueue.h"
#include "TQueue.h"
#include <gtest.h>
TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(Queue<int> p(5));
}

TEST(TQueue, cant_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(Queue<int> p(-4));
}

TEST(TQueue, can_add_in_full_queue)
{
	ASSERT_ANY_THROW(Queue<int> p(MaxMemSize + 1));
}

TEST(TQueue, can_get_next_elem_from_the_queue)
{
	Queue<int> p(4);
	EXPECT_EQ(p.GetNextIndex(1), 2);
}
TEST(TQueue, can_put_elem)
{
	Queue<int> p(4);
	ASSERT_NO_THROW(p.Put(2));
}

TEST(TQueue, can_get_elem)
{
	Queue<int> p(4);
	p.Put(2);
	ASSERT_NO_THROW(p.Get());
}

TEST(TQueue, can_correcttly_get_elem_from_the_queue)
{
	Queue<int> p(4);
	p.Put(2);
	EXPECT_EQ(p.Get(), 2);
}

TEST(TQueue, can_check_queue_is_empty)
{
	Queue<int> p(4);
	p.Put(1);
	EXPECT_EQ(p.IsEmpty(), 0);
	EXPECT_EQ(p.IsFull(), 0);
}

TEST(TQueue, can_check_queue_is_full)
{
	Queue<int> p(2);
	p.Put(1);
	p.Put(2);
	EXPECT_EQ(p.IsFull(), 1);
}

TEST(TQueue, can_not_qet_elem_from_empty_queue)
{
	Queue<int> p(2);
	p.Put(1);
	p.Get();
	ASSERT_ANY_THROW(p.Get());
}

TEST(TQueue, can_not_put_elem_in_full_queue)
{
	Queue<int> p(2);
	p.Put(1);
	p.Put(2);
	ASSERT_ANY_THROW(p.Put(3));
}
TEST(TQueue, can_learn_the_first_element_queue)
{
	Queue<int> p(2);
	p.Put(4);
	EXPECT_EQ(p.Check(), 4);
}
