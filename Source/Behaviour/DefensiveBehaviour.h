/**
 * Define the defenssive behaviour of agents, when an agent whant to avoid fights.
 * @file DefensiveBehaviour.h
 * @author Laurent Valentin
 * @date 13/03/2014
 */

#ifndef __DEFENSIVEBEHAVIOUR_HPP__
#define __DEFENSIVEBEHAVIOUR_HPP__

#include <iostream>
#include "IBehaviour.h"

/**
 * The defensive behaviour for each agent.
 * @class DefensiveBehaviour
 * @author Valentin Laurent
 */
class DefensiveBehaviour : public IBehaviour
{
public:
    //Constructor
    DefensiveBehaviour();
    
    //Destructor
    ~DefensiveBehaviour(){};    /**< The DefensiveBehaviour destructor*/
    
    bool act(Agent *, Agent ***, int, int);
    Movement::move_t flee(Agent *, Agent ***, int, int);
};

#endif /*__DEFENSIVEBEHAVIOUR_HPP__*/