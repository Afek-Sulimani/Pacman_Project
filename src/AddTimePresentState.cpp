#include "AddTimePresentState.h"

// collision between add time present and pacman, 
//--------------------------------
void AddTimePresentState::handleCollision(Pacman& gameObj)
{
	(void)gameObj; // for avoiding warning
	if(DataManger::instence().getTime().isLimitLevel())
		DataManger::instence().getTime().addTime(TIME_TO_ADD);
}
//--------------------------------------------------
sf::Texture& AddTimePresentState::getSptiteTexture() const
{
	return DataManger::instence().getGameTexture().present2;
}