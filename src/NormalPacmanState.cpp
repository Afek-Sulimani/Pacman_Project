#include "NormalPacmanState.h"
//------------------------------------
bool NormalPacmanState::handleDemonCollision()
{ 
	return true;
}

// normal pacman can not over door
//-------------------------------------------
bool NormalPacmanState::handleDoorCollision()
{ 
	return false;
}
//--------------------------------------------
bool NormalPacmanState::movePacman(Pacman& player)
{
	return (player.handleKey());
}
//-------------------------------------------
bool NormalPacmanState::isSuper() const
{
	return false;
}
//-------------------------------------------
bool NormalPacmanState::getAttack() const
{
	return false;
}
//--------------------------------------------
float NormalPacmanState::getSpeed() const
{
	return 2;
}