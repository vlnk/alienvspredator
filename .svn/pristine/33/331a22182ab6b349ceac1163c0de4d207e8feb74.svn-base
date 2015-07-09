/**
 * Management of the terminal presentation.
 * @file ConsolePresentation.cpp
 * @author Valentin Elvassor
 * @date 11/01/2014
 */

#include "ConsolePresentation.hpp"

//Constants initialization
const std::string ConsolePresentation::RESET = "\033[0m";
const std::string ConsolePresentation::BOLDYELLOW = "\033[1m\033[33m";
const std::string ConsolePresentation::BOLDRED = "\033[1m\033[31m";
const std::string ConsolePresentation::BOLDCYAN = "\033[1m\033[36m";

/**
 * ConsolePresentation constructor
 */
ConsolePresentation::ConsolePresentation():
    _setcolor(false)
{
}

/**
 * ConsolePresentation destructor
 */
ConsolePresentation::~ConsolePresentation() {
}

/**
 * Displayer of the matrix of Agents for each step.
 * @param **matrix the matrix of Agents.
 * @param width the width of the matrix.
 * @param heigth the heigth of the matrix.
 */
void ConsolePresentation::updateMatrixDisplay(Agent ***matrix, int width, int heigth)
{
	for (int i = 0 ; i < width ; ++i)
	{
		for (int j = 0 ; j < heigth ; ++j)
		{
			if (matrix[i][j])
            {
                if (_setcolor)
                {

                    if (matrix[i][j]->toString() == "A")
                    {
                        std::cout << BOLDRED << *matrix[i][j] << RESET << "\t";
                    }
                    else if (matrix[i][j]->toString() == "P")
                    {
                        std::cout << BOLDCYAN << *matrix[i][j] << RESET << "\t";
                    }
                    else
                    {
                        std::cout << BOLDYELLOW << *matrix[i][j] << RESET << "\t";
                    }
                }
                else
                {
                    std::cout << *matrix[i][j] << "\t";
                }
				
            }
			else
            {
				std::cout << "." << "\t";
            }
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void ConsolePresentation::displayNumberOfAgents(int num_of_agents, int num_of_iterations)
{
    std::cout << num_of_iterations << ") Number of agents : " << num_of_agents << std::endl << std::endl;
}

void ConsolePresentation::displayLogs(int num_of_agents, int num_of_deaths, int num_of_births, int num_of_iterations)
{
    std::cout << "Number of agents : " << num_of_agents << std::endl;
    std::cout << "Number of deaths : " << num_of_deaths << std::endl;
    std::cout << "Number of births : " << num_of_births << std::endl;
    std::cout << "Number of iterations : " << num_of_iterations << std::endl;
}

void ConsolePresentation::setColors(bool setcolor)
{
    _setcolor = setcolor;
}
