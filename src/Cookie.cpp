#include "Cookie.h"

//cookie C-Tor Receives position and texture,
// loads the texture and places the object according to the position
//--------------------------------------------
Cookie::Cookie(const sf::Vector2f& position, const sf::Texture& texture)
{
	setPositionSprite(position);
	initSprite(texture);
	setOrgin();
}

//-------------------------------------------
void Cookie::initSprite( const sf::Texture& texture)
{
	setTexture(texture);
}

// collision with pacmen fromm cookie
// calld for the collision from pacmen side
// and return all the times true for delete the object
//-------------------------------------------
bool Cookie::handleCollision(Pacmen& gameObj)
{
	gameObj.handleCollision(*this);
	return true;
}

//collision with demon fromm cookie
// calld for the collision from demon side
// and return all the times false for not deleting it
//----------------------------------------------
bool Cookie::handleCollision(Demon& gameObj)
{
	gameObj.handleCollision(*this);
	return false;
}