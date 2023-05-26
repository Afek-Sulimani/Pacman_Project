#pragma once
#include "BackroundItems.h"
#include <SFML/Graphics.hpp>
#include "DataManger.h"
#include "DynamicObj.h"
class Backround
{
public:
	Backround() : m_gameSizeCol(0), m_gameSizeRow(0) {};
	void initBackRound(float, float);
	void draw(sf::RenderWindow& window);
	bool isCollideWithBounds(const DynamicObj& dynamicObj) const;
private:
	float m_gameSizeRow;
	float m_gameSizeCol;
	BackroundItems m_items;
	void clearBackRound();
};