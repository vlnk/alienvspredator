/**
 * Class Human descriptor
 * @file Human.cpp
 * @author Valentin Laurent et Valentin Elvassore
 * @date 21 Janvier 2014
 */

#include "Human.hpp"

/**
 * Human constructor
 * @param x the x-coordonate of the Human.
 * @param y the y-coordonate of the Human.
 * @param lifespan the lifespan of the Human.
 * @param age the age of the Human.
 * @param fieldOfVision the field of vision of the Human.
 */
Human::Human(int x, int y, int lifespan, int age, int fieldOfVision) :
    Agent(x, y, lifespan, age, fieldOfVision)
{}

/**
 * Human destructor
 */
Human::~Human()
{}

/**
 * Human toString() method
 * @return a representative string of Human object.
 */
std::string Human::toString() const
{
	return "H";
}

/**
 * Human attack against another Agent
 * @param a an agent who is fighting against Human.
 * @return the final state of Human after the fight.
 */
void Human::attack(Agent * a)
{
    if (a->toString() == "A")
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
Human* Human::giveBirth(const int x,const int y)
{
    return (new Human(x,y,AVERAGE_LIFETIME,0));
}

/**
 * Check is type is the same of called type
 * @param ag an Agent to check the type.
 * @return a boolean.
 */
bool Human::isSameType(Agent * ag)
{
    return (ag->toString() == "H");
}

/**
 * Check if type is the type of Agent prey
 * @param ag an Agent to check type.
 * @return a boolean.
 */
bool Human::isPrey(Agent * ag)
{
    return (ag->toString() == "P");
}

/**
 * Check if type is the type of Agent fear
 * @param ag an Agent to check type.
 * @return a boolean.
 */
bool Human::isFeared(Agent * ag)
{
    return (ag->toString() == "A");
}