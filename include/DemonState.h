#pragma once
#include <SFML/Graphics.hpp>
enum DirectionType
{
    LEFT = 0,
    RIGHT = 1,
    DOWN = 2,
    UP = 3
};
class Demon;

class DemonState {
public:
    DemonState();
    virtual bool handleDoorCollision() = 0;
    virtual bool handlePacmenCollision() = 0;
    virtual bool isDead() const = 0;
    virtual sf::Vector2f moveDemon(Demon& demon) = 0;
    sf::Vector2f getLastDiraction();
    void setLastDiraction(const sf::Vector2f& diraction);
    sf::Vector2f setNewDirection(const int num);
    virtual ~DemonState() {}
    bool getDemonBlocked() const;
    void setDemonBlock(const bool block);
    virtual void getOutOfBlock();
    virtual bool isSmart() const;
    virtual void setSmart(const bool& wasSmart) { (void)wasSmart; };
    int getDiractionNum() const;
    int GetOpisetDiraction(int diraction);
    virtual float getSpeed() const = 0;

private:
    int m_diracrtion;
    sf::Vector2f m_lastDiraction;
    bool m_blocked;
};