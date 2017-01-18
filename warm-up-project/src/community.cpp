#include "community.h"

Community::Community()
  : name(""), people(map<string,Person>()) {
}

Community::Community(string _name, map<string,Person> _people) 
  : name(_name), people(_people) {
}

string Community::get_name() {
	return name;
}

bool Community::set_name(string _name) {
    name = _name;
    return true;
}

bool Community::add_person(Person _person) {
    contact to_add(_person.get_username(), _person);
    
    return false;
}

// return the person object for a given username
Person Community::get_member(string username) {
    if (people.find(username) != people.end()) {
        return people[username];
    }
    else {
        return Person();
    }
}
    
list<string> Community::get_all_usernames() {
    list<string> usernames;
    for (auto const& x : people)
    {
        string username = x.first;
        usernames.push_back(username);
    }
    // TODO (done)
    // return all usernames of members as a list
    // usernames.push_back();
    return usernames;
}

void Community::print_all_usernames() {
    // TODO (done)
	// print all usernames of members to the console
    for (auto const& x : people)
    {
        std::cout << x.first;
    }
    return;
}

list<Person> Community::find_member(string firstname) {
    list<Person> ret;
    //TODO (done)
    // find users with a certain first name
    for (auto const& x : people)
    {
        Person curr_p = x.second;
        if (curr_p.get_firstname() == firstname)
          ret.push_back(curr_p);
    }
    return ret;
}

list<Person> Community::find_member(int age_lb, int age_ub) {
  list<Person> ret;
  //TODO (done)
  // find users within certain ages [age_lb, age_ub], both lower bound and upper bound shall be inclusive
  for (auto const& x : people)
  {
      Person curr_p = x.second;
      int user_age = curr_p.get_age();
      if (user_age >= age_lb || user_age <= age_lb)
        ret.push_back(curr_p);
  }
  return ret;
}

bool Community::send_msg(list<string> usernames, string msg) {
	//TODO (done) i think
	// send msg to a Person addressed by username
	// make sure the username is validated
  list<string>::iterator iter;
  bool found = true;
  for (iter = usernames.begin(); iter != usernames.end(); iter++) {
    Person p = people.find(iter);
    if (p == people.end()) {
      p.get_msg(msg);
    } else {
      for (auto const& x : people) {
        Person curr_p = x.second;
        curr_p.get_msg(msg);
      }
      found = false;
    }
  }
	return found;
}

