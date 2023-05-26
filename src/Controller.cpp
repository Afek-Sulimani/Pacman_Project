#include "Controller.h"

Controller::Controller()
    :windowColSize(0),
     windowRowSize(0)
{}


// This func manage the main loop of the game.
// the func will start and stop the time of the game,
// call to the move func of the board,
// call to the draw func of the board.
// will check tge status of the game.
//--------------------------------------
void Controller::run()
{
    m_transitionSprite.setTexture(DataManger::instence().getGameTexture().transitionBoard);
    initBoardObj(NEXT_LEVEL);
    m_window.setFramerateLimit(60);
    m_menu.initMenu(m_window.getSize());
    if (!m_menu.runMenu(m_window))// if user press exit .
        return;
    DataManger::instence().getGameMusic().stopTransitionMusic();
    DataManger::instence().getGameMusic().startGameMusic();
    sf::Clock clock;
    while (m_window.isOpen())
    {
        m_window.clear();
        m_board.draw(m_window);
        m_window.display();
        sf::Time elapsd = clock.getElapsedTime();
        m_board.moveObj(elapsd);
        if (checkGameOver())
            break;
        LevelType type = checkChangeLevel();
        if(type != CURRENT_LEVEL) // if need to change level or reset  
        {
            if (!changeLevel(type))
                break ;
            m_window.setFramerateLimit(60);
            type = CURRENT_LEVEL;
            clock.restart();
            continue;
        }
        for (auto event = sf::Event{}; m_window.pollEvent(event);)
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            }
        }
        if (elapsd.asSeconds() > 0.1)
            clock.restart();
    }
}

// initilaize the window 
//------------------------------------------------------------------------------
void Controller::initBoardObj(LevelType type)
{
	m_board.initBoard(windowRowSize, windowColSize, type);
    m_window.clear();
    m_window.create(sf::VideoMode((unsigned)windowColSize, (unsigned)windowRowSize), "window");
    DataManger::instence().setWindowPosition(m_window.getPosition());
}

// check if the player died 3 times so the game is over
//-----------------------------------------------------------
bool Controller::checkGameOver()
{
    if (DataManger::instence().getLives() <= 0 )
    {
        m_transitionSprite.setTexture(DataManger::instence().getGameTexture().byebyeBoard);
        transition();
        return true;
    }
    return false;
}

// this func manage the transition texture between levels
// and play the music according the status
//--------------------------------------------------------
bool Controller::transition()
{
    DataManger::instence().getGameMusic().stopGameMusic();
    DataManger::instence().getGameMusic().startTrasitionMusic();
    m_transitionSprite.setTextureRect(sf::IntRect(0, 0, 900, 200));
    m_transitionSprite.setPosition(m_window.getSize().x / (float)2u, m_window.getSize().y / (float)2u);
    m_transitionSprite.setOrigin(sf::Vector2f(m_transitionSprite.getLocalBounds().left +
        m_transitionSprite.getLocalBounds().width / 2u,
        m_transitionSprite.getLocalBounds().height / 2u));
    int timeForSprite = 0;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    while (true)
    {
        timeForSprite++;
        if (timeForSprite >= 40)
            timeForSprite = 0;
        m_transitionSprite.setTextureRect(sf::IntRect(0, (timeForSprite / 10) * 200, 900, 200));
        m_window.clear();
        m_window.draw(m_transitionSprite);
        m_window.display();
        if (auto event = sf::Event{}; m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_window.close();
                return false;
            }
            else if ((event.type == sf::Event::MouseButtonReleased) ||
                (event.type == sf::Event::TextEntered))
                break;
        }
    }
    DataManger::instence().getGameMusic().stopTransitionMusic();
    DataManger::instence().getGameMusic().startGameMusic();

    return true;
}

//
//-------------------------------------------------------------
bool Controller::changeLevel(LevelType type)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    if (type == NEXT_LEVEL) // won the game
    {
        DataManger::instence().LevelUp();
        if (DataManger::instence().playerWon())
        {
            m_transitionSprite.setTexture(DataManger::instence().getGameTexture().wonBoard);
            DataManger::instence().getGameMusic().OpenWinMusic();
            transition();
            DataManger::instence().getGameMusic().stopGameMusic();
            DataManger::instence().getGameMusic().stopTransitionMusic();
            return false;
        }
        m_transitionSprite.setTexture(DataManger::instence().getGameTexture().transitionBoard);
    }
    else if (type == RESET_LEVEL)// the time is gone so reset the board.
        m_transitionSprite.setTexture(DataManger::instence().getGameTexture().timeGoneBoard);
        
    if(! transition())
        return false;
    m_board.changelevel();
    initBoardObj(type);
    return true;
}
//-----------------------------------------------------------
LevelType Controller::checkChangeLevel() const
{
    if ((DataManger::instence().getNumOfCookie()) <= 0)
        return NEXT_LEVEL;

    else if (DataManger::instence().timeGone())
        return RESET_LEVEL;
    else
        return CURRENT_LEVEL;
}