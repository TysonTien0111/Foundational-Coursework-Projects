#include <gtest/gtest.h>
#include "Queue.cpp"

TEST(QueueTest, InstantiateEmptyQueue)
{
    Queue<int> queue;
    ASSERT_EQ(queue.size(), 0);
}

TEST(QueueTest, DequeueFromEmptyQueue)
{
    Queue<int> queue;
    ASSERT_EQ(queue.size(), 0);
    ASSERT_EQ(queue.dequeue(), std::nullopt);
    ASSERT_EQ(queue.size(), 0);
}

TEST(QueueTest, DequeueFromNonEmptyQueue)
{
    Queue<int> queue;
    queue.enqueue(14);
    queue.enqueue(6);
    ASSERT_EQ(queue.size(), 2);
    ASSERT_EQ(queue.dequeue(), 14);
    ASSERT_EQ(queue.size(), 1);
    ASSERT_EQ(queue.dequeue(), 6);
    ASSERT_EQ(queue.size(), 0);
    ASSERT_EQ(queue.dequeue(), std::nullopt);
    ASSERT_EQ(queue.size(), 0);
}

TEST(QueueTest, EnqueueToEmptyQueue)
{
    Queue<int> queue;
    queue.enqueue(14);
    ASSERT_EQ(queue.size(), 1);
    queue.enqueue(6);
    ASSERT_EQ(queue.size(), 2);
}

TEST(QueueTest, EnqueueToNonEmptyQueue)
{
    Queue<int> queue;
    queue.enqueue(14);
    queue.enqueue(6);
    ASSERT_EQ(queue.size(), 2);
    ASSERT_EQ(queue.dequeue(), 14);
    ASSERT_EQ(queue.size(), 1);
}
