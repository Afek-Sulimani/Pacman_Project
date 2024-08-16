#include "AddLivePresentState.h"

// collision between add live present and pacman, 
//--------------------------------
void AddLivePresentState::handleCollision(Pacman& gameObj)
{
	(void)gameObj; // for avoid warning 
	DataManger::instence().addLive();
}

// return the add live present texture to init sprite func from present class 
//------------------------------------------------------------------------
sf::Texture& AddLivePresentState::getSptiteTexture() const
{
	return DataManger::instence().getGameTexture().present;
}