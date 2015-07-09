/**
 * Management of the terminal presentation (header).
 * @file ConsolePresentation.hpp
 * @author Valentin Elvassor
 * @date 11/01/2014
 */

#ifndef CONSOLEPRESENTATION_HPP_
#define CONSOLEPRESENTATION_HPP_

#include <iostream>
#include "../Entity/Agent.hpp"

/**
 * The class ConsolePresentation describes all methodes to display the game.
 * @class ConsolePresentation
 * @author Valentin Elvassor
 */
class ConsolePresentation
{
private:
    bool    _setcolor;  /**< Set the terminal coloration.*/
    
public:
    //Constructor
	ConsolePresentation();
    
    //Destructor
	virtual ~ConsolePresentation();
    
    //Methods
    void updateMatrixDisplay(Agent ***, int, int);
    void displayNumberOfAgents(int, int);
    void displayLogs(int, int, int, int);
                         
    //Setters
    void setColors(bool);
    
    //Constants
    const static std::string RESET;
    const static std::string BOLDYELLOW;
    const static std::string BOLDRED;
    const static std::string BOLDCYAN;
};

#endif /* CONSOLEPRESENTATION_HPP_ */
