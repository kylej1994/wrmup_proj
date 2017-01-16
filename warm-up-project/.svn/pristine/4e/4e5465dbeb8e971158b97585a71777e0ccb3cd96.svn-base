#include <regex>
#include "person.h"

bool str_isalpha(const string str){
    for(int i = 0; i < str.size(); i++)
    	if((isalpha(str[i]) == 0) || (str[i] == ' '))
    		return false;
    return true;
}

bool str_isalnum(const string s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

Person::Person() 
  : username(""), firstname(""), lastname(""), gender(""), age(0), tagline("") {
}

Person::Person(string _username, string _firstname, string _lastname, 
               string _gender, int _age, string _tagline) 
  : username(_username), firstname(_firstname), lastname(_lastname),
    gender(_gender), age(_age), tagline(_tagline) {
}

string Person::get_username() {
    return username;
}
string Person::get_firstname() {
    return firstname;
}
string Person::get_lastname() {
    return lastname;
}
string Person::get_gender(){
    return gender;
}
int Person::get_age() {
    return age;
}
string Person::get_tagline() {
    return tagline;
}
string Person::get_info() {
	string ret = "";
    return ret;
}

bool Person::set_username(string _username) {
    // TODO (done)
	// write the function for set_username
    //A Person's username can have a maximum of 64 characters and must have alphanumeric 
    //characters only. Also, it can not start with a digit. Finally, it cannot be the empty string.
    bool not_empty = !_username.compare("");
    bool is_less_64 = length(_username) <= 64;
    bool not_first_digit = _username.at(0); 
    bool is_all_alphanumeric = !std::regex_match(_username, std::regex("^[A-Za-z0-9]+$"));
    if (not_empty && not_first_digit && is_all_alphanumeric && is_less_64){
        username = _username;
    	return true;
    } 
    return false;
}

bool Person::set_firstname(string _firstname) {
    // TODO (done)
    //A Person's firstname and lastname can have a maximum of 64 characters, and must contain only alphabetic characters.
    bool is_less_64 = length(_firstname) <= 64;
    bool not_empty = !_firstname.compare("");
    bool is_all_alphabetic = !std::regex_match(_firstname, std::regex("^[A-Za-z]+$"));
	if (not_empty && is_all_alphabetic && is_less_64) {
        firstname = _firstname;
        return true;
    }
    else {
        return false;
    }
}


bool Person::set_lastname(string _lastname) {
    // TODO (done)
    //A Person's age must be between 0 (inclusive) and 128 (exclusive).
    bool is_less_64 = length(_lastname) <= 64;
    bool not_empty = !_lastname.compare("");
    bool is_all_alphabetic = !std::regex_match(_lastname, std::regex("^[A-Za-z]+$"));
    if (not_empty && is_all_alphabetic && is_less_64) {
        lastname = _lastname;
        return true;
    }
    else {
        return false;
    }
}

bool Person::set_gender(string _gender){
    //TODO (done)
    if (!_gender.compare("m") || !_gender.compare("f"))
    {
        gender = _gender;
        return true;
    }
    return false;
}

bool Person::set_age(int _age) {
	// TODO (done)
    if (_age >= 0 && _age < 128) {
        age = _age;
        return true;
    }
    else {
        return false;
    }
}
bool Person::set_tagline(string _tagline) {
	// TODO (done)
    if (length(_tagline) <= 512) {
        tagline = _tagline;
        return true;
    }
    else {
        return false;
    }
}


bool Person::set_info(string _username, string _firstname, string _lastname,
                      int _age, string _tagline) {
    // TODO (done)
	// set the information for
	// 1) username
	// 2) firstname
	// 3) lastnam3
	// 4) age
	// 5) tagline
    bool su = set_username(_username);
    bool fn = set_firstname(_firstname);
    bool ln = set_lastname(_lastname);
    bool age = set_age(_age);
    bool tl = set_tagline(_tagline);
    if (su && fn && ln && age && tl)
        return true;
	return false;
}

void Person::send_msg(Person &recipient, string msg) {
	// TODO
	// send message
    }

void Person::get_msg(string msg) {
	// TODO
	// get message
    }

bool Person::read_msg() {
	// TODO
	// print the message if there any message inbox
    return false;

}

