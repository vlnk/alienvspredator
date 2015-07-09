/**
 * Class Predator descriptor
 * @file Predator.cpp
 * @author Valentin Laurent et Valentin Elvassore
 * @date 21 Janvier 2014
 */

#include "Predator.hpp"

/**
 * Predator constructor
 * @param x the x-coordonate of the Predator.
 * @param y the y-coordonate of the Predator.
 * @param lifespan the lifespan of the Predator.
 * @param age the age of the Predator.
 * @param fieldOfVision the field of vision of the Predator.
 */
Predator::Predator(int x, int y, int lifespan, int age, int fieldOfVision) :
    Agent(x, y, lifespan, age, fieldOfVision)
{
}

/**
 * Predator destructor
 */
Predator::~Predator()
{
}

/**
 * Predator toString() method
 * @return a representative string of Predator object.
 */
std::string Predator::toString() const
{
	return "P";
}

/**
 * Predator attack against another Agent
 * @param a an agent who is fighting against Predator.
 * @return the final state of Predator after the fight.
 */
void Predator::attack(Agent * a)
{
    if (a->toString() == "H")
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
Predator* Predator::giveBirth(const int x,const int y)
{
    return (new Predator(x,y,AVERAGE_LIFETIME,0));
}

/**
 * Check is type is the same of called type
 * @param ag an Agent to check the type.
 * @return a boolean.
 */
bool Predator::isSameType(Agent * ag)
{
    return (ag->toString() == "P");
}

/**
 * Check if type is the type of Agent prey
 * @param ag an Agent to check type.
 * @return a boolean.
 */
bool Predator::isPrey(Agent * ag)
{
    return (ag->toString() == "A");
}

/**
 * Check if type is the type of Agent fear
 * @param ag an Agent to check type.
 * @return a boolean.
 */
bool Predator::isFeared(Agent * ag)
{
    return (ag->toString() == "H");
}