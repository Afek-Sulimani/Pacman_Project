#pragma once
#include <SFML/Graphics.hpp>

class Pacman;
class PacmanState 
{
public:
    virtual ~PacmanState() {}
    virtual bool handleDoorCollision() = 0;
    virtual bool handleDemonCollision() = 0;
    virtual bool movePacman(Pacman& player) = 0;
    virtual bool isSuper() const = 0;
    virtual bool getAttack() const = 0;
    virtual float getSpeed() const = 0;
};