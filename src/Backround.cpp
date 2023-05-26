#include "Backround.h"

// draw all the bounds sprite
//----------------------------------------------------
void Backround::draw(sf::RenderWindow& window)
{
	window.draw(m_items.m_GameBackround);
	for (int i = 0; i < m_items.m_leftrow.size(); i++)
		window.draw(m_items.m_leftrow[i]);
	for (int i = 0; i < m_items.m_lowerrow.size(); i++)
		window.draw(m_items.m_lowerrow[i]);
	for (int i = 0; i < m_items.m_rightrow.size(); i++)
		window.draw(m_items.m_rightrow[i]);
	for (int i = 0; i < m_items.m_upperow.size(); i++)
		window.draw(m_items.m_upperow[i]);
}

// Goes over the vectors and check was a callision with the object
//-------------------------------------------------------------
bool Backround::isCollideWithBounds(const DynamicObj& dynamicObj) const
{
	for (int i = 0; i < m_items.m_leftrow.size(); i++)
		if (m_items.m_leftrow[i].getGlobalBounds().intersects(dynamicObj.getSpriteGlobalBounds()))
			return true;
	for (int i = 0; i < m_items.m_lowerrow.size(); i++)
		if (m_items.m_lowerrow[i].getGlobalBounds().intersects(dynamicObj.getSpriteGlobalBounds()))
			return true;
	for (int i = 0; i < m_items.m_rightrow.size(); i++)
		if (m_items.m_rightrow[i].getGlobalBounds().intersects(dynamicObj.getSpriteGlobalBounds()))
			return true;
	for (int i = 0; i < m_items.m_upperow.size(); i++)
		if (m_items.m_upperow[i].getGlobalBounds().intersects(dynamicObj.getSpriteGlobalBounds()))
			return true;
	return false;
}

// this func insert into the vectors the sprite of the bounding 
// that can limit the window follow the sizes that read from the files  
//----------------------------------------------------
void Backround::initBackRound(float size_col, float size_row)
{
	clearBackRound();
	m_gameSizeCol = size_col;
	m_gameSizeRow = size_row + 50; // +50 for game bar row
	float counter = 200;
	auto upper = sf::Sprite(DataManger::instence().getGameTexture().upperRow); // Creates an object for a top frame
	upper.setPosition(sf::Vector2f(0, 0));
	m_items.m_upperow.push_back(upper);
	auto bottom = sf::Sprite(DataManger::instence().getGameTexture().bottomRow);
	bottom.setPosition(sf::Vector2f(0, m_gameSizeRow - 50));
	m_items.m_lowerrow.push_back(bottom);
	while (counter < m_gameSizeCol) //Fills the vector representing the static objects of the window  
	{
		// creat the sprite of up and down limits
		if (counter + 200 < m_gameSizeCol)
		{
			upper = sf::Sprite(DataManger::instence().getGameTexture().upperRow);
			upper.setPosition(sf::Vector2f(counter, 0));
			m_items.m_upperow.push_back(upper);
			bottom = sf::Sprite(DataManger::instence().getGameTexture().bottomRow);
			bottom.setPosition(sf::Vector2f(counter, m_gameSizeRow - 50));
			m_items.m_lowerrow.push_back(bottom);
			counter += 200;
			continue;
		}// in the first col we put a diffrent texture
		upper = sf::Sprite(DataManger::instence().getGameTexture().upperBlock);
		upper.setPosition(sf::Vector2f(counter, 0));
		m_items.m_upperow.push_back(upper);
		bottom = sf::Sprite(DataManger::instence().getGameTexture().bottoBlock);
		bottom.setPosition(sf::Vector2f(counter, m_gameSizeRow - 50));
		m_items.m_lowerrow.push_back(bottom);
		counter += 50;
	}
	counter = 24;
	while (counter < m_gameSizeRow - 100)
	{
		counter += 50;
		auto left = sf::Sprite(DataManger::instence().getGameTexture().leftRow);
		left.setPosition(sf::Vector2f(0, counter));
		m_items.m_leftrow.push_back(left);
		auto right = sf::Sprite(DataManger::instence().getGameTexture().rightRow);
		right.setPosition(sf::Vector2f(m_gameSizeCol - 50, counter));
		m_items.m_rightrow.push_back(right);
	}
	// creat the backround and set his position
	auto backround = sf::Sprite(DataManger::instence().getGameTexture().gameBackround);
	float x = (m_gameSizeCol);
	x /= 1500;
	float y = (m_gameSizeRow);
	y /= 1500;
	backround.setPosition(sf::Vector2f(0, 50));
	backround.scale(sf::Vector2f(x, y));
	m_items.m_GameBackround = backround;
}
//-------------------------------------------------------------------
// clear the vectors for next level backround
void Backround::clearBackRound()
{
	m_items.m_leftrow.clear();
	m_items.m_lowerrow.clear();
	m_items.m_rightrow.clear();
	m_items.m_upperow.clear();
}