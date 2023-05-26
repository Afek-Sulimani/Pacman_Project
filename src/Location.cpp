#pragma once
#include <SFML/Graphics.hpp>
#include "Location.h"
//---------------------------------------------------------
// ctor recived two integers
Location::Location(int x, int y)
    : col(x),
      row(y)
{}
//---------------------------------------------------------
// ctor recived flout and convert to int
Location::Location(const sf::Vector2f& location)
{
    row = int(location.y / 50);
    col = int(location.x / 50);
}
//---------------------------------------------------------
//return the size of the board
sf::Vector2f Location::getGlobal()
{
    return(sf::Vector2f((float)(col * 50) +25, (float)(row * 50) + 75));
}
//--------------------------------------------------------
// the func recived a vector2f and return location object 
Location Location::getLocationFromVectorsf(const sf::Vector2f& location)
{
    int newcol = int(location.x / 50);
    int newrow = int(location.y / 50);
    Location temp;
    temp.col = newcol;
    temp.row = newrow;
    return temp;
}
