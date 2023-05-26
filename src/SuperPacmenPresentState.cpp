#include "SuperPacmenPresentState.h"

// collision between pacmen and spacial present
// that make the pacmen to be super 
// called pacmen fun that make it to be super
//----------------------------------
void SuperPacmenPresentState::handleCollision(Pacmen& gameObj)
{
	gameObj.makeSuper();
}

// set the texture of the super pacmen present
//--------------------------------
sf::Texture& SuperPacmenPresentState::getSptiteTexture() const
{
	return DataManger::instence().getGameTexture().present3;
}
