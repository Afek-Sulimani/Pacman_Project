#pragma once
#include <SFML/Graphics.hpp>

class Pacmen;
class PresentState
{
public:
	virtual void handleCollision(Pacmen& gameObj) = 0;
	virtual sf::Texture& getSptiteTexture() const = 0;
	virtual ~PresentState() {};

};
