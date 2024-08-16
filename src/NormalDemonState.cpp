#include "NormalDemonState.h"
//Normal demon cannot passed doors
//------------------------------------
bool NormalDemonState::handleDoorCollision()
{
	return true;
}
//Normal demon can kill pacman
//-------------------------------------
bool NormalDemonState::handlePacmanCollision()
{
	return true;
}
//--------------------------------------

/*
this is the reguler demon move
* the algorithem is random.the demon will move 20 time at each
* diraction
*/
//------------------------------------
sf::Vector2f NormalDemonState::moveDemon(Demon& demon)
{
	(void)demon; //to avoid warning 
	static int count = 0;
	if (getDemonBlocked())
		getOutOfBlock();
	else
	{
		if (count < 20)
		{
			count++;
			return getLastDiraction();
		}
		count = 0;
		setNewDirection(rand() % 4);
	}
	return getLastDiraction();
}
//--------------------------------------
bool NormalDemonState::isDead() const
{
	return false;
}

//--------------------------------------
float NormalDemonState::getSpeed() const
{
	return 1;
}
