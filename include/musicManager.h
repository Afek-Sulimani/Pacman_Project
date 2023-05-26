#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class MusicManager
{
public:
	void initMusic();
	void startGameMusic();
	void stopGameMusic();
	void stopTransitionMusic();
	void startTrasitionMusic();
	void OpenWinMusic();
	sf::SoundBuffer keySound;
	sf::SoundBuffer presentSound;
	sf::SoundBuffer coockieSound;
	sf::SoundBuffer transformSound;
	sf::SoundBuffer attackSound;
	sf::SoundBuffer dashSound;
	sf::SoundBuffer hurtSound;
	sf::SoundBuffer byebyeSound;
	sf::SoundBuffer scream;
private:
	void loadMusic();
	sf::Music m_transitionMusic;
	sf::Music m_music;

};
