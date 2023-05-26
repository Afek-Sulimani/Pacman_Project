#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "GameObj.h"
#include "Pacmen.h"
#include "DataManger.h"
#include "menu.h"
class Controller
{
public:
	Controller();
	void run();

private:
	Menu m_menu;
	LevelType checkChangeLevel() const ;
	Board m_board;
	void initBoardObj(LevelType type);
	bool checkGameOver() ;
	bool changeLevel(LevelType type);
	bool transition() ;
	sf::RenderWindow m_window;
	sf::Sprite m_transitionSprite;
	float windowRowSize, windowColSize;
};