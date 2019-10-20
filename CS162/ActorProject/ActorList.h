/**
  * @brief MyComplex Project
  * @authors Gabriel Brehm, Jacob M.
  */
#ifndef ACTORLIST_H
#define ACTORLIST_H
#include <fstream>
#
#include "Actor.h"

class ActorList
{
public:
//Creates list of actors by reading in text file
    /**
    * @brief ActorList - creats a defult actorlist object
    */
    ActorList();
    /**
    * @brief ActorList - copy constuctor
    * @param otherList - the other list
    */
    ActorList(const ActorList &otherList);
    /**
    * @brief getActotByIndex - gets the actor by index
    * @param n - the index
    * @return - the actor at the index
    */
    Actor* getActotByIndex(int n) const;
    ~ActorList();

private:

    Actor* actors; //array
    int numActors;
};

#endif // ACTORLIST_H
