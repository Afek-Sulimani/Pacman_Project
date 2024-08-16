#pragma once
#include <SFML/Graphics.hpp>
#include "DemonState.h"
#include "Demon.h"
  
class SmartDemonState :public DemonState
{
public:
    SmartDemonState();
    bool handleDoorCollision() override ;
    bool handlePacmanCollision() override ;
    bool isDead() const ;
    sf::Vector2f moveDemon(Demon& demon);
    void smartNextMove(Demon& demon);
    bool isSmart() const override;
    float getSpeed() const;
    void getOutOfBlockSmart(Demon& demon, int diraction1, int diraction2);
private:
    int m_lastGoodDiraction;
    int m_stepsCount ;
   
};