#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObj.h"
#include "Pacman.h"
#include "Demon.h"

class Wall : public StaticObj
{
public:
	~Wall() {};
	Wall(const sf::Vector2f& position, const sf::Texture& texture);
	bool handleCollision(Pacman& gameObj) override ;
	bool handleCollision(Demon& gameObj) override;
private:
	void initSprite(const sf::Texture& texture);
};