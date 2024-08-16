#pragma once
#include <SFML/Graphics.hpp>
#include "DynamicObj.h"
#include <memory>
#include "PacmanState.h"
#include "NormalPacmanState.h"
#include "SuperPacmanState.h"
#include "DataManger.h"
#include <string>
class Pacman : public DynamicObj
{
public:
	Pacman();
	~Pacman() {};
	bool handleCollision(GameObj& gameoObj) override;
	bool handleCollision(Pacman& gameObj) override;
	bool handleCollision(Demon& gameObj) override;
	bool handleCollision(Door& gameObj) override;
	bool handleCollision(Key& gameObj) override;
	bool handleCollision(Present& gameObj) override;
	bool handleCollision(Cookie& gameObj) override;
	bool handleCollision(Wall& gameObj) override;
	void move(const sf::Time& deltaTime);
	void setPosition(const sf::Vector2f& position);
	bool isSuperPacmanAttack() const;
	bool superPacmanAttack();
	bool isSuper() const;
	bool handleKey();
	void drawBars(sf::RenderWindow& window);
	void makeSuper();
	bool isSpacielAttack();
	void setSpecialAttack(const bool& isSpacielAttack);
private:
	void handleStep(const sf::Time& deltaTime);
	int m_shakeScreenLen;
	void shakeScreen(sf::RenderWindow& window);
	void spacielAttack();
	void updateBars();
	void initBarSprites();
	void initPacman();
	void backToNormal();
	bool m_specialAttack;
	int m_dashTime;
	int m_attackLen;
	int m_superPacmanTime;
	bool m_isAttack;
	int m_playerScore;
	std::unique_ptr<PacmanState> ps;
	sf::Sprite m_superPacmanBar;
	sf::Sprite m_DashBar;
	sf::Sound m_attackSound;
	sf::Sound m_transformSound;
	sf::Sound m_dashSound;
};
