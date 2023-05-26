#pragma once
#include <SFML/Graphics.hpp>
#include "KillDemonsPresentState.h"
#include "SuperPacmenPresentState.h"
#include "AddTimePresentState.h"
#include "AddLivePresentState.h"
#include "StaticObj.h"
#include "Pacmen.h"
#include "Demon.h"
#include <memory>

class PresentState;

class Present : public StaticObj
{
public:
	Present(const sf::Vector2f& position);
	bool handleCollision(Pacmen& gameObj) override;
	bool handleCollision(Demon& gameObj) override;

private:
	void setTexturePresent();
	void initSprite(const sf::Texture& texture);
	std::unique_ptr<PresentState> ps;
	
};
