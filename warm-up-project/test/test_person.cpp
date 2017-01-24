#include "gtest/gtest.h"
#include "person.h"

// this class is used for testing public methods in class Person
class test_person: public ::testing::Test {
protected:
	Person person;
	Person recipient;
};

// test get_username and set_username
TEST_F(test_person, test_username) {
	EXPECT_FALSE(person.set_username(""));
	EXPECT_FALSE(person.set_username("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklm"));
	EXPECT_FALSE(person.set_username("1c"));
	EXPECT_FALSE(person.set_username("1"));
	EXPECT_FALSE(person.set_username("a^b"));
	EXPECT_FALSE(person.set_username("b)"));
	EXPECT_TRUE(person.set_username("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl"));
	EXPECT_STREQ(person.get_username().c_str(), "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl");

}

// test get_firstname and set_firstname
TEST_F(test_person, test_firstname) {
	EXPECT_TRUE(person.set_firstname(""));
	EXPECT_FALSE(person.set_firstname("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklm"));
	EXPECT_FALSE(person.set_firstname("1c"));
	EXPECT_FALSE(person.set_firstname("1"));
	EXPECT_FALSE(person.set_firstname("a^b"));
	EXPECT_FALSE(person.set_firstname("b)"));
	EXPECT_TRUE(person.set_firstname("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl"));
	EXPECT_STREQ(person.get_firstname().c_str(), "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl");
}

// test get_lastname and set_lastname
TEST_F(test_person, test_lastname) {
  	EXPECT_FALSE(person.set_lastname("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklm"));
  	EXPECT_TRUE(person.set_lastname("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl"));
  	EXPECT_STREQ(person.get_lastname().c_str(), "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl");
	EXPECT_FALSE(person.set_lastname("abcdefg0"));
	EXPECT_FALSE(person.set_lastname("abcdefg;"));
	EXPECT_TRUE(person.set_lastname(""));
}

/**you may need to write more test functions.
 *  What we provide here is just for your reference
 */

// tests get_gender and set_gender
TEST_F(test_person, test_gender) {
	EXPECT_FALSE(person.set_gender("asdf"));
	EXPECT_FALSE(person.set_gender("a"));
	EXPECT_FALSE(person.set_gender(""));
	EXPECT_TRUE(person.set_gender("f"));
	EXPECT_STREQ(person.get_gender().c_str(), "f");
	EXPECT_TRUE(person.set_gender("m"));
	EXPECT_STREQ(person.get_gender().c_str(), "m");
}

// test get_age and set_age
//   test_person is the name of class your inherit from the base Test class
//   test_age is the name of this test case, which will show up in the test
//     results
//   make sure you cover every subroutine and branches
//   here we test edge cases of invalid ages
//   also, we test the get_age() method
//   avoid using ASSERT_FALSE here; if there is something wrong in ASSERT,
//   it will abort the whole testing which will hinder the grading process
TEST_F(test_person, test_age) {
	EXPECT_FALSE(person.set_age(-1));
	EXPECT_TRUE(person.set_age(0));
	EXPECT_EQ(person.get_age(), 0);
	EXPECT_TRUE(person.set_age(127));
	EXPECT_EQ(person.get_age(), 127);
	EXPECT_FALSE(person.set_age(128));
}

// test get_tagline and set_tagline
TEST_F(test_person, test_tagline) {
	EXPECT_TRUE(person.set_tagline("alksdjf213s"));
	EXPECT_TRUE(person.set_tagline("af&ABSD"));
	EXPECT_TRUE(person.set_tagline("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd"));
	EXPECT_TRUE(person.set_tagline("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcde"));
	EXPECT_FALSE(person.set_tagline("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdef"));
	EXPECT_TRUE(person.set_tagline(""));
	EXPECT_STREQ(person.get_tagline().c_str(), "");
}

// test get_info and set_info
TEST_F(test_person, test_info) {
}

// test send_msg and read_msg
//   to make your code shorter, we suggest combining these tests together; you
//   can also separate them into several test cases
TEST_F(test_person, test_msg) {
}

