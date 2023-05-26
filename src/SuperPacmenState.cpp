#include "SuperPacmenState.h"
//-------------------------------------
SuperPacmenState::SuperPacmenState()
	: m_isAttack(false)
{}
// return if the superPacmen is not attacking the demon
//------------------------------------
bool SuperPacmenState::handleDemonCollision()
{
	return !m_isAttack;
}

//-------------------------------------------
bool SuperPacmenState::handleDoorCollision()
{
	return true;
}
// this function handle the keybord input and move the player
//--------------------------------------------
bool SuperPacmenState::movePacmen(Pacmen& player)
{
	m_isAttack = (player.superPacmenAttack());
	return (player.handleKey());
}
//---------------------------------------------
bool SuperPacmenState::isSuper() const
{
	return true;
}
//----------------------------------------------
bool SuperPacmenState::getAttack() const
{
	return m_isAttack;
}
//--------------------------------------------
float SuperPacmenState::getSpeed() const
{
	return (float)2.3;
}