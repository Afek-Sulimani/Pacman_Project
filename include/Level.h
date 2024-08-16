#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "GameObj.h"
#include "Location.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include "DataManger.h"

enum ObjType
{
	COOKIE = '*', 
	DEMON = '&',
	PACMAN = 'a',
	DOOR = 'D',
	PRESENT = '$',
	KEY = '%',
	WALL ='#'
};

class Level
{
public:
	Level();
	~Level();
	bool nextLevel(float& winsowRow, float& windowCol);
	void fillFromStr(std::vector <std::unique_ptr<GameObj>>* objects,
				std::vector <std::unique_ptr<Demon>>* demons, Pacman& pacman);
private:
	void fillStr();
	std::unique_ptr<GameObj> createObject(const sf::Vector2f& location, char option);
	std::ifstream m_file;
	std::ifstream m_playlist;
	void readFromFile();
	std::vector <std::string> m_boardStr;
	float m_gameSizeRow;
	float m_gameSizeCol;
	void checkEndingGame();
	void setNextLevelName() ;
	int LevelTime;
};
//-----------------------------------------------------