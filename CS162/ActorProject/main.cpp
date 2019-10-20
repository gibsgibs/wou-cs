#include <iostream>
#include "Movie.h"
#include "ActorList.h"

using namespace std;

int main()
{
    //Load our master list of actors
    ActorList mainActorList;

    //Do stuff...
    Movie movie1("Space Wars", 3);
    Movie movie2("The Breakup", 2);

    movie1.addActor(mainActorList.getActotByIndex(1));
    movie1.addActor(mainActorList.getActotByIndex(2));
    movie1.addActor(mainActorList.getActotByIndex(3));

    movie2.addActor(mainActorList.getActotByIndex(0));
    movie2.addActor(mainActorList.getActotByIndex(2));

    movie1.print();
    movie2.print();

    mainActorList.getActotByIndex(2)->setFirstName("Gibsgibs");

    movie1.print();
    movie2.print();

    ActorList copyActorList(mainActorList);
    copyActorList.getActotByIndex(0)->setFirstName("Tim");

    cout << mainActorList.getActotByIndex(0)->getInfo()
         << endl
         << copyActorList.getActotByIndex(0)->getInfo()
         << endl;


    return 0;
}

