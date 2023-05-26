#include "NormalPacmenState.h"
//------------------------------------
bool NormalPacmenState::handleDemonCollision()
{ 
	return true;
}

// normal pacmen can not over door
//-------------------------------------------
bool NormalPacmenState::handleDoorCollision()
{ 
	return false;
}
//--------------------------------------------
bool NormalPacmenState::movePacmen(Pacmen& player)
{
	return (player.handleKey());
}
//-------------------------------------------
bool NormalPacmenState::isSuper() const
{
	return false;
}
//-------------------------------------------
bool NormalPacmenState::getAttack() const
{
	return false;
}
//--------------------------------------------
float NormalPacmenState::getSpeed() const
{
	return 2;
}