#pragma once
#include <SFML/Graphics.hpp>
#include "DataManger.h"

class Menu
{
public:
	Menu();
	void initMenu(const sf::Vector2u& windowSize);
	bool runMenu(sf::RenderWindow& window);
private:
	bool handleClick(const sf::Vector2f& location, sf::RenderWindow& window);
	void handleClickInformation();
	void draw(sf::RenderWindow& window);
	bool m_informationMode;
	sf::Sprite m_menuSprite;
	sf::RectangleShape m_StartGame;
	sf::RectangleShape m_Help;
	sf::RectangleShape m_exit;
	sf::IntRect m_SpriteRect;
};