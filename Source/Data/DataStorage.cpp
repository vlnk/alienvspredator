/**
 * DataStorage.cpp
 *
 *  Created on: 11 janv. 2014
 *  Author: Vavou
 */

#include "DataStorage.hpp"

/**
 * Cumulative proportions for filling the matrix.
 */
const double DataStorage::PROPORTIONS_CUMULEES[4] = {0.04, 0.08, 0.12, 1};

/**
 * DataStorage constructor
 * @param width The width of the matrix.
 * @param height The height of the matrix.
 */
DataStorage::DataStorage(int width, int height):
    _width(width),
    _height(height),
    _num_of_deaths(0),
    _num_of_births(0)
{
	_agents.clear();
	initMatrix();
}

/**
 * DataStorage destructor.
 */
DataStorage::~DataStorage() 
{
    for (std::vector<Agent *>::iterator it = _agents.begin();
         it != _agents.end(); ++it)
    {
        delete (*it);
    }
    _agents.clear();
    
    for (int i = 0; i < _width; ++i)
    {
        delete [] _matrix[i];
        _matrix[i] = NULL;
    }
    
    delete [] _matrix;
    _matrix = NULL;
}

/**
 * Initialize the matrix of Agents.
 */
void DataStorage::initMatrix()
{
	double random;
	_matrix = new Agent**[_width];

	for (int i = 0 ; i < _width ; ++i)
	{
		_matrix[i] = new Agent*[_height];
		for (int j = 0 ; j < _height ; ++j)
		{
			random = GameController::getInstance()->getRandom();
			if (random < PROPORTIONS_CUMULEES[0])
            {
				_matrix[i][j] = new Alien(i,j);
            }
			else if (random < PROPORTIONS_CUMULEES[1])
            {
				_matrix[i][j] = new Human(i,j);
            }
			else if (random < PROPORTIONS_CUMULEES[2])
            {
				_matrix[i][j] = new Predator(i,j);
            }
			else
            {
				_matrix[i][j] = NULL;
            }
            
			if (_matrix[i][j])
            {
                _agents.push_back(_matrix[i][j]);
            }
		}
	}
}

/**
 * Height setter.
 * @param height Assigning height value to _height attribute.
 */
void DataStorage::setHeight(int height) {
	_height = height;
}

/**
 * Width setter.
 * @param width Assigning width value to _width attribute
 */
void DataStorage::setWidth(int width) {
	_width = width;
}

Agent* DataStorage::getAgentAt(int index) const
{
    Agent * r = NULL;
    
    if ((unsigned int)index < _agents.size())
    {
        r = _agents[index];
    }
    
    return r;
}

/**
 * The Agent vector setter.
 * @param vector<Agent*> A vector of agents.
 */
void DataStorage::setAgents(const std::vector<Agent*> agents) {
	_agents = agents;
}

/**
 * The matrix of Agents getter.
 * @return _matrix The matrix of agents
 */
Agent*** DataStorage::getMatrix() const {
	return _matrix;
}

/**
 * Delete an Agent of the game
 * @param ag An Agent to delete.
 * @exception TO DO
 */
void DataStorage::destroyAgent(Agent *ag)
{
    //std::cout << "Agent " << ag->toString() << " was killed" << std::endl;
    
    std::vector<Agent *>::iterator it = _agents.begin();
    bool end = false;
    
    while (it != _agents.end() && !end)
    {
        if (*it == ag)
        {
            _matrix[ag->getCoordinate().x][ag->getCoordinate().y] = NULL;
            it = _agents.erase(it);
            _num_of_deaths++;
            end = true;
        }
        else
        {
            it++;
        }
    }

}

/**
 * Check if two agents can make love and give birth.
 * @param mother the mother of the new child.
 * @param x the x-coordinate of the new child.
 * @param y the y-coordinate of the new child.
 */
void DataStorage::giveBirth(Agent * mother, int x, int y)
{
    Agent * child;
    
    child = mother->giveBirth(x, y);
    
    if (child->toString() == "Ag")
    {
        std::cout << "ERREUR" << std::endl;
    }
    else if (!_matrix[x][y])
    {
        _num_of_births++;
        _agents.push_back(child);
        _matrix[x][y] = child;
    }
    else
    {
        //TODO
    }
}

/**
 * Add one year for all population
 */
void DataStorage::ageingPopulation()
{
    for (std::vector<Agent*>::iterator it = _agents.begin();
         it != _agents.end(); ++it)
    {
        (*it)->addAge();
    }
}

/**
 * Check if an agent can move and move it.
 * @param Agent* An agent to move.
 * @param x The x-coordinate of the new location of the agent.
 * @param y The y-coordinate of the new location of the agent.
 */
bool DataStorage::moveAgent(Agent * ag, int x, int y)
{
    bool deplace = false;
    
	if (!_matrix[x][y])
	{
		_matrix[ag->getCoordinate().x][ag->getCoordinate().y] = NULL;
		ag->setCoordinate(x, y);
		_matrix[x][y] = ag;
        deplace = true;
    }
    else
    {
        //std::cout << "Agent " << ag->toString() << " can't move !" << std::endl;
    }
    
    return deplace;
}

void DataStorage::deathTime()
{
    std::vector<Agent*>::iterator it = _agents.begin();

    while (it != _agents.end())
    {
        if ((*it)->getAge() >= Agent::AVERAGE_LIFETIME)
        {
            _matrix[(*it)->getCoordinate().x][(*it)->getCoordinate().y] = NULL;
            it = _agents.erase(it);
            _num_of_deaths++;
        }
        else
        {
            ++it;
        }
    }
}