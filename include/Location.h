#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
//----------------------------------------------------------------
struct Location
{
    Location(int x = 0, int y = 0);
    Location(const sf::Vector2f& location);
    Location getLocationFromVectorsf(const sf::Vector2f& location);
    sf::Vector2f getGlobal();
    int row;
    int col;
};
