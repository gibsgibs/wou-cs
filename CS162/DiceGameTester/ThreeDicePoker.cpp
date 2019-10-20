#include "ThreeDicePoker.h"

ThreeDicePoker::ThreeDicePoker()
{
    dice = new Die[3];
}

int ThreeDicePoker::getDieValue(int dieNumber)
{
    return dice[dieNumber].getValue();
}

void ThreeDicePoker::rollDie(int number)
{
    dice[number].roll();
}

void ThreeDicePoker::rollAll()
{
    dice[0].roll();
    dice[1].roll();
    dice[2].roll();
}

int ThreeDicePoker::getScore()
{
    int score = 0;
    if(dice[0].getValue() == dice[1].getValue() &&
       dice[0].getValue() == dice[2].getValue())
    {
        score = 1000;
    }
    else if(dice[0].getValue() == (dice[1].getValue() - 1) &&
            dice[2].getValue() == (dice[1].getValue() + 1))
    {
        score = 400;
    }
    else if(dice[0].getValue() == (dice[1].getValue() + 1) &&
            dice[2].getValue() == (dice[1].getValue() - 1))
    {
        score = 400;
    }
    else if(dice[1].getValue() == (dice[0].getValue() - 1) &&
            dice[2].getValue() == (dice[0].getValue() + 1))
    {
        score = 400;
    }
    else if(dice[1].getValue() == (dice[0].getValue() + 1) &&
            dice[2].getValue() == (dice[0].getValue() - 1))
    {
        score = 400;
    }
    else if(dice[0].getValue() == (dice[2].getValue() - 1) &&
            dice[1].getValue() == (dice[2].getValue() + 1))
    {
        score = 400;
    }
    else if(dice[0].getValue() == (dice[2].getValue() + 1) &&
            dice[1].getValue() == (dice[2].getValue() - 1))
    {
        score = 400;
    }
    else if(dice[0].getValue() == dice[1].getValue() &&
            dice[0].getValue() == dice[2].getValue())
    {
        score = dice[0].getValue() * 40;
    }
    else if(dice[1].getValue() == dice[2].getValue())
    {
        score = dice[1].getValue() * 40;
    }
    else
    {
        int highest = dice[0].getValue();
        for(int i = 0; i < 3; i++)
        {
            if(dice[i].getValue() > highest)
            {
                highest = dice[i].getValue();
            }
        }
        score = highest * 10;
    }
    return score;
}
void ThreeDicePoker::setDie(int dieNumber, int value)
{
    dice[dieNumber].setValue(value);
}

