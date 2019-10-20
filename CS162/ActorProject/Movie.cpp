#include "Movie.h"

Movie::Movie(string theTitle, int numberActors)
{
    actors = new Actor*[numberActors];
    numActors = 0;
    maxActors = numberActors;
    title = theTitle;
}

void Movie::print()
{
    cout << title
         << endl;
    for(int i = 0; i < maxActors; i++)
    {
        cout << actors[i]->getInfo()
             << endl;
    }
    cout << endl;
}

void Movie::addActor(Actor* person)
{
    actors[numActors] = person;
    numActors++;
}

Movie::~Movie()
{
    delete[] actors;
}
