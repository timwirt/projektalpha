#include <gtest/gtest.h>
#include <../src/DoublyLinkedList.cpp>

TEST(ProjectAlpha, DoublyLinkedListSizeFirstAndLastElementTest) {//ASSERT VS EXPECT
    ProjektAlpha::DoublyLinkedList<std::string> list = ProjektAlpha::DoublyLinkedList<std::string>((std::string)"Hello");
    EXPECT_EQ(list.get_size(), 1);

    list.add_back("my");
    list.add_back("name");
    auto node = list.add_back("is");
    list.add_back("Tim!");
    list.add_front("Test:");
    EXPECT_EQ(list.get_size(), 6);
    EXPECT_EQ(list.get_first(), "Test:");
    EXPECT_EQ(list.get_back(), "Tim!");
    EXPECT_NE(list.get_back(), "is");

    list.remove(node);
    EXPECT_EQ(list.get_size(), 5);

    //list.print();
}