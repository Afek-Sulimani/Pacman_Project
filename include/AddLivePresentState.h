#pragma once
#include <SFML/Graphics.hpp>
#include "PresentState.h"
#include "DataManger.h"

class AddLivePresentState : public PresentState
{
public:
	void handleCollision(Pacman& gameObj);
	sf::Texture& getSptiteTexture() const;
private:
};