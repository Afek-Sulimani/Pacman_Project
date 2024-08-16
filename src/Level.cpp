#include "Level.h"

// level c-tor initilaize the private mebber
// open the playlist file that hold all the names 
// of the levels in the game
//----------------------------------------------
Level::Level()
	:m_gameSizeRow(0),
	 m_gameSizeCol(0),
	 LevelTime(0)
{
	m_playlist.open("Playlist.txt");
	int numOflevel ;
	m_playlist >> numOflevel;
	m_playlist.get();
	DataManger::instence().setNumOfLevels(numOflevel);
	srand((unsigned)time(NULL));
}

//Level D-tor will close all the file that not close
//-----------------------------------------------
Level::~Level()
{
	if (m_file.is_open())
		m_file.close();

	if (m_playlist.is_open())
		m_playlist.close();
}

// read the number of rows colomns 
// and time of the level if the level is witout time it read 0 
//-----------------------------------------------
void Level::readFromFile()
{
	if (m_file.is_open())// If the file exists
	{
		m_file >> m_gameSizeRow;
		m_file.get();
		m_file >> m_gameSizeCol;
		m_file.get();
		m_file >> LevelTime;
		m_file.get();	
	}
}

//read from the file all the characters
// and set all the parametrs for creating new borad 
//------------------------------------------------
bool Level::nextLevel(float& windowRow, float& windowCol)
{
//	checkEndingGame();
	setNextLevelName();
	if (m_file.is_open())
	{
		readFromFile(); //read the existing file		
		windowRow = m_gameSizeRow * 50;
		windowCol = m_gameSizeCol * 50;
		fillStr();
		m_file.close();
		return true;
	}
	return false;
}

//Fills the vector with all the characters in the file of the current level
//---------------------------------------------------
void Level::fillStr()
{
	m_boardStr.clear();
	m_boardStr.assign((unsigned)m_gameSizeRow, "" );
	for (size_t i = 0; i < m_gameSizeRow; i++)
	{
		std::string temp;
		getline(m_file, temp);
		m_boardStr[i] += temp;
	}
}

//Creates all objects of the board from the vectors
//and places them on the board
//update the vectors of the board class
//------------------------------------------------------------------------
void Level::fillFromStr(std::vector <std::unique_ptr<GameObj>>* objects,
				std::vector <std::unique_ptr<Demon>>* demons, Pacman& pacman)
{
	Location temp;
	DataManger::instence().getTime().setTime(LevelTime);// update the time limit of the level
	for (int i = 1; i < m_boardStr.size() - 1; i++)
	{
		for (int j = 1; j < m_boardStr[i].size() - 1; j++)
		{
			temp.row = i;
			temp.col = j;
			sf::Vector2f location = temp.getGlobal();
			char option = m_boardStr[i][j];
			if (option == ' ') // if no object
				continue;
			else if (option == DEMON)// if demon
				demons->push_back(std::make_unique<Demon>(location, DataManger::instence().getGameTexture().demon[rand() % 5]));

			else if (option == PACMAN)// if Pacman
				pacman.setPosition(location);

			else//if one of the static objects
				objects->push_back(createObject(location, option));
		}
	}
}

//calls the appropriate constructor according to the letter,
//and returns it into the vector
//-----------------------------------------------------------------
std::unique_ptr<GameObj> Level::createObject(const sf::Vector2f& location, char option)
{
	switch (option)
	{
	case COOKIE:
	{
		DataManger::instence().addCookie();
		return std::make_unique<Cookie>(location, DataManger::instence().getGameTexture().cookie);
	}
	case KEY: 
		return std::make_unique<Key>(location, DataManger::instence().getGameTexture().key);
	case DOOR: 
		return std::make_unique<Door>(location, DataManger::instence().getGameTexture().door);
	case PRESENT:
		return std::make_unique<Present>(location);
	case WALL: 
		return std::make_unique<Wall>(location, DataManger::instence().getGameTexture().wall);
	}
	return nullptr;
}

// check if the game is done 
//----------------------------------------------------------------------
void Level::checkEndingGame()
{
	if (DataManger::instence().playerWon())
	{
		m_file.close();
		m_playlist.close();
	}
}

// read from the playlist file the next level file name
//------------------------------------------------------------------------
void Level::setNextLevelName()
{
	if (m_playlist.is_open())
	{
		std::string temp;
		getline(m_playlist, temp);
		m_file.open(temp);
	}
	//else if (m_file.is_open())
	//	m_file.close();
}