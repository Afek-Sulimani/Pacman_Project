#include "MusicManager.h"

//---------------------------------------
void MusicManager::loadMusic()
{
	m_music.openFromFile("PacmanMusic.ogg");
	keySound.loadFromFile("keySound.wav");
	attackSound.loadFromFile("attack.ogg");
	transformSound.loadFromFile("transform.ogg");
	coockieSound.loadFromFile("coockieSound.wav");
	presentSound.loadFromFile("presentSound.wav");
	dashSound.loadFromFile("dash.ogg");
	hurtSound.loadFromFile("hurt.ogg");
	m_transitionMusic.openFromFile("transitionMusic.ogg");
	byebyeSound.loadFromFile("byebye.wav");
	scream.loadFromFile("scream.ogg");
}

// initilaize the param of the music manager
//----------------------------------------------
void MusicManager::initMusic()
{
	loadMusic();
	m_music.setLoop(true);
	m_music.setVolume(60);
	m_transitionMusic.setLoop(true);
	m_transitionMusic.setVolume(60);
}
//-----------------------------------------------
void MusicManager::startGameMusic()
{
	m_music.play();
}
//-----------------------------------------------
void MusicManager::stopGameMusic()
{
	m_music.stop();
}
//------------------------------------------------
void MusicManager::stopTransitionMusic()
{
	m_transitionMusic.stop();
}
//-----------------------------------------------
void MusicManager::startTrasitionMusic()
{
	m_transitionMusic.play();
}
//------------------------------------------------
void MusicManager::OpenWinMusic()
{
	m_transitionMusic.openFromFile("winmusic.ogg");
}