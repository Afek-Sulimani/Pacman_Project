#include "KillDemonsPresentState.h"

//handle the collision of pacman 
// with the present that kill all the demonds for few seconds 
//  and set the spacial attack to true
//--------------------------------
void KillDemonsPresentState::handleCollision(Pacman& gameObj)
{
	gameObj.setSpecialAttack(true);
}

// got the textire of kill demon present from game texture
//--------------------------------
sf::Texture& KillDemonsPresentState::getSptiteTexture() const
{
	return DataManger::instence().getGameTexture().present1;
}