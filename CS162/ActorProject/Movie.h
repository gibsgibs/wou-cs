/**
  * @brief MyComplex Project
  * @authors Gabriel Brehm, Jacob M.
  */
#ifndef MOVIE_H
#define MOVIE_H
#include "Actor.h"
class Movie
{
public:
    /**
     * @brief Movie - the 2 argument constuctor that makes a movie object
     * @param theTitle - the title of the movie
     * @param numberActors - the number of actors
     */
    Movie(string theTitle, int numberActors);
    /**
     * @brief print - prints out the movie and actors
     */
    void print();
    /**
     * @brief addActor - adds an actor to the lsit
     * @param person - the actor being added
     */
    void addActor(Actor* person);
    ~Movie();
private:
    string title;
    Actor** actors; //array
    int numActors;
    int maxActors;
};

#endif // MOVIE_H
