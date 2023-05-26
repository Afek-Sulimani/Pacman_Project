#pragma once
#include <SFML/Graphics.hpp>
#include "PresentState.h"
#include "DataManger.h"
class SuperPacmenPresentState : public PresentState
{
public:
	void handleCollision(Pacmen& gameObj) override;
	sf::Texture& getSptiteTexture() const;
private:
};
