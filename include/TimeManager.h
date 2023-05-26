#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class TimeManager
{
public:
	TimeManager() = default;
	void setTime(int time);
	void addTime(const int timeToAdd);
	bool timeGone() const;
	void handleTime(const sf::Time& deltaTime);
	void initTime();
	bool isLimitLevel() const ;
	std::string getString();
private:
	bool levelWithTimeLimit;
	int m_time;
	int m_countDownTime;
	std::string convertTimeToString(int sec);
};
