#include "Actor.h"

#include <sstream>

Actor::Actor()
{
    firstName = "?";
    lastName = "?";
    birthYear = 0;
}


Actor::Actor(const string& fName, const string& lName, int bYear)
{
    firstName = fName;
    lastName = lName;
    birthYear = bYear;
}

void Actor::setFirstName(const string& newName) {
    firstName = newName;
}

string Actor::getInfo() const {
    //use stringstream to build up output
    stringstream ss("");
    ss << lastName << ", " << firstName << " (" << birthYear << ")";
    return ss.str();  //convert to string to return
}
