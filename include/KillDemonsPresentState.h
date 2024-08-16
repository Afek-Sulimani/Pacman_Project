#pragma once
#include <SFML/Graphics.hpp>
#include "PresentState.h"
#include "DataManger.h"

class KillDemonsPresentState : public PresentState
{
public:
	void handleCollision(Pacman& gameObj) override;
	sf::Texture& getSptiteTexture() const;
private:
};
