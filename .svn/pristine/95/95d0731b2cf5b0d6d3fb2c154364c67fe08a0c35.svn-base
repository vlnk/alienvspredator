/**
 * GameController.cpp
 *
 * Created on: 11 janv. 2014
 * Author: Vavou
 */

#include "GameController.hpp"
#include "../Behaviour/IBehaviour.h"
#include "../Behaviour/AggressiveBehaviour.h"
#include "../Behaviour/DefensiveBehaviour.h"
#include "../Behaviour/CourtshipBehaviour.h"

/**
 * Cumulative proportions for choosing actions of Agents
 */
const double GameController::PROPORTIONS_CUMULEES_BY_ACTIONS[3] = {0.4, 0.65, 1};

/**
 * Cumulative proportions for choosing between "go to the prey" and "flee the feared Agent"
 */
const double GameController::PROPORTIONS_CUMULEES_BY_DESIRE[2] = {0.7, 1};

/**
 * Initialization of the instance variable (for the singleton behaviour).
 */
GameController * GameController::_instance = NULL;

/**
 * GameControler contructor
 * @param width An integer to initialize the dimensions of the matrix
 * @param height An integer to initialize the dimensions of the matrix
 * @param seed The seed for the Random Generator Number.
 */
GameController::GameController(int width, int height, int seed):
    _data(*new DataStorage(width, height)),
    _presentation(*new ConsolePresentation()),
    _mt(*new MersenneTwister(seed)),
    _num_of_iterations(0)
{
    _cpy_matrix = new Agent**[_data.getWidth()];
    
    for (int i = 0; i < _data.getWidth(); ++i)
    {
        _cpy_matrix[i] = new Agent*[_data.getHeight()];
    }
}

/**
 * GameControler destructor
 */
GameController::~GameController()
{
    _presentation.updateMatrixDisplay(_data.getMatrix(), _data.getWidth(), _data.getHeight());
    _presentation.displayLogs(_data.getAgents().size(), _data.getNumOfDeaths(), _data.getNumOfBirths(), _num_of_iterations);
    
    for (int i = 0; i < _data.getWidth(); ++i)
    {
        delete [] _cpy_matrix[i];
        
    }
    
    delete [] _cpy_matrix;
    delete &_data;
    delete &_presentation;
    delete &_mt;
    
    std::cout << "good bye" << std::endl;
}

/**
 * Data getter
 * @return _data The initialized objects for the game.
 */
const DataStorage& GameController::getData() const
{
	return _data;
}

/**
 * Instance getter, check if GameControler is already instanciate.
 * @param width The width of the playing field.
 * @param height The height of the playing field.
 * @return *_instance A bool which check the instantiation.
 */
 GameController * GameController::getInstance(int width, int height)
{
	if (!_instance)
    {
        _instance = new GameController(width, height, (unsigned)time(NULL));
    }
	return _instance;
}

void GameController::destroyInstance()
{
    delete _instance;
    _instance = nullptr;
}

/**
 * Randomize actions while the game.
 * @param min An integer of the minimum value expected
 * @param max An integer of the maximum value expected
 * @return A random double between min and max values.
 */
double GameController::getRandom(double min, double max)
{
	return (_mt.genrand_real1() * (max-min) + min);
}

/**
 * Progress the game by moving all Agents.
 */
void GameController::progress()
{
	std::vector<Agent*> agentsNonTraites(_data.getAgents());
	int                 alea;
    int                 num_of_realized_actions;
    bool                succeed_action;
    double              random;
	Agent           *   currentAgent;
    
    copyOfMatrix();
    
    _presentation.updateMatrixDisplay(_data.getMatrix(), _data.getWidth(), _data.getHeight());
    _presentation.displayLogs(_data.getAgents().size(), _data.getNumOfDeaths(), _data.getNumOfBirths(), _num_of_iterations);

	while (!agentsNonTraites.empty())
	{
		alea = (int) getRandom(0, agentsNonTraites.size() -1);
		currentAgent = agentsNonTraites[alea];
		agentsNonTraites.erase(agentsNonTraites.begin()+alea);
        num_of_realized_actions = 0;
        
        do {
            random = getRandom();
            succeed_action = false;
            
            if (random < PROPORTIONS_CUMULEES_BY_ACTIONS[0])
            {
                DefensiveBehaviour * fugitive = new DefensiveBehaviour();
                currentAgent->changeBehaviour(fugitive);
                fugitive->getMovement().addMoveSignal(
                    boost::bind(&DataStorage::moveAgent,&_data,_1,_2,_3));
            }
            else if (random < PROPORTIONS_CUMULEES_BY_ACTIONS[1])
            {
                AggressiveBehaviour * mugger = new AggressiveBehaviour();
                currentAgent->changeBehaviour(mugger);
                mugger->killSig.connect(
                    boost::bind(&DataStorage::destroyAgent,&_data,_1));
                mugger->getMovement().addMoveSignal(
                    boost::bind(&DataStorage::moveAgent,&_data,_1,_2,_3));
                
            }
            else
            {
                CourtshipBehaviour * lover = new CourtshipBehaviour();
                currentAgent->changeBehaviour(lover);
                lover->loveSig.connect(
                    boost::bind(&DataStorage::giveBirth,&_data,_1,_2,_3));
                lover->getMovement().addMoveSignal(
                    boost::bind(&DataStorage::moveAgent,&_data,_1,_2,_3));
            }

            succeed_action = currentAgent->act(_cpy_matrix, _data.getWidth(), _data.getHeight());
            
            if (succeed_action)
            {
                num_of_realized_actions++;
            }

        } while (num_of_realized_actions < NUMBER_OF_ACTIONS);
	}
    
    _data.ageingPopulation();
    _data.deathTime();
    _num_of_iterations++;
    
}

/**
 * Configure presentation parameters.
 * @param setcolor Set the terminal coloration.
 */
void GameController::configurePresentation(bool setcolor)
{
    _presentation.setColors(setcolor);
}

/**
 * Copy the matrix of DataStorage
 * @return A copy of _matrix.
 */
void GameController::copyOfMatrix()
{
    for (int i = 0; i < _data.getWidth(); ++i)
    {
        for (int j = 0; j < _data.getHeight(); ++j)
        {
            _cpy_matrix[i][j] = _data.getMatrix()[i][j];
        }
    }
}


