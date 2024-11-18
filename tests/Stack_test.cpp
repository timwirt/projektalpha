#include <gtest/gtest.h>
#include <../src/Stack.cpp>

TEST(StackTest, PushAndPop) {
    ProjektAlpha::Stack<int> test_stack;

    test_stack.push(42);
    EXPECT_EQ(42, test_stack.pop());
}

TEST(StackTest, EmptyStack) {
    ProjektAlpha::Stack<int> test_stack;
    EXPECT_THROW(test_stack.pop(), std::runtime_error);
}

TEST(StackTest, Size) {
    ProjektAlpha::Stack<int> test_stack;

    EXPECT_EQ(0, test_stack.get_size());
    test_stack.push(42);
    EXPECT_EQ(1, test_stack.get_size());
    test_stack.push(0);
    EXPECT_EQ(2, test_stack.get_size());
    test_stack.pop();
    EXPECT_EQ(1, test_stack.get_size());
    test_stack.pop();
    EXPECT_EQ(0, test_stack.get_size());
}