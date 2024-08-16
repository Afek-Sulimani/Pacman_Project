#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "Backround.h"
#include "Pacman.h"
#include "Level.h"
#include <vector>
#include <memory>
#include "Demon.h"
#include <thread>
#include <chrono>
class Board
{
public:
	Board();
	void initBoard(float&, float&, LevelType type);
	void draw(sf::RenderWindow& window);
	void moveObj(const sf::Time& deltaTime);
	void changelevel();
private:
	void killAllDemons();
	void setDefualt();
	void deleteDoor();
	void handleCollisions(DynamicObj& gameObject);
	std::vector <std::unique_ptr<GameObj>> m_objects;
	std::vector <std::unique_ptr<Demon>> m_demons;
	Level m_level;
	Pacman m_player;
	Backround m_backround;
	float m_gameSizeRow;
	float m_gameSizeCol;
};