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
   Person p, q;
   EXPECT_FALSE(community.add_person(p));
   EXPECT_FALSE(community.add_person(p2));
}

// test get_all_usernames
//   there's no EXPERT functions for comparing non-built-in types, you need to
//   do some parsing by yourself
TEST_F(test_community, get_all_usernames) {
    Person p1, p2, p3;
    String s1, s2, s3;
    s1 = "p1user";
    s2 = "p2user";
    s3 = "p3user";
    p1.set_username(s1);
    p2.set_username(s2);
    p3.set_username(s3);
    list<string> usernames;
    usernames.push_back(s1);
    usernames.push_back(s2);
    usernames.push_back(s3);
    community.add_person(p1);
    community.add_person(p2);
    community.add_person(p3);
    list<string> comm_usernames = community.get_all_usernames();
    for (auto const& curr_user : usernames)
    {
        
    }
}

// test find_member by first name and age range
TEST_F(test_community, find_member) {
    Person p1, p2, p3;
    p1.set_firstname("John");
    p2.set_firstname("Kyle");
    p3.set_firstname("John");
    p1.setage(20);
    p2.setage(30);
    p3.setage(35);
    community.add_person(p1);
    community.add_person(p2);
    community.find_member("John"); //should find person
    community.find_member("Joe"); //no response
    community.find_member(10, 50); //all people
    community.find_member(20, 20); //just one person
    community.find_member(0, 10); //no response
    community.find_member(20, 30); //2 people
}

// test get_member
TEST_F(test_community, get_member) {
    Person p1, p2, p3;
    p1.set_username("user1");
    p2.set_username("user2");
    community.add_person(p1);
    community.add_person(p2);
    community.add_person(p3);
    community.get_member("user1"); //found
    community.get_member(""); //no response
    community.get_member("user27"); //new object
}

// test send_msg
TEST_F(test_community, send_msg) {
    
}

