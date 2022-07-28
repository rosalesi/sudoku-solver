#include "gtest/gtest.h"
#include "src/lib/headers/utils.h"

// Tests for the class Utils
class UtilsTest : public ::testing::Test {
  protected:
    Utils utils;
    std::vector<std::string> firstExpected;
    std::vector<std::string> secondExpected;
    std::vector<std::string> thirdExpected;
    void SetUp() override {
      firstExpected.push_back("one");
      firstExpected.push_back("two");
      firstExpected.push_back("three");
      for (int i = 1; i < 10; i ++) {
        secondExpected.push_back(std::to_string(i));
      }
      thirdExpected.push_back("0");
    }
};

// Test for the method split on a Utils
TEST_F(UtilsTest, testSplit) {
  EXPECT_EQ(utils.split("one two three"), firstExpected);
  EXPECT_EQ(utils.split("1 2 3 4 5 6 7 8 9"), secondExpected);
  EXPECT_EQ(utils.split("0"), thirdExpected);
}