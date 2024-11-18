#include <gtest/gtest.h>
#include <iostream>

TEST(MeineTestSuite, Sucess) {
  // Sind 1 und 1 gleich?
  EXPECT_EQ(1, 1);
  ASSERT_EQ(1, 1);
}


TEST(MeineTestSuite, Fatal) {
  ASSERT_EQ(1, 2); // Sind 1 und 2 gleich?
  std::cerr << "[  ~HALLO~ ]" << std::endl; //  wird nicht mehr erreicht
}

TEST(MeineTestSuite, NonFatal) {
  EXPECT_EQ(1, 2); // Sind 1 und 2 gleich?
  std::cerr << "[  ~HALLO~ ]" << std::endl; //  wird noch mehr erreicht
}
