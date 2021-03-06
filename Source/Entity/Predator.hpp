/**
 * The Predator class
 * @file Predator.hpp
 * @author Valentin Laurent & Valentin Elvassore
 */

#ifndef PREDATOR_HPP
#define PREDATOR_HPP

#include "Agent.hpp"
#include "Human.hpp"
#include "Alien.hpp"

/**
 * The class Predator contains all methods for this specific Agent based on the superclass Agent.
 * @class Predator
 * @author Valentin Laurent
 */
class Predator : public Agent {

public:
    //Constructor
    Predator(int, int, int = 10, int = 18, int = 6);
    
    //Destructor
    ~Predator();
    
    //Display
	virtual std::string toString() const;
    
    //Methods
    void attack(Agent *);
    bool isSameType(Agent *);
    Predator* giveBirth(const int, const int);
    bool isPrey(Agent*);
    bool isFeared(Agent*);
};

#endif
