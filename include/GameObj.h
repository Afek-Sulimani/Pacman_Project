#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
class Pacman;
class Demon;
class Cookie;
class Door;
class Key;
class Present;
class Wall;

class GameObj
{
public:
	GameObj() {};
	virtual ~GameObj() {};
	virtual void draw(sf::RenderWindow& window);
	virtual bool handleCollision(GameObj& gameoObj) = 0;
	virtual bool handleCollision(Pacman& gameObj) = 0;
	virtual bool handleCollision(Cookie& gameObj) = 0;
	virtual bool handleCollision(Demon& gameObj) = 0;
	virtual bool handleCollision(Door& gameObj) = 0;
	virtual bool handleCollision(Key& gameObj) = 0;
	virtual bool handleCollision(Present& gameObj) = 0;
	virtual bool handleCollision(Wall& gameObj) = 0;
	virtual bool checkCollision(const GameObj& gameobj) const;
	sf::FloatRect getSpriteGlobalBounds() const;

protected:
	void playSound(const sf::SoundBuffer& sound);
	sf::FloatRect getSmallerBounds() const;
	sf::Vector2f getPosition() const;
	void setOrgin();
	void setPositionSprite(const sf::Vector2f& position);
	void moveSprite(const sf::Vector2f& diraction, const float& speed);
	void setTextureRect(const sf::IntRect& Rextangle);
	void setTexture(const sf::Texture& texture);
	void setScale(const float&, const float&);
private:
	sf::Sprite m_sprite;
	sf::Sound m_sound;
};