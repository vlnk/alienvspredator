/**
 * DataStorage.hpp
 *
 *  Created on: 11 janv. 2014
 *  Author: Valentin LAURENT & Valentin ELVASSORE
 */

#ifndef DATASTORAGE_HPP_
#define DATASTORAGE_HPP_

#include <cstddef>
#include "../Entity/Agent.hpp"
#include "../Entity/Human.hpp"
#include "../Entity/Predator.hpp"
#include "../Entity/Alien.hpp"
#include "../Logic/GameController.hpp"
#include <vector>
#include <iterator>


class GameController;

/**
 * The data storage manage all ressources used by the game controller.
 * @class DataStorage
 * @author Valentin Elvassor
 */
class DataStorage {
    
private:
	int         _width;             /**< The width of the matrix.*/
	int         _height;            /**< The height of the matrix.*/
	Agent ***   _matrix;            /**< The matrix of the game.*/
	std::vector<Agent *> _agents;   /**< The vector of Agents.*/

	void initMatrix();
    
    int         _num_of_deaths;      /**< The number of kills.*/
    int         _num_of_births;     /**< The number of births.*/

public:
    //Constructor
	DataStorage(int = 10, int = 20);
    
    //Destructor
	~DataStorage();
    
    //Getters
	const int& getHeight() const {return _height;}
    const int& getWidth() const {return _width;}
    Agent*** getMatrix() const;
    const std::vector<Agent*>& getAgents() const {return _agents;}
    Agent* getAgentAt(int) const;
    const int& getNumOfDeaths() const {return _num_of_deaths;}
    const int& getNumOfBirths() const {return _num_of_births;}
    
    //Setters
	void setHeight(int height);
	void setWidth(int width);
	void setAgents(const std::vector<Agent*> agents);
    
    //Methods
    void destroyAgent(Agent *);
    bool moveAgent(Agent *, int, int);
    
    void giveBirth(Agent *, int , int);
    void ageingPopulation();
    void deathTime();
    
    //Constants
	const static double PROPORTIONS_CUMULEES[4];
};

#endif /* DATASTORAGE_HPP_ */
