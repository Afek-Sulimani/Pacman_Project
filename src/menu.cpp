#include "menu.h"

/* constractor to menu, will call sfml constractors
   to init the objects.
*/
//--------------------------------------------
Menu::Menu()
	:m_SpriteRect(0, 0, 600, 600),
	m_informationMode(false),
	m_StartGame(sf::Vector2f(170, 70)),
	m_Help(sf::Vector2f(260, 55)),
	m_exit(sf::Vector2f(120, 55))

{}
/*
* init menu: will recive the window size and will build the object
* accordingly, will also set the texture of the menu sprite
*/
//---------------------------------------------
void Menu::initMenu(const sf::Vector2u& windowSize)
{
	sf::Vector2f startOfSprite;
	m_menuSprite.setTexture(DataManger::instence().getGameTexture().menu);
	m_menuSprite.setTextureRect(m_SpriteRect);
	m_menuSprite.setPosition(windowSize.x / 2.f, windowSize.y / 2.f);
	startOfSprite = m_menuSprite.getPosition();
	m_menuSprite.setOrigin(sf::Vector2f(m_menuSprite.getLocalBounds().left +
		m_menuSprite.getLocalBounds().width / 2u,
		m_menuSprite.getLocalBounds().height / 2u));
	m_StartGame.setPosition(startOfSprite.x - 70, startOfSprite.y - 155); 
	m_Help.setPosition(startOfSprite.x - 130, startOfSprite.y - 45);
	m_exit.setPosition(startOfSprite.x - 55 , startOfSprite.y + 60);
}

/*
* this will be the main function of the menu, will run in a loop
* until gets from user he wants to start the game.
* will return if the game was exited
*/
//--------------------------------------
bool Menu::runMenu(sf::RenderWindow& window)
{
	DataManger::instence().getGameMusic().startTrasitionMusic();
	while (true)
	{
		window.clear();
		draw(window);
		if (auto event = sf::Event{}; window.waitEvent(event))
		{

			if (event.type == sf::Event::Closed) //close the window
			{
				window.close();
				return false;
			}
			else if (event.type == sf::Event::MouseButtonReleased)
			{
				auto location = window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });
				if (!m_informationMode)
				{
					if (handleClick(location, window)) //the player wants to start/exit
						return true;
				}
				else
					handleClickInformation(); //if the player is wants to move
			}								// to the next page in the instructions

		}
		window.display();
	}
	return true;
}
// will draw the menu
//--------------------------------------
void Menu::draw(sf::RenderWindow& window)
{
	window.draw(m_menuSprite);
}
// this function will handle the player clicks on the window and 
// act accordenly
//---------------------------------------
bool Menu::handleClick(const sf::Vector2f& location, sf::RenderWindow& window)
{
	if (m_exit.getGlobalBounds().contains(location)) //want to exit
	{
		window.close();
		return true;
	}
	else if (m_StartGame.getGlobalBounds().contains(location)) //wants to start
		return true;
	else if (m_Help.getGlobalBounds().contains(location))
	{
		m_informationMode = true;
		handleClickInformation();
		return false;
	}
	return false;
}
// this function will handle the player clicks on the help
// botton and wants to know how to play
//--------------------------------------------------
void Menu::handleClickInformation()
{
	if (m_SpriteRect.left == 3600) //return to the menu
	{
		m_informationMode = false;
		m_SpriteRect.left = 0;
	}
	else
		m_SpriteRect.left += 600; //move to the next page
	m_menuSprite.setTextureRect(m_SpriteRect);
}