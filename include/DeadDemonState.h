#pragma once
#include <SFML/Graphics.hpp>
#include "DemonState.h"

class DeadDemonState : public DemonState
{
public:
    bool handleDoorCollision() override ;
    bool handlePacmenCollision() override ;
    bool isDead() const ;
    sf::Vector2f moveDemon(Demon& demon);
    void setSmart(const bool& wasSmart);
    bool isSmart() const override;
    float getSpeed() const;
private:
    bool m_wasSmart;
};