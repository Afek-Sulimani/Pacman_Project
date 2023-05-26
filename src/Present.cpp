#include "Present.h"

//present C-Tor Receives position ,
// loads the texture ascending and places the object according to the position
//------------------------------------------
Present::Present(const sf::Vector2f& position)
{
	static int present_type = -1 ;
	setPositionSprite(position);
	int num = 4;
	//check if this level have time limit for avoid add time present
	if ((DataManger::instence().getTime().isLimitLevel()) == false)
		num = 3; // so do not creat a add time present.
	present_type++;
	present_type %= num;
	switch (present_type)
	{
	case 0:
		ps.reset(new SuperPacmenPresentState);
		break;
	case 1:
		ps.reset(new AddLivePresentState);
		break;
	case 2:
		ps.reset(new KillDemonsPresentState);
		break;
	case 3:
		ps.reset(new AddTimePresentState);
		break;
	}
	setTexturePresent();
	setOrgin();
}
//-------------------------------------------
void Present::initSprite(const sf::Texture& texture)
{
	setTexture(texture);
}

//call the handle collision with pacmen of the present state
//and for the pacmen func of colliding with present
// and all the time delete the present  
//----------------------------------------------
bool Present::handleCollision(Pacmen & gameObj)
{
	ps->handleCollision(gameObj);
	gameObj.handleCollision(*this);
	return true;
}

//Returns true which means delete if the demon is normal and makes it smart.
//if he was smart then he returns a false does not delete the present
//----------------------------------------------
bool Present::handleCollision(Demon& gameObj) 
{
	if (gameObj.handleCollision(*this))
		return true;
	return false;
}
//--------------------------------------------
void Present::setTexturePresent()
{
	initSprite(ps->getSptiteTexture());
}
//-------------------------------------------