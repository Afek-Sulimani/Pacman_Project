#pragma once
#include <SFML/Graphics.hpp>
#include "KillDemonsPresentState.h"
#include "SuperPacmanPresentState.h"
#include "AddTimePresentState.h"
#include "AddLivePresentState.h"
#include "StaticObj.h"
#include "Pacman.h"
#include "Demon.h"
#include <memory>

class PresentState;

class Present : public StaticObj
{
public:
	Present(const sf::Vector2f& position);
	bool handleCollision(Pacman& gameObj) override;
	bool handleCollision(Demon& gameObj) override;

private:
	void setTexturePresent();
	void initSprite(const sf::Texture& texture);
	std::unique_ptr<PresentState> ps;
	
};
