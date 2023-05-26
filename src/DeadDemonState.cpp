#include "DeadDemonState.h"
// if the dead demon cannot collide with door and passed it
//---------------------------------
bool DeadDemonState::handleDoorCollision()
{
	return false;
}
//nothing will happen if the pacmen collide with dead demon
//---------------------------------
bool DeadDemonState::handlePacmenCollision()
{
	return false;
}
// the dead demon will not be able to move
//-------------------------------
sf::Vector2f DeadDemonState::moveDemon(Demon& demon)
{
	(void)demon; // for avoid warning 
	return sf::Vector2f(0, 0);
}
// will set if the demon was smart befor he died
//-------------------------------------
void DeadDemonState::setSmart(const bool& wasSmart)
{
	m_wasSmart = wasSmart;
}
// will return if thw demon was smart
//------------------------------------
bool DeadDemonState::isSmart() const
{
	return m_wasSmart;
}
//--------------------------------------
bool DeadDemonState::isDead() const
{
	return true;
}
//-------------------------------------
float DeadDemonState::getSpeed() const
{
	return 0;
}