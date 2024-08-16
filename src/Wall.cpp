#include "Wall.h"

//wall C-Tor Receives position and texture,
// loads the texture and places the object according to the position
//--------------------------------------------
Wall::Wall(const sf::Vector2f& position, const sf::Texture& texture)
{
	setPositionSprite(position);
	initSprite(texture);
	setOrgin();
}
//-------------------------------------------
void Wall::initSprite(const sf::Texture& texture)
{
	setTexture(texture);
}
// the wall will never delete so we return false
//--------------------------------------------
bool Wall::handleCollision(Pacman & gameObj)
{
	gameObj.handleCollision(*this);
	return false;
}

//-------------------------------------------
bool Wall::handleCollision(Demon& gameObj)
{
	gameObj.handleCollision(*this);
	return false;
}