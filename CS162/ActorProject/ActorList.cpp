#include "ActorList.h"
#include <iostream>
using namespace std;

ActorList::ActorList()
{
    //ifstream actorProject("actors.txt"); creates an ifstream
    //                                     object, and opens the file
    ifstream actorProject("actors.txt");
    if(actorProject.fail())
    {
        cout << "File does not exist." << endl;
        cout << "Exit program." << endl;
        exit(0);
    }
//  actorProject.open("actors.txt");

    actorProject >> numActors;
    actors = new Actor[numActors];

    for(int i = 0; i < numActors; i++)
    {
        string lastName;
        string firstName;
        int year;

        actorProject >> lastName >> firstName >> year;
        actors[i] = Actor(firstName, lastName, year);

    }
    if(!actorProject.good())
    {
        cout << "Error reading file.";
        exit(0);
    }
}

ActorList::ActorList(const ActorList& otherList)
{
    numActors = otherList.numActors;
    actors = new Actor[numActors];
    for(int i = 0; i < numActors; i++)
    {
        actors[i] = otherList.actors[i];
    }
}

Actor* ActorList::getActotByIndex(int n) const
{
    return &actors[n];
}

ActorList::~ActorList()
{
    delete[] actors;
}
