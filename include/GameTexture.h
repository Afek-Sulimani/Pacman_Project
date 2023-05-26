#pragma once
#include <SFML/Graphics.hpp>
struct GameTexture
{
	sf::Texture demon[5];
	sf::Texture cookie;
	sf::Texture present; //live 
	sf::Texture present1;// kill demon
	sf::Texture present2;// time
	sf::Texture present3;// superpacmen 
	sf::Texture key;
	sf::Texture door;
	sf::Texture wall;
	sf::Texture upperRow;
	sf::Texture bottomRow;
	sf::Texture leftRow;
	sf::Texture rightRow;
	sf::Texture gameBackround;
	sf::Texture upperBlock;
	sf::Texture bottoBlock;
	sf::Texture pcamen;
	sf::Texture superPacmen;
	sf::Texture pacmen;
	sf::Font font;
	sf::Texture hearts;
	sf::Texture dash;
	sf::Texture superPacmenBar;
	sf::Texture transitionBoard;
	sf::Texture byebyeBoard;
	sf::Texture menu;
	sf::Texture wonBoard;
	sf::Texture timeGoneBoard;
	void loadTexture();
};
//-------------------------------------------
