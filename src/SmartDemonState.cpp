#include "SmartDemonState.h"
//------------------------------------
SmartDemonState::SmartDemonState()
	: m_lastGoodDiraction(0),
	m_stepsCount(0)
{}
//smart demon can get passed doors
//------------------------------------
bool SmartDemonState::handleDoorCollision()
{
	return false;
}
//can kill pacman
//-------------------------------------
bool SmartDemonState::handlePacmanCollision()
{
	return true;
}
//------------------------------------
bool SmartDemonState::isDead() const
{
	return false;
}
/*
* this will be the move function of the smart demon
* the function will move the demon towards the pacman and
* will try not to get blocked in the way, will do 20 moves
* each "step"
*/
//------------------------------------
sf::Vector2f SmartDemonState::moveDemon(Demon& demon) //const
{
	if (!getDemonBlocked()) //update the last succseful move
		m_lastGoodDiraction = getDiractionNum();
	else
		m_stepsCount = 20; //want to get out right out of block
	if (m_stepsCount < 20)
	{
		m_stepsCount++;
		setDemonBlock(false);
		return getLastDiraction(); //keep going in  same diraction
	}
	m_stepsCount = 0;
	smartNextMove(demon);
	return getLastDiraction();
}

// will find the next "smart move" towards the pacman
//-----------------------------------------
void SmartDemonState::smartNextMove(Demon& demon)
{
	if (getDemonBlocked())
	{
		if (m_lastGoodDiraction == getDiractionNum()) //if got into loop of blockes
			getOutOfBlock(); //by random algorithm
		else // use the smart function that will be able to step forward 
			getOutOfBlockSmart(demon, GetOpisetDiraction(m_lastGoodDiraction), getDiractionNum());
	}
	else //get the closest rout
		getOutOfBlockSmart(demon, -1, -1);
}

//---------------------------------------------
bool SmartDemonState::isSmart() const
{
	return true;
}

//----------------------------------------------
void SmartDemonState::getOutOfBlockSmart(Demon& demon, int diraction1, int diraction2)
{
	demon.huntPacman(diraction1, diraction2);
	setDemonBlock(false);
}
//smart demon is a little faster the normal one
//----------------------------------------------
float SmartDemonState::getSpeed() const
{
	return (float)1.38;
}