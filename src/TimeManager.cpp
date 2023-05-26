#include "TimeManager.h"

//inititlaized the param of the time
//------------------------------------
void TimeManager::initTime()
{
	m_time = 0;
	m_countDownTime = -1;
	levelWithTimeLimit = false;
}

// received number from level class 
// 0 if this level without time limit
//----------------------------------
void TimeManager::setTime(int time)
{
	if (time > 0)
	{
		levelWithTimeLimit = true;
		m_countDownTime = time * 10;
	}
	else if (time <= 0)
	{
		levelWithTimeLimit = false;
		m_countDownTime = 0;
	}
}

// adding time if the pacmen collide with add tipe present
//--------------------------------------------
void TimeManager::addTime(const int timeToAdd)
{
	m_countDownTime += (timeToAdd * 10);
}

// return true if it was a limit time level and the time is gone
// else return true if the time is not gone
//--------------------------------------------------
bool TimeManager::timeGone() const
{
	if (m_countDownTime <= 0 && levelWithTimeLimit == true)
		return true;
	return false;
}

// return the time for info bar
//--------------------------------------------------
std::string TimeManager::getString() 
{
	std::string ret_string = convertTimeToString(m_time);
	if (levelWithTimeLimit)
		return ret_string += "  Remaining : " + convertTimeToString(m_countDownTime);
	return ret_string;
}

// convert the time to human clock form 
//-------------------------------------------------
std::string TimeManager::convertTimeToString(int seconds)
{
	int min;
	int sec;
	seconds /= 10;
	min = seconds / 60;
	sec = seconds % 60;
	return (std::to_string(min / 10) + std::to_string(min % 10)
		+ ":" + std::to_string(sec / 10) + std::to_string(sec % 10));
}

// return if it limit time level
//-----------------------------------
bool TimeManager::isLimitLevel() const
{
	return levelWithTimeLimit;
}

//got the elapsed time and add it or sub it  according to the clock
//---------------------------------------------
void TimeManager::handleTime(const sf::Time& deltaTime)
{
	m_time += deltaTime.asMilliseconds() / 100;
	m_countDownTime -= deltaTime.asMilliseconds() / 100;
}