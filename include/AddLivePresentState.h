#pragma once
#include <SFML/Graphics.hpp>
#include "PresentState.h"
#include "DataManger.h"

class AddLivePresentState : public PresentState
{
public:
	void handleCollision(Pacmen& gameObj);
	sf::Texture& getSptiteTexture() const;
private:
};