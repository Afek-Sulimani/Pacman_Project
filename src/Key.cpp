#include "Key.h"

//key C-Tor Receives position and texture,
// loads the texture and places the object according to the position
//--------------------------------------------
Key::Key(const sf::Vector2f& position, const sf::Texture& texture)
{
	setPositionSprite(position);
	initSprite(texture);
	setOrgin();
}
//-------------------------------------------
void Key::initSprite(const sf::Texture& texture)
{
	setTexture(texture);
}

// collision with pacman from key
// calld for the collision from pacman side
// and return all the times true for delete the object
//-----------------------------------------------
bool Key::handleCollision(Pacman& gameObj)
{
	gameObj.handleCollision(*this);
	return true;
}

// collision with demon from key
// calld for the collision from demon side
// and return all the time false for not deleting 
//----------------------------------------------
bool Key::handleCollision(Demon& gameObj)
{
	gameObj.handleCollision(*this);
	return false;
}