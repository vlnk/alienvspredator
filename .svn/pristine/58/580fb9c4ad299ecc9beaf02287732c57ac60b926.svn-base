/**
 * The Alien class
 * @file Alien.hpp
 * @author Valentin Laurent & Valentin Elvassore
 */

#ifndef ALIEN_HPP
#define ALIEN_HPP

#include "Agent.hpp"
#include "Human.hpp"
#include "Predator.hpp"

/**
 * The class Alien contains all methods for this specific Agent based on the superclass Agent.
 * @class Alien
 * @author Valentin Laurent
 */
class Alien : public Agent {
    
public:
    //Constructor
    Alien(int, int, int = 10, int = 16, int = 4);
    
    //Destructor
    ~Alien();
    
    //Display
    std::string toString() const;
    
    //Methods
    void attack(Agent *);
    Alien* giveBirth(const int,const int);
    bool isSameType(Agent*);
    bool isPrey(Agent*);
    bool isFeared(Agent*);
};

#endif
