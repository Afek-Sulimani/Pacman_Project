#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
struct BackroundItems
{
	std::vector <sf::Sprite> m_upperow;
	std::vector <sf::Sprite> m_lowerrow;
	std::vector <sf::Sprite> m_leftrow;
	std::vector <sf::Sprite> m_rightrow;
	sf::Sprite m_GameBackround;
};
