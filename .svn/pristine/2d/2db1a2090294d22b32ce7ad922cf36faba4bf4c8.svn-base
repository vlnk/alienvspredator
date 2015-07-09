/**
 * Make a movement for each Agent
 * @file Movement.h
 * @author Valentin Laurent
 * @date 13/03/2014
 */

#ifndef __MOVEMENT_H__
#define __MOVEMENT_H__

#include <iostream>
#include <boost/signals2.hpp>
#include "../Entity/Alien.hpp"

/**
 * The movement class for each agent.
 * @class Movement
 * @author Valentin Laurent
 */
class Movement
{
public:
    //Typedef
    typedef boost::signals2::signal<bool (Agent *, int, int)> MoveSignal;
    
    //Constructor
    Movement(){};   /**< The mouvement constructor.*/
    
    //Destructor
    ~Movement(){};  /**< The mouvement destructor.*/
    
    //Methods
    bool move(Agent *, int, int, int);
    bool move(Agent *, int, int);
    void addMoveSignal(const MoveSignal::slot_type& slot) const;
    
    //Enumeration
    enum move_t { UP, RIGHT, DOWN, LEFT, NOWHERE }; /**< move_t An enumeration of all directions that an agent can take.*/
    
    //Constante
    static const int NUM_OF_DIRECTIONS = 4; /**< The number of directions that an agent can take.*/
    
private:
    //Signal
    mutable MoveSignal _moveSig;
};

#endif /*__MOVEMENT_H__*/
