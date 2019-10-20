#ifndef ACTOR_H
#define ACTOR_H

#include <iostream>
using namespace std;


class Actor
{
public:
    //Creates actor with name "?", "?" and birth year 0
    Actor();
    Actor(const string& fName, const string& lName, int bYear);

    void setFirstName(const string& newName);

    //Returns string containing info about this actor
    string getInfo() const;

private:
    string firstName;
    string lastName;
    int birthYear;
};

#endif // ACTOR_H
