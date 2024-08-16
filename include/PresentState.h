#pragma once
#include <SFML/Graphics.hpp>

class Pacman;
class PresentState
{
public:
	virtual void handleCollision(Pacman& gameObj) = 0;
	virtual sf::Texture& getSptiteTexture() const = 0;
	virtual ~PresentState() {};

};
