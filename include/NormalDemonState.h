#pragma once
#include <SFML/Graphics.hpp>
#include "DemonState.h"
class NormalDemonState : public DemonState
{
public:
    bool handleDoorCollision() override ;
    bool handlePacmanCollision() override ;
    bool isDead() const ;
    sf::Vector2f moveDemon(Demon& demon); 
    float getSpeed() const ;
private:

};