#include "DemonState.h"
// constractor for the demon state
//------------------------------
DemonState::DemonState()
	:m_diracrtion(0),
	m_blocked(true)
{}

//--------------------------------
sf::Vector2f DemonState::getLastDiraction()
{
	return m_lastDiraction;
}

//-----------------------------------
void DemonState::setLastDiraction(const sf::Vector2f& diraction)
{
	m_lastDiraction = diraction;
}
// will set diraction according an integer and will also return it
//------------------------------------
sf::Vector2f DemonState::setNewDirection(const int num)
{
	switch (num)
	{
	case (LEFT):
	{
		setLastDiraction(sf::Vector2f(-1, 0));
		break;
	}
	case(RIGHT):
	{
		setLastDiraction(sf::Vector2f(1, 0));
		break;
	}
	case (DOWN):
	{
		setLastDiraction(sf::Vector2f(0, -1));
		break;
	}
	case (UP):
	{
		setLastDiraction(sf::Vector2f(0, 1));
		break;
	}
	}
	m_diracrtion = num;
	return getLastDiraction();
}

//-----------------------------------
bool DemonState::getDemonBlocked() const
{
	return m_blocked;
}

//------------------------------------
void DemonState::setDemonBlock(const bool block)
{
	m_blocked = block;
}
// use the basic algorithem of the demon to get out of a block
// by finding new random way out
//--------------------------------------
void DemonState::getOutOfBlock()
{
	sf::Vector2f last_direction = getLastDiraction();
	setNewDirection(rand() % 4);
	while (getLastDiraction() == last_direction) // if not equal so last direction updated
		setNewDirection(rand() % 4);
	setDemonBlock(false);
}
// virtual function, only the smart demon return true
//------------------------------------
bool DemonState::isSmart() const
{
	return false;
}

//-----------------------------------
int DemonState::getDiractionNum() const
{
	return m_diracrtion;
}

//---------------------------------------
int DemonState::GetOpisetDiraction(int diraction)
{
	switch (diraction)
	{
	case UP:
		return DOWN;
	case DOWN:
		return UP;
	case RIGHT:
		return LEFT;
	case LEFT:
		return RIGHT;
	default:
		break;
	}
	return 0;
}