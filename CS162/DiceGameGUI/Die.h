#ifndef DIE_H
#define DIE_H

class Die
{
private:
    int numSides;
    int value;
public:
    Die();
    Die(int theNumSides);
    void roll();
    int getValue();
    void setValue(int forcedValue);
};

#endif // DIE_H
