#pragma once
#include "GameObj.h"
#include  <SFML/Graphics.hpp>

class StaticObj :public GameObj
{
public:
	StaticObj() {};
	bool handleCollision(GameObj& gameObj) override;
	bool handleCollision(Door& gameObj) override;
	bool handleCollision(Cookie& gameObj) override;
	bool handleCollision(Key& gameObj) override;
	bool handleCollision(Present& gameObj) override;
	bool handleCollision(Wall& gameObj) override;
private:
};
