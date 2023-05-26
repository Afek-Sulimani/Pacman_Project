#pragma once
#include "GameObj.h"
#include <SFML/Graphics.hpp>

class DynamicObj : public GameObj
{
public:
	DynamicObj();
	virtual void move(const sf::Time& deltaTime) = 0;
	sf::Vector2f getDiraction() const;
	float getSpeed() const;
	sf::IntRect getRectangle() const;
	void objectBlocked();
	virtual void setBlocked() {};
	void backToOriginal();

protected:
	void handleRectable(const sf::Time& deltaTime);
	void setSpeed(float speed);
	void setDiraction(const sf::Vector2f& diraction);
	void setRecTangle();
	void SetTopRectangle(int col);
	void setLastPosition(const sf::Vector2f& lastPosition);
	void setOriginalPosition(const sf::Vector2f& OriginalPosition);

private:
	sf::Vector2f m_originalPosition;
	sf::Vector2f m_lastPosition;
	sf::Vector2f m_diraction;
	sf::IntRect m_recTexture;
	float m_speed;
};