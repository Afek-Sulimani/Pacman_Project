#include "SuperPacmanState.h"
//-------------------------------------
SuperPacmanState::SuperPacmanState()
	: m_isAttack(false)
{}
// return if the superPacman is not attacking the demon
//------------------------------------
bool SuperPacmanState::handleDemonCollision()
{
	return !m_isAttack;
}

//-------------------------------------------
bool SuperPacmanState::handleDoorCollision()
{
	return true;
}
// this function handle the keybord input and move the player
//--------------------------------------------
bool SuperPacmanState::movePacman(Pacman& player)
{
	m_isAttack = (player.superPacmanAttack());
	return (player.handleKey());
}
//---------------------------------------------
bool SuperPacmanState::isSuper() const
{
	return true;
}
//----------------------------------------------
bool SuperPacmanState::getAttack() const
{
	return m_isAttack;
}
//--------------------------------------------
float SuperPacmanState::getSpeed() const
{
	return (float)2.3;
}