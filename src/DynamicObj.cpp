#include "DynamicObj.h"
#include <iostream>

//A dynamic object constructor 
// initializes the animation's blocking rectangle
//----------------------------------------------
DynamicObj::DynamicObj()
	: m_recTexture(sf::IntRect(0, 0, 50, 50)),
	  m_speed(1)
{}

//Returns the bounding rectangle of the animation
//----------------------------------------------
sf::IntRect DynamicObj::getRectangle() const
{
	return m_recTexture;
}

//Returns the orientation of the dynamic object
//-----------------------------------------------
sf::Vector2f DynamicObj::getDiraction() const
{
	return m_diraction;
}

//----------------------------------------------
float DynamicObj::getSpeed() const
{
	return m_speed;
}
//-----------------------------------------------
void DynamicObj::setSpeed(float speed)
{
	m_speed = speed;
}

// update the direction
//----------------------------------------------
void DynamicObj::setDiraction(const sf::Vector2f& diraction)
{
	m_diraction = diraction;
}

//This function moves the blocking rectangle of the animation every few seconds
// and update the last position of rectangle 
//---------------------------------------------
void DynamicObj::handleRectable(const sf::Time& deltaTime)
{
	static bool revers;
	if (deltaTime.asMilliseconds() < 80)
		return;
	if (m_recTexture.left == 0)
	{
		m_recTexture.left += 50;
		revers = false;
	}
	else if (m_recTexture.left == 300)
	{
		m_recTexture.left -= 50;
		revers = true;
	}
	else if (!revers)
		m_recTexture.left += 50;
	else if (revers)
		m_recTexture.left -= 50;
	setTextureRect(m_recTexture);
}
//--------------------------------------------
void DynamicObj::setRecTangle()
{
	setTextureRect(getRectangle());
	setOrgin();
}
//--------------------------------------------
void DynamicObj::SetTopRectangle(int col)
{
	m_recTexture.top = col;
}

// update the last position 
//--------------------------------------------
void DynamicObj::setLastPosition(const sf::Vector2f& lastPosition)
{
	m_lastPosition = lastPosition;
}
// this func will update the last object position 
// when coliide with wall or unlock door
//---------------------------------------------
void DynamicObj::objectBlocked()
{
	setBlocked();
	setPositionSprite(m_lastPosition);
}
//--------------------------------------------------
void DynamicObj::setOriginalPosition(const sf::Vector2f& OriginalPosition)
{
	m_originalPosition = OriginalPosition;
}

// return to the original position
//---------------------------------------------------
void DynamicObj::backToOriginal()
{
	setPositionSprite(m_originalPosition);
}