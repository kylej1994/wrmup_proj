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
   EXPECT_FALSE(community.add_person(q));
}

// test get_all_usernames
//   there's no EXPERT functions for comparing non-built-in types, you need to
//   do some parsing by yourself
TEST_F(test_community, get_all_usernames) {
    Person p1, p2, p3;
    string s1, s2, s3;
    s1 = "p1user";
    s2 = "p2user";
    s3 = "p3user";
    p1.set_username(s1);
    p2.set_username(s2);
    p3.set_username(s3);
    list<string> usernames;
    list<string> comm_usernames = community.get_all_usernames();;
    list<string>::iterator iter1 = usernames.begin();
    list<string>::iterator iter2 = comm_usernames.begin();
    /*Base test. Test for two empty strings*/
    for (; iter1 != usernames.end() && iter2 != comm_usernames.end(); ++iter1, ++iter2)
    {
        EXPECT_STREQ(iter1->c_str(), iter2->c_str());
    }

    usernames.push_back(s1);
    usernames.push_back(s2);
    usernames.push_back(s3);
    community.add_person(p1);
    community.add_person(p2);
    community.add_person(p3);
    comm_usernames = community.get_all_usernames();
    iter1 = usernames.begin();
    iter2 = comm_usernames.begin();

    /*Base test. Test for two strings that are the same size*/
    for (; iter1 != usernames.end() && iter2 != comm_usernames.end(); ++iter1, ++iter2)
    {
        EXPECT_STREQ(iter1->c_str(), iter2->c_str());
    }

    list <string> usernames2;
    usernames2.push_back(s3);
    usernames2.push_back(s2);
    usernames2.push_back(s1);
    iter1 = usernames2.begin();
    iter2 = comm_usernames.begin();
     for (; iter1 != usernames2.end() && iter2 != comm_usernames.end(); ++iter1, ++iter2)
    {
        EXPECT_STRNE(iter1->c_str(), iter2->c_str());
    }   

}

// test find_member by first name and age range
TEST_F(test_community, find_member) {
    Person p1, p2, p3;
    list<Person>::iterator iter1;
    list<Person>::iterator iter2;
    p1.set_firstname("John");
    p2.set_firstname("Kyle");
    p3.set_firstname("John");
    p1.set_age(20);
    p2.set_age(30);
    p3.set_age(35);
    community.add_person(p1);
    community.add_person(p2);
    list<Person> result1 = community.find_member("John"); //should find 2 people
    list<Person> result2 = community.find_member("Joe"); //no response
    list<Person> result3 = community.find_member(10, 50); //all people
    list<Person> result4 = community.find_member(20, 20); //just one person
    list<Person> result5 = community.find_member(0, 10); //no response

    //Test for no equality
    list<Person> correct1;
    for (iter1 = result1.begin(), iter2 = correct1.begin(); iter1 != result1.end() && iter2 != correct1.end(); ++iter1, ++iter2)
    {
        EXPECT_STREQ((*iter1).get_info().c_str(), (*iter2).get_info().c_str());
    }   

    //Test for a lack of equality
    correct1.push_back(p2);
    for (iter1 = result1.begin(), iter2 = correct1.begin(); iter1 != result1.end() && iter2 != correct1.end(); ++iter1, ++iter2)
    {
        EXPECT_STRNE((*iter1).get_info().c_str(), (*iter2).get_info().c_str());
    }   

    //Test for ==
    list<Person> correct2;
    correct2.push_back(p1);
    for (iter1 = result1.begin(), iter2 = correct2.begin(); iter1 != result1.end() && iter2 != correct2.end(); ++iter1, ++iter2)
    {
        EXPECT_STREQ((*iter1).get_info().c_str(), (*iter2).get_info().c_str());
    }   

    //Test for equality
    list<Person> correct3;
    correct3.push_back(p1);
    for (iter1 = result2.begin(), iter2 = correct3.begin(); iter1 != result2.end() && iter2 != correct3.end(); ++iter1, ++iter2)
    {
        EXPECT_STREQ((*iter1).get_info().c_str(), (*iter2).get_info().c_str());
    }   

    //All people 
    // list<Person> correct4;
    // correct4.push_back(p1);
    // correct4.push_back(p2);
    // for (iter1 = result3.begin(), iter2 = correct4.begin(); iter2 != result3.end() && iter2 != correct4.end(); ++iter1, ++iter2)
    // {
    //     // EXPECT_STREQ((*iter1).get_info().c_str(), (*iter2).get_info().c_str());
    //     printf("%s\n", (*iter1).get_info().c_str());
    // }

    //Test for equality
    list<Person> correct5;
    correct3.push_back(p1);
    for (iter1 = result5.begin(), iter2 = correct5.begin(); iter1 != result5.end() && iter2 != correct5.end(); ++iter1, ++iter2)
    {
        EXPECT_STREQ((*iter1).get_info().c_str(), (*iter2).get_info().c_str());
    }   
}

// test get_member
TEST_F(test_community, get_member) {
    Person p1, p2, p3;
    p1.set_firstname("user1");
    p2.set_firstname("user2");
    
    community.add_person(p1);
    community.add_person(p2);
    community.add_person(p3);
    Person result1 = community.get_member("user1"); //found
    Person result2 = community.get_member(""); //no response
    Person result3 = community.get_member("user27"); //new object
    EXPECT_STREQ(result1.get_info().c_str(), p1.get_info().c_str());
    // EXPECT_STRNE(result1.get_info().c_str(), p2.get_info().c_str());
    // EXPECT_STRNE(result2.get_info().c_str(), p1.get_info().c_str());
    // EXPECT_STREQ(result2.get_info().c_str(), p2.get_info().c_str());
    Person p4;
    EXPECT_STREQ(result2.get_info().c_str(), p4.get_info().c_str());

}

// test send_msg
TEST_F(test_community, send_msg) {
    // Person p1, p2, p3;
    // string s1, s2, s3;
    // s1 = "p1user";
    // s2 = "p2user";
    // s3 = "p3user";
    // p1.set_username(s1);
    // p2.set_username(s2);
    // p3.set_username(s3);
    // usernames.push_back(s1);
    // usernames.push_back(s2);
    // usernames.push_back(s3);
    // community.add_person(p1);
    // community.add_person(p2);
    // community.add_person(p3);
    // EXPECT_TRUE();
    // EXPECT_FALSE();
}

