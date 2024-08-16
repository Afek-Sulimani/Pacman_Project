#include "DataManger.h"

//the main func of this singleton class 
// will called to the c-tor only once,
// only from this func we can manage the data
//--------------------------------------
DataManger& DataManger::instence()
{
	static auto manger = DataManger();
	return manger;
}

// data manager c-tor will operat once from instance static func 
//-------------------------------------
DataManger::DataManger()
	:m_lives(3),
	m_level(1),
	m_playerScore(0),
	numberOfCookie(0),
	currentLeft_live(0),
	m_time(),
	numOfLevels(3)
{}

//loading all the texture and music of the game
//--------------------------------------
void DataManger::LoadObj()
{
	m_textures.loadTexture();
	m_music.initMusic();
}

//Initializes all variables of the info row
//----------------------------------------------
void DataManger::initDataRow()
{
	m_livesSprite.setTexture(m_textures.hearts);
	m_livesSprite.setTextureRect(sf::IntRect(0, 0, 100, 50));
	m_text.setFont(DataManger::instence().m_textures.font);
	m_text.setFillColor(sf::Color::Black);
	m_text.setPosition(sf::Vector2f(10, 10));
}

//Draws the data of the data line on the board
//--------------------------------------------
void DataManger::drawText(sf::RenderWindow& window)
{
	m_livesSprite.setPosition(m_text.getGlobalBounds().width + 10, 5);
	setString();
	m_text.setString(m_informatiomString);
	window.draw(m_livesSprite);
	window.draw(m_text);
}

//Updates the data string to be displayed in the info row
//--------------------------------------------
void DataManger::setString()
{
	m_informatiomString = "Level:  " + std::to_string(m_level)
		+ "   score:  " + std::to_string(m_playerScore) +
		"   Time:  " + m_time.getString() + "   lives: ";
}

// when the player ate all the cookies 
//------------------------------------------
void DataManger::LevelUp()
{
	m_level++;
}

//update the player score for row info
//---------------------------------------------
void DataManger::addToScore(int howMuch)
{
	m_playerScore += howMuch;
}

//when the player died need to sub live 
//------------------------------------------
void DataManger::diedOnce()
{
	currentLeft_live += 100;
	m_lives--;
	m_livesSprite.setTextureRect(sf::IntRect(currentLeft_live,0, 100, 50));
}

// return the curren number of lives
//------------------------------------------
int DataManger::getLives() const
{
	return m_lives;
}

// when the player collide with add live present
//----------------------------------------------
void DataManger::addLive()
{
	if (m_lives < 3)
	{
		m_lives++;
		currentLeft_live -= 100;
		m_livesSprite.setTextureRect(sf::IntRect(currentLeft_live,0, 100, 50));
	}
}

//add to the number of cookie when creat a objects from level file.
//-----------------------------------------------
void DataManger::addCookie()
{
	numberOfCookie ++;
}

// dec num of cookie when player it one
//------------------------------------------------
void DataManger::decCookie()
{
	numberOfCookie --;
}

// return the number of cookie for knowing if need to up for next level
//-----------------------------------------------
int DataManger::getNumOfCookie() const
{
	return numberOfCookie;
}

// update the num of levels
//----------------------------------------------
void DataManger::setNumOfLevels(int num )
{
	numOfLevels = num;
};

// return true if the player finished all the levels 
//-----------------------------------------------
bool DataManger::playerWon() const
{
	if(m_level > numOfLevels)
		return true;
	return false;
}

// return the pacman position for smart demons
//-----------------------------------------------
sf::Vector2f DataManger::getPacmanPosition() const
{
	return m_pacmanPosition;
}

//-----------------------------------------------
void DataManger::updatePacmanPosition(const sf::Vector2f& position)
{
	m_pacmanPosition = position;
}

//return the position of rectangle of live animation
//------------------------------------------------
sf::Vector2f DataManger::getLastDataPosition() const
{
	return sf::Vector2f(m_livesSprite.getGlobalBounds().left + m_livesSprite.getGlobalBounds().width,
						m_livesSprite.getGlobalBounds().top);
}

//--------------------------------------------------
void DataManger::setWindowPosition(const sf::Vector2i& position)
{
	m_windowPosition = position;
}
//----------------------------------
sf::Vector2i DataManger::getWindowPosition() const
{
	return m_windowPosition;
}

//Allows to access the texture of the game
// from the class that manages them
//----------------------------------
GameTexture& DataManger::getGameTexture()
{
	return m_textures;
}

//Allows to access the musics of the game
// from the class that manages them
//-----------------------------------
MusicManager& DataManger::getGameMusic()
{
	return m_music;
}

//Allows to access the time of the game
// from the class that manages it
//------------------------------------
TimeManager& DataManger::getTime()
{
	return m_time;
}

//when this is level with time and the clock finish 
//-------------------------------------
bool DataManger::timeGone()
{
	if (m_time.timeGone())
	{
		numberOfCookie = 0;
		return true;
	}
	return false;
}
