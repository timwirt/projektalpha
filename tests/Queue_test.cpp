#include <gtest/gtest.h>
#include <../src/Queue.cpp>

TEST(ProjektAlpha, QueueSizeFirstElementTest) {
    ProjektAlpha::Queue<std::string> q = ProjektAlpha::Queue<std::string>((std::string)"Hello");
    EXPECT_EQ(q.get_size(), 1);

    q.insert("this");
    q.insert("is");
    q.insert("a");
    q.insert("Queue");
    q.insert("Test!");
    EXPECT_EQ(pq.get_size(), 6);
    EXPECT_EQ(pq.get_first(), "Hello");

    pq.remove();
    EXPECT_EQ(list.get_size(), 5);
    
}