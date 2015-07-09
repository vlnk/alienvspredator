/**
 * Class Agent descriptor
 * @file Agent.cpp
 * @author Valentin Laurent et Valentin Elvassore
 * @date 21 Janvier 2014
 */

#include "Agent.hpp"
#include "../Behaviour/IBehaviour.h"
#include "../Behaviour/DefensiveBehaviour.h"
#include "../Data/DataStorage.hpp"

/**
 * Agent constructor.
 * @param x The x-coordonate of the Agent.
 * @param y The y-coordonate of the Agent.
 * @param lifespan The lifespan of the Agent.
 * @param age The age of the Agent.
 * @param fieldOfVision The field of vision of the Agent.
 */
Agent::Agent(int x, int y, int lifespan, int age, int fieldOfVision) :
    _lifespan(lifespan),
    _age(age),
    _field_of_vision(fieldOfVision)
{
	_coordinate = coordinate_t();
	_coordinate.x = x;
	_coordinate.y = y;
    _behaviour = new DefensiveBehaviour();
}

/**
 * Agent destructor.
 */
Agent::~Agent()
{
    delete _behaviour;
}

/**
 * Agent coordonate setter.
 * @param x The x-coordonate of the Agent.
 * @param y The y-coordonate of the Agent.
 */
void Agent::setCoordinate(int x, int y)
{
	_coordinate.x = x;
	_coordinate.y = y;
}

/**
 * Agent toString() method.
 * @return A representative string of Agent object.
 */
std::string Agent::toString() const
{
	return "Ag";
}

/**
 * Agent displayer.
 * @param o A flux to display Agent.
 * @param a The Agent to display.
 * @return The flux which display the Agent.
 */
std::ostream& operator<<(std::ostream &o, Agent const&a)
{
	return o << a.toString();
}

/**
 * Lifespan setter.
 * @param lifespan The lifespan of the agent.
 */
void Agent::setLifespan(const int lifespan)
{
    _lifespan = lifespan;
}

/**
 * Add one year for an Agent.
 */
void Agent::addAge()
{
    _age += 1;
}

void Agent::changeBehaviour(IBehaviour * behaviour)
{
    if (_behaviour)
    {
        delete _behaviour;
        _behaviour = NULL;
    }
    
    this->_behaviour = behaviour;
}

/**
 * Do an action achieved by the agent.
 * @param matrix The matrix of Agents.
 * @param width The width of the matrix.
 * @param height The height of the matrix.
 * @return A boolean which check if the action is achieved.
 */
bool Agent::act(Agent *** matrix, int width, int height)
{
    return this->_behaviour->act(this, matrix, width, height);
}
