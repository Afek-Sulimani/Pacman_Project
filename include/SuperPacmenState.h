#pragma once
#include "PacmenState.h"
#include <SFML/Graphics.hpp>
#include "Pacmen.h"
class Pacmen;
class SuperPacmenState : public PacmenState
{
public:
	SuperPacmenState();
	~SuperPacmenState() {};
	bool handleDemonCollision() override;
	bool handleDoorCollision() override;
	bool movePacmen(Pacmen& player);
	bool isSuper() const override;
	bool getAttack() const;
	float getSpeed() const;
private:
	bool m_isAttack;
};