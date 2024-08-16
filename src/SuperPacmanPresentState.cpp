#include "SuperPacmanPresentState.h"

// collision between pacman and spacial present
// that make the pacman to be super 
// called pacman fun that make it to be super
//----------------------------------
void SuperPacmanPresentState::handleCollision(Pacman& gameObj)
{
	gameObj.makeSuper();
}

// set the texture of the super pacman present
//--------------------------------
sf::Texture& SuperPacmanPresentState::getSptiteTexture() const
{
	return DataManger::instence().getGameTexture().present3;
}
