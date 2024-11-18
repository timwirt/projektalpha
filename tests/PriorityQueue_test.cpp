#include <gtest/gtest.h>
#include <../src/PriorityQueue.cpp>

TEST(ProjektAlpha, PriorityQueueSizeFirstElementTest) {
    ProjektAlpha::PriorityQueue<std::string, int> pq = ProjektAlpha::PriorityQueue<std::string, int>((std::string)"Hello", (int)10);
    EXPECT_EQ(pq.get_size(), 1);

    pq.insert("this", 19);
    pq.insert("is", 18);
    pq.insert("a", 17);
    pq.insert("PriorityQueue", 16);
    pq.insert("Test!", 15);
    pq.insert("Test:", 21);
    EXPECT_EQ(pq.get_size(), 7);
    EXPECT_EQ(pq.get_first(), "Test:");

    pq.remove();
    EXPECT_EQ(list.get_size(), 6);
    
}