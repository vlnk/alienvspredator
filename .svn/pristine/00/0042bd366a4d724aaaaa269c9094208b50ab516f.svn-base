/**
 * Define the courtship behaviour of agents, when an agent whant to make love.
 * @file CourtshipBehaviour.h
 * @author Laurent Valentin
 * @date 13/03/2014
 */

#ifndef __COURTSHIPBEHAVIOUR_HPP__
#define __COURTSHIPBEHAVIOUR_HPP__

#include <iostream>
#include <boost/signals2.hpp>
#include "IBehaviour.h"

/**
 * The courtship behaviour for each agent.
 * @class CourtshipBehaviour
 * @author Valentin Laurent
 */
class CourtshipBehaviour : public IBehaviour
{
public:
    //Constructor
    CourtshipBehaviour();
    
    //Destructor
    ~CourtshipBehaviour(){};    /**<Courtship behaviour destructor.*/
    
    //Signal
    boost::signals2::signal<void (Agent *, int, int)> loveSig;  /**<A signal to the DataStorage in order to give a birth to a new agent.*/
    
    //Methods
    bool love(Agent *, Agent ***, int, int, int);
    Movement::move_t findLove(Agent*, Agent***, int, int);
    void makeLove(Agent *, int, int);
    bool act(Agent *, Agent ***, int, int);
    
};

#endif /*__COURTSHIPBEHAVIOUR_HPP__*/
