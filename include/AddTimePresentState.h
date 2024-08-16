#pragma once
#include <SFML/Graphics.hpp>
#include "PresentState.h"
#include "DataManger.h"

const int TIME_TO_ADD = 20;

class AddTimePresentState : public PresentState
{
public:
	void handleCollision(Pacman& gameObj);
	sf::Texture& getSptiteTexture() const;
private:
};
