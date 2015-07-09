/**
 * Define the courtship behaviour of agents, when an agent whant to make love.
 * @file CourtshipBehaviour.cpp
 * @author Laurent Valentin
 * @date 13/03/2014
 */

#include "CourtshipBehaviour.h"

/**
 * Courtship behaviour constructor.
 */
CourtshipBehaviour::CourtshipBehaviour()
{
}

/**
 * Help the agent to find its soulmate.
 * @param ag The agent in love.
 * @param cpy_matrix The matrix of agents (copy).
 * @param width The width of the matrix.
 * @param height The height of the matrix.
 */
Movement::move_t CourtshipBehaviour::findLove(Agent* ag, Agent*** cpy_matrix, int width, int height)
{
    int     direction = 0;
    bool    find = false;
    bool    end = false;
    int     x = ag->getCoordinate().x;
    int     y = ag->getCoordinate().y;
    
    do
    {
        switch (direction) {
            case Movement::UP:
                if ((x > (_distance - 1)) &&
                    (cpy_matrix[x - _distance][y]))
                {
                    find = ag->isSameType(cpy_matrix[x - _distance][y]);
                }
                break;
            case Movement::RIGHT:
                if ((y < height - _distance) &&
                    (cpy_matrix[x][y + _distance]))
                {
                    find = ag->isSameType(cpy_matrix[x][y + _distance]);
                }
                break;
            case Movement::DOWN:
                if ((x < width - _distance) &&
                    (cpy_matrix[x + this->_distance][y]))
                {
                    find = ag->isSameType(cpy_matrix[x + _distance][y]);
                }
                break;
            default:
                if ((y > (this->_distance - 1)) &&
                    (cpy_matrix[x][y - _distance]))
                {
                    find = ag->isSameType(cpy_matrix[x][y - _distance]);
                }
                break;
        }
        
        if (!find)
        {
            direction = (direction + 1) % Movement::NUM_OF_DIRECTIONS;
            
            if (direction == 0)
            {
                _distance++;
            }
        }
        
        if (_distance > width ||
            _distance > height ||
            _distance > ag->getFieldOfVision())
        {
            end = true;
        }
        
    } while (!find && !end);
    
    if (end && !find)
    {
        direction = Movement::NOWHERE;
    }
    
    return (Movement::move_t)direction;
}

/**
 * A coutship between two Agents.
 * @param mother The Agent who make a child.
 * @param cpy_matrix A copy of the field.
 * @param width The width of the matrix.
 * @param height The height of the matrix.
 * @return A boolean if the courtship is succed or failed.
 */
bool CourtshipBehaviour::love(Agent * mother, Agent *** cpy_matrix, int width, int height, int direction)
{
    bool    end_loving = false;
    bool    end = false;
    bool    find_empty_place = false;
    int     x_empty = -1;
    int     y_empty = -1;
    Agent * father = NULL;
    int     x = mother->getCoordinate().x;
    int     y = mother->getCoordinate().y;
    
    
    do
    {
        end_loving = false;
        find_empty_place = false;
        
        switch (direction) {
            case Movement::UP:
                if ((x > 0) && (cpy_matrix[x - 1][y]))
                {
                    father = cpy_matrix[x - 1][y];
                }
                else if ((x > 0) && (!cpy_matrix[x - 1][y]))
                {
                    find_empty_place = true;
                    x_empty = x - 1;
                    y_empty = y;
                }
                break;
            case Movement::RIGHT:
                if ((y < height - 1) && (cpy_matrix[x][y + 1]))
                {
                    father = cpy_matrix[x][y + 1];
                }
                else if ((y < width - 1) && (!cpy_matrix[x][y + 1]))
                {
                    find_empty_place = true;
                    x_empty = x;
                    y_empty = y + 1;
                }
                break;
            case Movement::DOWN:
                if ((x < width - 1) && (cpy_matrix[x + 1][y]))
                {
                    father = cpy_matrix[x + 1][y];
                }
                else if ((x < width - 1) && (!cpy_matrix[x + 1][y]))
                {
                    find_empty_place = true;
                    x_empty = x + 1;
                    y_empty = y;
                }
                break;
            case Movement::LEFT:
                if ((y > 0) && (cpy_matrix[x][y - 1]))
                {
                    father = cpy_matrix[x][y - 1];
                }
                else if ((y > 0) && (!cpy_matrix[x][y - 1]))
                {
                    find_empty_place = true;
                    x_empty = x;
                    y_empty = y - 1;
                }
                break;
            default:
                end = true;
                break;
        }
        
        if (father && mother->isSameType(father) &&
            mother->getAge() > Agent::SEXUAL_MAJORITY)
        {
            end_loving = true;
        }
        
        direction = (Movement::move_t)(direction + 1);
        
    } while (!end && !(find_empty_place && end_loving));
    
    if (find_empty_place && end_loving && (x_empty > 0) && (y_empty > 0))
    {
        makeLove(mother, x_empty, y_empty);
    }
    
    return (!find_empty_place) && (!end_loving);
}

/**
 * Send the signal to the DataStorage for creation of an agent.
 * @param ag The mother of the new agent.
 * @param x The x-coordonate of the new agent.
 * @param y The y-coordonate of the new agent.
 */
void CourtshipBehaviour::makeLove(Agent * mother, int x, int y)
{
    loveSig(mother, x, y);
}

/**
 * The agent in love do everything to meet its soulmate.
 * @param ag The agent in love.
 * @param cpy_matrix The matrix of agents.
 * @param width The width of the matrix.
 * @param height The height of the matrix.
 * @return A boolean which check if the agent success to fo find its soulmate.
 */
bool CourtshipBehaviour::act(Agent * ag, Agent *** cpy_matrix, int width, int height)
{
    int direction = findLove(ag, cpy_matrix, width, height);
    bool achieve = false;
    
    
    if (direction == Movement::NOWHERE)
    {
        achieve = _mvt.move(ag, width, height, round(
            GameController::getInstance()->getRandom(0,3)));
    }
    else if (_distance > 1)
    {
        achieve = _mvt.move(ag, width, height, direction);
    }
    else
    {
        love(ag, cpy_matrix, width, height, direction);
        achieve = true;
    }
    
    _distance = 1;
    
    return achieve;
}