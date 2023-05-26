#include "Door.h"

//door C-Tor Receives position and texture,
// loads the texture and places the object according to the position
//--------------------------------------------
Door::Door(const sf::Vector2f& position, const sf::Texture& texture)
{
	setPositionSprite(position);
	initSprite(texture);
	setOrgin();
}
//set the textue in the sprite in the base class
//-------------------------------------------
void Door::initSprite(const sf::Texture& texture)
{
	setTexture(texture);
}

// collision with pacmen from door
// calld for the collision from pacmen side
// and return if delete or not the door Depending if super or not
//-----------------------------------------------
bool Door::handleCollision(Pacmen& gameObj)
{
	return (gameObj.handleCollision(*this));
}

// collision with demon from door
// calld for the collision from demon side
// and return if delete or not the door Depending on the type of demon
//----------------------------------------------
bool Door::handleCollision(Demon& gameObj)
{
	return (gameObj.handleCollision(*this));
	
}
