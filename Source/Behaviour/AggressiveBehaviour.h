/**
 * Define the aggressive behaviour of agents, when an agent whant to fight.
 * @file AggressiveBehaviour.h
 * @author Laurent Valentin
 * @date 13/03/2014
 */

#ifndef __AGGRESSIVEBEHAVIOUR_HPP__
#define __AGGRESSIVEBEHAVIOUR_HPP__

#include <iostream>
#include <boost/signals2.hpp>
#include "IBehaviour.h"

/**
 * The aggressive behaviour for the agents.
 * @class AggressiveBehaviour
 * @author Valentin Laurent
 */
class AggressiveBehaviour : public IBehaviour
{
public:
    //Constructor
    AggressiveBehaviour();
    
    //Destructor
    ~AggressiveBehaviour(){};
    
    //Signal
    boost::signals2::signal<void (Agent *)> killSig;    /**<A signal to the DataStorage for deleting an agent.*/
    
    //Methods
    bool act(Agent *, Agent ***, int, int);
    bool attack(Agent *, Agent ***, int, int, int = 0);
    Movement::move_t findPrey(Agent *, Agent ***, int, int);
    
    void killAgent(Agent * ag) { killSig(ag); }         /**Send the signal to erase an agent.*/
};

#endif /*__AGGRESSIVEBEHAVIOUR_HPP__*/
