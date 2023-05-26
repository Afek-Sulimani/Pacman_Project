#pragma once
#include <SFML/Graphics.hpp>

class Pacmen;
class PacmenState 
{
public:
    virtual ~PacmenState() {}
    virtual bool handleDoorCollision() = 0;
    virtual bool handleDemonCollision() = 0;
    virtual bool movePacmen(Pacmen& player) = 0;
    virtual bool isSuper() const = 0;
    virtual bool getAttack() const = 0;
    virtual float getSpeed() const = 0;
};