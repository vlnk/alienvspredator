/**
 * Pattern strategy
 * @file DefensiveBehaviour.h
 * @author Laurent Valentin
 * @date 13/03/2014
 */

#ifndef __IBEHAVIOUR_HPP__
#define __IBEHAVIOUR_HPP__

#include <iostream>
#include "Movement.h"
#include "../Entity/Agent.hpp"
#include "../Logic/GameController.hpp"

/**
 * The interface IBehaviour for all behaviours.
 * @class IBehaviour
 * @author Valentin Laurent
 */
class IBehaviour
{
protected:
    int         _distance;  /**< The distance between the agent and the others.*/
    Movement&  _mvt;        /**< The mouvement of the agent during an action.*/
public:
    IBehaviour();
    virtual ~IBehaviour() = 0;
    virtual bool act(Agent *, Agent ***, int, int) = 0;
    
    const Movement& getMovement() const {return _mvt;}
};

#endif /*__IBEHAVIOUR_HPP__*/
