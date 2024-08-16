#include "Pacman.h"
#include <iostream>

Pacman::Pacman()
	: m_attackLen(0),
	ps(std::make_unique<NormalPacmanState>()),
	m_playerScore(0),
	m_superPacmanTime(0),
	m_shakeScreenLen(0),
	m_specialAttack(false)

{
	initPacman();
	setSpeed(2);
}
//update the pacman position and the original one
//-------------------------------------------
void Pacman::setPosition(const sf::Vector2f& position)
{
	setOriginalPosition(position);
	setPositionSprite(position);
}
// will init the pacman class members
//---------------------------------------------
void Pacman::initPacman()
{
	m_dashSound.setBuffer(DataManger::instence().getGameMusic().dashSound);
	m_attackSound.setBuffer(DataManger::instence().getGameMusic().attackSound);
	m_transformSound.setBuffer(DataManger::instence().getGameMusic().transformSound);
	initBarSprites();
	setTexture(DataManger::instence().getGameTexture().pacman);
	m_dashTime = 350;
	setRecTangle(); //for animation
}
//will init the Pacman skills bar with texutre and position
//-----------------------------------------
void Pacman::initBarSprites()
{
	m_DashBar.setTexture(DataManger::instence().getGameTexture().dash);
	m_superPacmanBar.setTexture(DataManger::instence().getGameTexture().superPacmanBar);
	m_DashBar.setTextureRect(sf::IntRect(0, 0, 50, 40));
	m_superPacmanBar.setTextureRect(sf::IntRect(0, 0, 50, 40));
}

// will move the pacman, this function is clocked based each
// call is a "step", the function recive speed from the state 
// and diraction from user
//--------------------------------------------
void Pacman::move(const sf::Time& deltaTime)
{
	handleStep(deltaTime);
	setSpeed(ps->getSpeed());
	if (ps->movePacman(*this))
		moveSprite(getDiraction(), getSpeed());
}

// the function will handle the time counters of
// the class, such as superPacman time and Dash time
// will also update the animation and pacman skills
//--------------------------------------------
void Pacman::handleStep(const sf::Time& deltaTime)
{
	if (ps->isSuper())
	{
		m_superPacmanTime--;
		if (m_superPacmanTime < 0)
			backToNormal();
	}
	setLastPosition(getPosition());
	DataManger::instence().updatePacmanPosition(getPosition());
	if (m_dashTime < 350)
		m_dashTime += 1;
	handleRectable(deltaTime); //animation
	updateBars(); //game skill bars
}
//this function will handle key from user and set the pacman diraction 
// accordingly, will also handle the dash key
//--------------------------------------------
bool Pacman::handleKey()
{
	static bool right = false;
	static bool dash = false;
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) || //if dash is enable
		(sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt))) &&
		(m_dashTime >= 350 || dash))
	{
		if (m_dashTime == 350)
			m_dashSound.play();
		setSpeed(4);
		m_dashTime -= 20;
		if (m_dashTime > 0)
			dash = true;
		else
		{
			dash = false;
			m_dashTime = 0;
		}
	}
	else
	{
		dash = false;
		setSpeed(2);
	}
	// this is the diraction section
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{

		setScale(1, 1); // turn the pacman to the right
		setDiraction(sf::Vector2f(-1, 0));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		setScale(-1, 1); //turn the pacman left
		setDiraction(sf::Vector2f(1, 0));

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		setDiraction(sf::Vector2f(0, -1));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		setDiraction(sf::Vector2f(0, 1));
	else
		return false;
	return true;

}

//-----------------------------------------------
bool Pacman::isSuperPacmanAttack() const
{
	return ps->getAttack();
}
//this function will handle user keyboard input of attack
// will be called only in super-pacman mode
//-----------------------------------------------
bool Pacman::superPacmanAttack()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || ps->getAttack())
	{
		if (m_attackLen == 100)
			m_attackSound.play();
		if (m_attackLen > 0)
		{
			SetTopRectangle(100); //animation of attacking super-pacman
			m_attackLen--;
			return true;
		}
		else if (m_attackLen == 0)
		{
			m_attackLen = 100;
			SetTopRectangle(50); // the attack is over
		}
	}
	return false;
}
//return if the pacman is in super-pacman mode
//-----------------------------------
bool Pacman::isSuper() const
{
	return(ps->isSuper());
}
// will make the pacman a superPacman
//----------------------------------
void Pacman::makeSuper()
{
	m_transformSound.play();
	m_superPacmanTime = 700;
	SetTopRectangle(50);
	setSpeed(3);
	ps.reset(new SuperPacmanState());
}
// return to normal pacman
//---------------------------------------
void Pacman::backToNormal()
{
	setSpeed(2);
	SetTopRectangle(0);
	ps.reset(new NormalPacmanState());
}
//will return if the pacman collide with demon
//--------------------------------------
bool Pacman::handleCollision(GameObj& gameoObj)
{
	return gameoObj.handleCollision(*this);
}

//--------------------------------------
bool Pacman::handleCollision(Pacman& gameObj)
{
	(void)gameObj; // for avoid warning
	return false;
}
// will return true if the pacman needs to dey, will also kill
// the demon if was attacking in the collision in super-pacman mode
//---------------------------------------
bool Pacman::handleCollision(Demon& gameObj)
{
	if (!ps->getAttack() && !gameObj.isDead())
	{
		playSound(DataManger::instence().getGameMusic().hurtSound);
		if (DataManger::instence().getLives() == 1)
			playSound(DataManger::instence().getGameMusic().byebyeSound);
	}
	return (!gameObj.isDead() && ps->handleDemonCollision());
}
// super-pacman can break wall will return if the door is broken
//---------------------------------------
bool Pacman::handleCollision(Door& gameObj)
{
	(void)gameObj; // for avoid warning
	bool toBreak = ps->handleDoorCollision();
	if (!toBreak)
		objectBlocked();
	return toBreak;
}

//---------------------------------------
bool Pacman::handleCollision(Key& gameObj)
{
	(void)gameObj; // for avoid warning
	playSound(DataManger::instence().getGameMusic().keySound);
	DataManger::instence().addToScore(7);
	return false;
}

//--------------------------------------
bool Pacman::handleCollision(Present& gameObj)
{
	(void)gameObj; // for avoid warning
	DataManger::instence().addToScore(5);
	return false;
}

//----------------------------------------
bool Pacman::handleCollision(Cookie& gameObj)
{
	(void)gameObj; // for avoid warning
	playSound(DataManger::instence().getGameMusic().coockieSound);
	DataManger::instence().addToScore(2);
	DataManger::instence().decCookie();
	return false;
}
//-----------------------------------------
bool Pacman::handleCollision(Wall& gameObj)
{
	(void)gameObj; // for avoid warning
	objectBlocked();
	return false;
}
// will update the skill bars animation in every step
// according to the time that have passed since the skill was activited
//---------------------------------------
void Pacman::updateBars()
{
	static int currentSuper = 0;
	static int currentDash = 6;
	int newSuper = m_superPacmanTime / 100;
	int newDash = m_dashTime / 50;
	if (currentSuper != newSuper)
	{
		newSuper *= 50;
		newSuper -= 50;
	}
	if (currentDash != newDash)
	{
		newDash *= 50;
		newDash -= 50;
	}
	m_superPacmanBar.setTextureRect(sf::IntRect(newSuper, 0, 50, 40)); //for animation
	m_DashBar.setTextureRect(sf::IntRect(newDash, 0, 50, 40));  //for animation
	currentDash = newDash;
	currentSuper = newSuper;

}
//-----------------------------------------
void Pacman::drawBars(sf::RenderWindow& window)
{
	shakeScreen(window);
	m_DashBar.setPosition(DataManger::instence().getLastDataPosition().x,
		DataManger::instence().getLastDataPosition().y);
	m_superPacmanBar.setPosition(m_DashBar.getPosition().x + 40, m_DashBar.getPosition().y);
	window.draw(m_superPacmanBar);
	window.draw(m_DashBar);
}

//--------------------------------------------------
bool Pacman::isSpacielAttack()
{
	if (m_specialAttack)
		spacielAttack();
	return m_specialAttack;
}

//---------------------------------------------------
void Pacman::setSpecialAttack(const bool& isSpacielAttack)
{
	m_specialAttack = isSpacielAttack;
}
//this function will be called when the player is preforming somthing
// unordinary, the function will recive the window and will move the position 
// of the screen to add shake effect, will hold 60 frames
//---------------------------------------------------
void Pacman::shakeScreen(sf::RenderWindow& window)
{
	sf::Vector2i statingPoint = DataManger::instence().getWindowPosition();
	if (m_shakeScreenLen == 0)
	{
		window.setPosition(statingPoint);
		m_shakeScreenLen--;
		return;
	}
	else if (m_shakeScreenLen == -1)
		return;
	else
	{
		window.setPosition(sf::Vector2i(statingPoint.x + rand() % 25,
			statingPoint.y + rand() % 25));
		m_shakeScreenLen--;
	}
}
//---------------------------------------------------
void Pacman::spacielAttack()
{
	playSound(DataManger::instence().getGameMusic().scream);
	m_shakeScreenLen = 60;
}