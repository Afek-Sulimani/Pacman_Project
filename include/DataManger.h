#pragma once
#include <SFML/Graphics.hpp>
#include "Cookie.h"
#include "Demon.h"
#include "Door.h"
#include "Key.h"
#include "Pacman.h"
#include "Present.h"
#include "Wall.h"
#include <SFML/Audio.hpp>
#include "GameTexture.h"
#include "musicManager.h"
#include "TimeManager.h"

enum LevelType
{
	CURRENT_LEVEL = 0,
	NEXT_LEVEL = 1,
	RESET_LEVEL = 2
};

class DataManger
{
public:
	static DataManger& instence();
	DataManger(const DataManger&) = delete;
	void operator=(const DataManger&) = delete;
	void LoadObj();
	GameTexture& getGameTexture();
	MusicManager& getGameMusic();
	TimeManager& getTime();
	void setString();
	void initDataRow();
	void drawText(sf::RenderWindow& window) ;
	void addToScore(int howMuch);
	void diedOnce();
	void LevelUp();
	bool playerWon() const ;
	void addCookie();
	void decCookie();
	int getNumOfCookie() const;
	int getLives() const;
	sf::Vector2f getPacmanPosition() const;
	void updatePacmanPosition(const sf::Vector2f& position);
	sf::Vector2f getLastDataPosition() const;
	void addLive();
	void setWindowPosition(const sf::Vector2i& position);
	sf::Vector2i getWindowPosition() const;
	bool timeGone();
	void setNumOfLevels(int num);

private: 
	DataManger() ;
	GameTexture m_textures;
	MusicManager m_music;
	TimeManager m_time;
	int m_playerScore;
	int m_level;
	int m_lives;
	int currentLeft_live;
	int numberOfCookie;
	int numOfLevels;
	sf::Vector2i m_windowPosition;
	sf::Text m_text;
	std::string m_informatiomString;
	sf::Sprite m_livesSprite;
	sf::Vector2f m_pacmanPosition;
};