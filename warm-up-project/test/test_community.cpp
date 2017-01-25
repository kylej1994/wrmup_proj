#include "gtest/gtest.h"
#include "person.h"
#include "community.h"

// this class is used for testing public methods in class Community
class test_community: public ::testing::Test {
protected:
	Community community;
};

// you should complete the following test cases
// you should add more if you see fit

// test get_name
TEST_F(test_community, get_name) {
    community.set_name("abcdefg");
    EXPECT_STREQ(community.get_name().c_str(), "abcdefg");
}

// test set_name
TEST_F(test_community, set_name) {
    string str_len_128 = "ssdfopijasdopfidsafdsapofijsadpofiaspjfdsaopfdjsdiopajfdsaiodsafjdsifoapjdsfsdfjsdajfpiodsajiofdspajfiodspjfiodsxcvjopixzvjpxzvd";
    string str_len_129 = "ssdfopijasdopfidsafdsapofijsadpofiaspjfdsaopfdjsdiopajfdsaiodsafjdsifoapjdsfsdfjsdajfpiodsajiofdspajfiodspjfiodsxcvjopixzvjpxzvdf";
    EXPECT_FALSE(community.set_name(""));
    EXPECT_FALSE(community.set_name("3456"));
    EXPECT_TRUE(community.set_name("abcdefg"));
    EXPECT_FALSE(community.set_name("abcd123421!!!"));
    EXPECT_FALSE(community.set_name(str_len_129));
    EXPECT_TRUE(community.set_name(str_len_128));
}

// test add_person
TEST_F(test_community, add_person) {
   Person p;
   EXPECT_FALSE(community.add_person(p));
}

// test get_all_usernames
//   there's no EXPERT functions for comparing non-built-in types, you need to
//   do some parsing by yourself
TEST_F(test_community, get_all_usernames) {
}

// test find_member by first name and age range
TEST_F(test_community, find_member) {
}

// test get_member
TEST_F(test_community, get_member) {
}

// test send_msg
TEST_F(test_community, send_msg) {
}

