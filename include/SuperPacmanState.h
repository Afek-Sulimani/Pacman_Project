#pragma once
#include "PacmanState.h"
#include <SFML/Graphics.hpp>
#include "Pacman.h"
class Pacman;
class SuperPacmanState : public PacmanState
{
public:
	SuperPacmanState();
	~SuperPacmanState() {};
	bool handleDemonCollision() override;
	bool handleDoorCollision() override;
	bool movePacman(Pacman& player);
	bool isSuper() const override;
	bool getAttack() const;
	float getSpeed() const;
private:
	bool m_isAttack;
};