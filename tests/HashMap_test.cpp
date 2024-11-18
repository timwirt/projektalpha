#include <gtest/gtest.h>
#include <../src/HashMap.cpp>

TEST(HashMapTest, AddAndRemoveAndGetFirstAndConatins) {
    ProjektAlpha::HashMap<std::string> test_HashMap(32);

    test_HashMap.add(std::string("Test_String"));
    EXPECT_EQ("Test_String",test_HashMap.get_first());
    EXPECT_TRUE(test_HashMap.contains(std::string("Test_String")));
    test_HashMap.remove(std::string("Test_String"));
    EXPECT_TRUE(test_HashMap.is_empty());
}

TEST(HashMapTest, ThrowHashMapExceptions) {
    ProjektAlpha::HashMap<std::string> test_HashMap(32);
    EXPECT_THROW(test_HashMap.remove(std::string("Test_String")), std::runtime_error); //HashMap is empty

    test_HashMap.add(std::string("Test_String"));
    EXPECT_THROW(test_HashMap.remove(std::string("Bin nicht drin")), std::runtime_error); //"Bin nicht drin" not in HashMap

    EXPECT_THROW(ProjektAlpha::HashMap<std::string> test_HashMap2(0), std::runtime_error); //Bucket number to small
}

TEST(HashMapTest, Size) {
    ProjektAlpha::HashMap<std::string> test_HashMap(32);

    EXPECT_EQ(0, test_HashMap.get_size());
    test_HashMap.add(std::string("Test_String1"));
    EXPECT_EQ(1, test_HashMap.get_size());
    test_HashMap.add(std::string("Test_String2"));
    EXPECT_EQ(2, test_HashMap.get_size());
    test_HashMap.remove(std::string("Test_String2"));
    EXPECT_EQ(1, test_HashMap.get_size());
    test_HashMap.remove(std::string("Test_String1"));
    EXPECT_EQ(0, test_HashMap.get_size());
}

TEST(HashMapTest, Iterator) {
    ProjektAlpha::HashMap<std::string> test_HashMap(32);

    test_HashMap.add(std::string("Test_String1"));
    test_HashMap.add(std::string("Test_String2"));

    auto it = test_HashMap.begin();

    EXPECT_EQ("Test_String1", *it);
    ++it;
    EXPECT_EQ("Test_String2", *it);
}