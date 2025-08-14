#include <gtest/gtest.h>
#include "Stack.cpp"

TEST(StackTest, InstantiateEmptyStack)
{
    Stack<int> stack;
    ASSERT_EQ(stack.size(), 0);
    ASSERT_EQ(stack.top(), std::nullopt);
}

TEST(StackTest, PushToEmptyStack)
{
    Stack<int> stack;
    stack.push(14);
    ASSERT_EQ(stack.size(), 1);
    ASSERT_EQ(stack.top(), 14);
}

TEST(StackTest, PushToNonEmptyStack)
{
    Stack<int> stack;
    stack.push(14);
    stack.push(6);
    ASSERT_EQ(stack.size(), 2);
    ASSERT_EQ(stack.top(), 6);
}

TEST(StackTest, TopAfterPop)
{
    Stack<int> stack;
    stack.push(14);
    stack.push(6);
    ASSERT_EQ(stack.size(), 2);
    ASSERT_EQ(stack.top(), 6);
    stack.pop();
    ASSERT_EQ(stack.size(), 1);
    ASSERT_EQ(stack.top(), 14);
}

TEST(StackTest, PopFromEmptyStack)
{
    Stack<int> stack;
    ASSERT_EQ(stack.size(), 0);
    ASSERT_EQ(stack.pop(), std::nullopt);
    ASSERT_EQ(stack.size(), 0);
}

TEST(StackTest, PopFromNonEmptyStack)
{
    Stack<int> stack;
    stack.push(14);
    stack.push(6);
    ASSERT_EQ(stack.size(), 2);
    ASSERT_EQ(stack.pop(), 6);
    ASSERT_EQ(stack.size(), 1);
}
