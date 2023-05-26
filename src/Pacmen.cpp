#include "Pacmen.h"
#include <iostream>

Pacmen::Pacmen()
	: m_attackLen(0),
	ps(std::make_unique<NormalPacmenState>()),
	m_playerScore(0),
	m_superPacmenTime(0),
	m_shakeScreenLen(0),
	m_specialAttack(false)

{
	initPacmen();
	setSpeed(2);
}
//update the pacmen position and the original one
//-------------------------------------------
void Pacmen::setPosition(const sf::Vector2f& position)
{
	setOriginalPosition(position);
	setPositionSprite(position);
}
// will init the pacmen class members
//---------------------------------------------
void Pacmen::initPacmen()
{
	m_dashSound.setBuffer(DataManger::instence().getGameMusic().dashSound);
	m_attackSound.setBuffer(DataManger::instence().getGameMusic().attackSound);
	m_transformSound.setBuffer(DataManger::instence().getGameMusic().transformSound);
	initBarSprites();
	setTexture(DataManger::instence().getGameTexture().pacmen);
	m_dashTime = 350;
	setRecTangle(); //for animation
}
//will init the Pacmen skills bar with texutre and position
//-----------------------------------------
void Pacmen::initBarSprites()
{
	m_DashBar.setTexture(DataManger::instence().getGameTexture().dash);
	m_superPacmenBar.setTexture(DataManger::instence().getGameTexture().superPacmenBar);
	m_DashBar.setTextureRect(sf::IntRect(0, 0, 50, 40));
	m_superPacmenBar.setTextureRect(sf::IntRect(0, 0, 50, 40));
}

// will move the pacmen, this function is clocked based each
// call is a "step", the function recive speed from the state 
// and diraction from user
//--------------------------------------------
void Pacmen::move(const sf::Time& deltaTime)
{
	handleStep(deltaTime);
	setSpeed(ps->getSpeed());
	if (ps->movePacmen(*this))
		moveSprite(getDiraction(), getSpeed());
}

// the function will handle the time counters of
// the class, such as superPacmen time and Dash time
// will also update the animation and pacmen skills
//--------------------------------------------
void Pacmen::handleStep(const sf::Time& deltaTime)
{
	if (ps->isSuper())
	{
		m_superPacmenTime--;
		if (m_superPacmenTime < 0)
			backToNormal();
	}
	setLastPosition(getPosition());
	DataManger::instence().updatePacmenPosition(getPosition());
	if (m_dashTime < 350)
		m_dashTime += 1;
	handleRectable(deltaTime); //animation
	updateBars(); //game skill bars
}
//this function will handle key from user and set the pacmen diraction 
// accordingly, will also handle the dash key
//--------------------------------------------
bool Pacmen::handleKey()
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

		setScale(1, 1); // turn the pacmen to the right
		setDiraction(sf::Vector2f(-1, 0));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		setScale(-1, 1); //turn the pacmen left
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
bool Pacmen::isSuperPacmenAttack() const
{
	return ps->getAttack();
}
//this function will handle user keyboard input of attack
// will be called only in super-pacmen mode
//-----------------------------------------------
bool Pacmen::superPacmenAttack()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || ps->getAttack())
	{
		if (m_attackLen == 100)
			m_attackSound.play();
		if (m_attackLen > 0)
		{
			SetTopRectangle(100); //animation of attacking super-pacmen
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
//return if the pacmen is in super-pacmen mode
//-----------------------------------
bool Pacmen::isSuper() const
{
	return(ps->isSuper());
}
// will make the pacmen a superPacmen
//----------------------------------
void Pacmen::makeSuper()
{
	m_transformSound.play();
	m_superPacmenTime = 700;
	SetTopRectangle(50);
	setSpeed(3);
	ps.reset(new SuperPacmenState());
}
// return to normal pacmen
//---------------------------------------
void Pacmen::backToNormal()
{
	setSpeed(2);
	SetTopRectangle(0);
	ps.reset(new NormalPacmenState());
}
//will return if the pacmen collide with demon
//--------------------------------------
bool Pacmen::handleCollision(GameObj& gameoObj)
{
	return gameoObj.handleCollision(*this);
}

//--------------------------------------
bool Pacmen::handleCollision(Pacmen& gameObj)
{
	(void)gameObj; // for avoid warning
	return false;
}
// will return true if the pacmen needs to dey, will also kill
// the demon if was attacking in the collision in super-pacmen mode
//---------------------------------------
bool Pacmen::handleCollision(Demon& gameObj)
{
	if (!ps->getAttack() && !gameObj.isDead())
	{
		playSound(DataManger::instence().getGameMusic().hurtSound);
		if (DataManger::instence().getLives() == 1)
			playSound(DataManger::instence().getGameMusic().byebyeSound);
	}
	return (!gameObj.isDead() && ps->handleDemonCollision());
}
// super-pacmen can break wall will return if the door is broken
//---------------------------------------
bool Pacmen::handleCollision(Door& gameObj)
{
	(void)gameObj; // for avoid warning
	bool toBreak = ps->handleDoorCollision();
	if (!toBreak)
		objectBlocked();
	return toBreak;
}

//---------------------------------------
bool Pacmen::handleCollision(Key& gameObj)
{
	(void)gameObj; // for avoid warning
	playSound(DataManger::instence().getGameMusic().keySound);
	DataManger::instence().addToScore(7);
	return false;
}

//--------------------------------------
bool Pacmen::handleCollision(Present& gameObj)
{
	(void)gameObj; // for avoid warning
	DataManger::instence().addToScore(5);
	return false;
}

//----------------------------------------
bool Pacmen::handleCollision(Cookie& gameObj)
{
	(void)gameObj; // for avoid warning
	playSound(DataManger::instence().getGameMusic().coockieSound);
	DataManger::instence().addToScore(2);
	DataManger::instence().decCookie();
	return false;
}
//-----------------------------------------
bool Pacmen::handleCollision(Wall& gameObj)
{
	(void)gameObj; // for avoid warning
	objectBlocked();
	return false;
}
// will update the skill bars animation in every step
// according to the time that have passed since the skill was activited
//---------------------------------------
void Pacmen::updateBars()
{
	static int currentSuper = 0;
	static int currentDash = 6;
	int newSuper = m_superPacmenTime / 100;
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
	m_superPacmenBar.setTextureRect(sf::IntRect(newSuper, 0, 50, 40)); //for animation
	m_DashBar.setTextureRect(sf::IntRect(newDash, 0, 50, 40));  //for animation
	currentDash = newDash;
	currentSuper = newSuper;

}
//-----------------------------------------
void Pacmen::drawBars(sf::RenderWindow& window)
{
	shakeScreen(window);
	m_DashBar.setPosition(DataManger::instence().getLastDataPosition().x,
		DataManger::instence().getLastDataPosition().y);
	m_superPacmenBar.setPosition(m_DashBar.getPosition().x + 40, m_DashBar.getPosition().y);
	window.draw(m_superPacmenBar);
	window.draw(m_DashBar);
}

//--------------------------------------------------
bool Pacmen::isSpacielAttack()
{
	if (m_specialAttack)
		spacielAttack();
	return m_specialAttack;
}

//---------------------------------------------------
void Pacmen::setSpecialAttack(const bool& isSpacielAttack)
{
	m_specialAttack = isSpacielAttack;
}
//this function will be called when the player is preforming somthing
// unordinary, the function will recive the window and will move the position 
// of the screen to add shake effect, will hold 60 frames
//---------------------------------------------------
void Pacmen::shakeScreen(sf::RenderWindow& window)
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
void Pacmen::spacielAttack()
{
	playSound(DataManger::instence().getGameMusic().scream);
	m_shakeScreenLen = 60;
}