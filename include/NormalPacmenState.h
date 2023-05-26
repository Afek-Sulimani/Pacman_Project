#pragma once
#include "PacmenState.h"
#include <SFML/Graphics.hpp>
#include "Pacmen.h"

class Pacmen;
class NormalPacmenState : public PacmenState
{
public:
	NormalPacmenState() {};
	~NormalPacmenState() {};
	bool handleDemonCollision() override;
	bool handleDoorCollision() override;
	bool movePacmen(Pacmen& player);
	bool isSuper() const override;
	bool getAttack() const;
	float getSpeed() const;
private:

};