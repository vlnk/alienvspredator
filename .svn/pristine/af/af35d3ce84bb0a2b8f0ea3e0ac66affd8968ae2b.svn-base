/**
 * The Agent class
 * @file Agent.hpp
 * @author Valentin Laurent & Valentin Elvassore
 */

#ifndef AGENT_HPP
#define AGENT_HPP

#include "coordinate.h"
#include <ostream>

class IBehaviour;
class DataStorage;

/**
 * The class Agent contains all virtual methods for each specific Agent (Alien, Human, Predator).
 * @class Agent
 * @author Valentin Laurent
 */
class Agent {
    
private:
	coordinate_t _coordinate;   /**< The position coordonates of the Agent.*/
    
protected:
    int _lifespan;              /**< The lifespan of the agent.*/
    int _age;                   /**< The age of the agent.*/
    int _field_of_vision;         /**< The field of vision of the agent.*/
    IBehaviour * _behaviour;    /**< Pointer on the behaviour of the agent.*/
    
public:
	//Constructor
	Agent(int, int, int, int, int);
	
	//Destructor
	virtual ~Agent() = 0;
	
    //Accessors
	const coordinate_t& getCoordinate() const {return _coordinate;}
	void setCoordinate(int, int);
    const int& getLifespan() const {return _lifespan;};
    void setLifespan(const int lifespan);
	virtual std::string toString() const;
    const int& getAge() const {return _age;}
    const int& getFieldOfVision() const {return _field_of_vision;}
    const IBehaviour * getBehaviour() const {return _behaviour;}
    
    //Methods
    virtual void attack(Agent *) = 0;
    virtual Agent* giveBirth(const int,const int) = 0;
    virtual bool isSameType(Agent*) = 0;
    void addAge();
    virtual bool isPrey(Agent*) = 0;
    virtual bool isFeared(Agent*) = 0;
    
    bool act(Agent***, int, int);
    void changeBehaviour(IBehaviour *);
    
    //Constante
    const static int SEXUAL_MAJORITY = 15;  /**< The sexual majority for each agent (the cannot make love before)*/
    const static int AVERAGE_LIFETIME = 30; /**< The average lifetime of each agent (to initialize their lifespan)*/
};

std::ostream& operator<<(std::ostream &, Agent const&);

#endif
