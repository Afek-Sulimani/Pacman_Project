#include "GameObj.h"
#include <iostream>

// this is the draw func for all the game objects
//-----------------------------------------------------
void GameObj::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

//------------------------------------------------------
void GameObj::setPositionSprite(const sf::Vector2f& position)
{
	m_sprite.setPosition(position);
}
//-----------------------------------------------------
void GameObj::setOrgin()
{
	m_sprite.setOrigin(sf::Vector2f(m_sprite.getLocalBounds().left + m_sprite.getLocalBounds().width / 2u,
		m_sprite.getLocalBounds().height / 2u));
}

// move the sprite by direction and speed
//------------------------------------------------------
void GameObj::moveSprite(const sf::Vector2f& diraction, const float& speed)
{
	m_sprite.move(diraction * speed);
}
//---------------------------------------------------------
void GameObj::setTextureRect(const sf::IntRect& Rectangle)
{
	m_sprite.setTextureRect(Rectangle);
}
//-------------------------------------------------------
void GameObj::setTexture(const sf::Texture& texture)
{
	m_sprite.setTexture(texture);
}

//-------------------------------------------------------
void GameObj::setScale(const float& x, const float& y)
{
	m_sprite.setScale(x, y);
}

// this func check if was a collision  
//------------------------------------------------------
bool GameObj::checkCollision(const GameObj& gameobj) const
{
	if (&gameobj == this)
		return false;
	if (this->m_sprite.getGlobalBounds().intersects(gameobj.getSmallerBounds()))
	{
		return true;
	}
	return false;
}

//-----------------------------------------------------
sf::FloatRect GameObj:: getSpriteGlobalBounds() const
{
	return m_sprite.getGlobalBounds();
}
//-----------------------------------------------------
sf::Vector2f GameObj::getPosition() const
{
	return m_sprite.getPosition();
}

//This function reduces the blocking rectangle of the object
//in case it is required to pass between walls 
//but the blocking rectangles are too large for it to pass
//---------------------------------------------------
sf::FloatRect GameObj::getSmallerBounds() const
{
	return sf::FloatRect(sf::Vector2f(m_sprite.getPosition().x -8, m_sprite.getPosition().y -8),
										sf::Vector2f(20, 20));
}
//---------------------------------------------------
void GameObj::playSound(const sf::SoundBuffer& sound)
{
	m_sound.setBuffer(sound);
	m_sound.play();
}