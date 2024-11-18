#include <gtest/gtest.h>
#include <../src/LinkedList.cpp>

TEST(ProjectAlpha, LinkedListSizeFirstAndLastElementTest) {//ASSERT VS EXPECT
    ProjektAlpha::LinkedList<std::string> list = ProjektAlpha::LinkedList<std::string>((std::string)"Hello");
    EXPECT_EQ(list.get_size(), 1);

    list.add_back("my");
    auto node = list.add_back("name");
    list.add_back("is");
    list.add_back("Tim!");
    list.add_front("Test:");
    EXPECT_EQ(list.get_size(), 6);
    EXPECT_EQ(list.get_first(), "Test:");
    EXPECT_EQ(list.get_back(), "Tim!");
    EXPECT_NE(list.get_back(), "is");

    list.remove_after(node);
    EXPECT_EQ(list.get_size(), 5);

    //list.print();
}