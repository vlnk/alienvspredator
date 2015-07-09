/**
 * Class Alien descriptor
 * @file Alien.cpp
 * @author Valentin Laurent et Valentin Elvassore
 * @date 21 Janvier 2014
 */

#include "Alien.hpp"

/**
 * Alien constructor
 * @param x the x-coordonate of the Alien.
 * @param y the y-coordonate of the Alien.
 * @param lifespan the lifespan of the Alien.
 * @param age the age of the Alien.
 * @param fieldOfVision the field of vision of the Alien.
 */
Alien::Alien(int x, int y, int lifespan,int age, int fieldOfVision):
    Agent(x, y, lifespan, age, fieldOfVision)
{}

/**
 * Alien destructor
 */
Alien::~Alien()
{}

/**
 * Alien toString() method
 * @return a representative string of Alien object.
 */
std::string Alien::toString() const
{
	return "A";
}

/**
 * Alien attack against another Agent
 * @param a an agent who is fighting against Alien.
 * @return the final state of Alien after the fight.
 */
void Alien::attack(Agent * a)
{
    if (a->toString() == "P")
    {
        _lifespan--;
    }
}

/**
 * Create a new Agent.
 * @param x the x-coordonate.
 * @param y the y-coordonate.
 * @return The new agent created.
 */
Alien* Alien::giveBirth(const int x,const int y)
{
    return (new Alien(x,y,AVERAGE_LIFETIME,0));
}

/**
 * Check if type is the same of called type
 * @param ag an Agent to check the type.
 * @return a boolean.
 */
bool Alien::isSameType(Agent * ag)
{
    return (ag->toString() == "A");
}

/**
 * Check if type is the type of Agent prey
 * @param ag an Agent to check type.
 * @return a boolean.
 */
bool Alien::isPrey(Agent * ag)
{
    return (ag->toString() == "H");
}

/**
 * Check if type is the type of Agent fear
 * @param ag an Agent to check type.
 * @return a boolean.
 */
bool Alien::isFeared(Agent * ag)
{
    return (ag->toString() == "P");
}





