#pragma once
#include "DynamicObj.h"
#include <SFML/Graphics.hpp>
#include "DemonState.h"
#include "DeadDemonState.h"
#include "NormalDemonState.h"
#include "SmartDemonState.h"
#include <memory>
#include "Present.h"
#include <cmath>
#include "DataManger.h"

class Demon : public DynamicObj
{
public:
	Demon(const sf::Vector2f& position, const sf::Texture& texture);
	void move(const sf::Time& deltaTime);
	~Demon() {};
	bool handleCollision(GameObj& gameoObj) override;
	bool handleCollision(Pacmen& gameObj) override;
	bool handleCollision(Demon& gameObj) override;
	bool handleCollision(Door& gameObj) override;
	bool handleCollision(Key& gameObj) override;
	bool handleCollision(Present& gameObj) override;
	bool handleCollision(Cookie& gameObj) override;
	bool handleCollision(Wall& gameObj) override;
	void setBlocked();
	bool isDead() const;
	void huntPacmen(int diraction1, int diraction2);
	void beDead();
	bool isSmart() const;
private:
	float caculateSIzeFromPacmen(int addToX, int addToY);
	void backToNormal();
	int m_deadTime;
	void beSmart();
	std::unique_ptr<DemonState> ps;
	void initSprite(const sf::Texture& texture);

};