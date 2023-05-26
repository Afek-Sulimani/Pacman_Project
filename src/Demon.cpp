#include "Demon.h"
/*
* constracor for demon, will recive position and texture,
* will also make the uniqe ptr that holds the demon state
*/
//--------------------------------------------
Demon::Demon(const sf::Vector2f& position, const sf::Texture& texture)
	: ps(std::make_unique<NormalDemonState>()),
	m_deadTime(0)
{
	setOriginalPosition(position);
	setPositionSprite(position);
	initSprite(texture);
	setSpeed(2);
}
// will init the sprite with texutre and texture rectangle for animation 
//---------------------------------------------
void Demon::initSprite(const sf::Texture& texture)
{
	setTexture(texture);
	setRecTangle();
}
/*
* the move function of the demon, will use state function
* to cacualte where is the next position of the demon going to be
*/
//--------------------------------------------
void Demon::move(const sf::Time& deltaTime)
{
	if (ps->isDead())
	{
		m_deadTime--;  //the dead state is temporary, will be monitored
		if (m_deadTime < 0) //by the game clock 
			if (ps->isSmart())
				beSmart();
			else
				backToNormal();
	}
	setLastPosition(getPosition());
	handleRectable(deltaTime); //for animation
	setDiraction(ps->moveDemon(*this)); // move by the state function
	setSpeed(ps->getSpeed());
	moveSprite(getDiraction(), getSpeed());// *deltaTime.asSeconds());//deltaTime.asSeconds());
}

// will return true only if the demon collide 
// with pacmen and the pacmen needs to die
//-----------------------------------------------
bool Demon::handleCollision(GameObj& gameoObj)
{
	return gameoObj.handleCollision(*this);
}
//this function will handle collision with the pacmen,
// if the pacmen was attaking the demon, the demon will die
// will return to the pacmen if he was attacked by demon
//-----------------------------------------------
bool Demon::handleCollision(Pacmen& gameObj)
{
	if (gameObj.isSuperPacmenAttack() && !isDead())
	{
		beDead();
		DataManger::instence().addToScore(50); //player recive 50 points for 
	}											//killing demon
	return ps->handlePacmenCollision();
}
//Smart demon will not collide with other smart demon!
// this function will block the current demon.
// any other collision is acceptable
//---------------------------------------
bool Demon::handleCollision(Demon& gameObj)
{
	ps->setDemonBlock(false);
	if (ps->isSmart() && gameObj.isSmart())
	{
		objectBlocked();
		ps->setDemonBlock(true);
	}
	return false;
}
// will handle according to the demon state
//---------------------------------------
bool Demon::handleCollision(Door& gameObj)
{
	(void)gameObj; // for avoid warning 
	if (ps->handleDoorCollision())
	{
		ps->setDemonBlock(true);
		objectBlocked();
	}
	return false;
}
//---------------------------------------
bool Demon::handleCollision(Key& gameObj)
{
	(void)gameObj; // for avoid warning 
	return false;
}
//-------------------------------------
bool Demon::handleCollision(Cookie& gameObj)
{
	(void)gameObj; // for avoid warning 
	return false;
}


// smart demon can get one presert and become smart
// will return if the present needs to disapper
//--------------------------------------
bool Demon::handleCollision(Present& gameObj)
{
	(void)gameObj; // for avoid warning 
	bool was_Normal = !ps->isSmart();
	if (was_Normal)
		beSmart();
	return (was_Normal);
}
//-----------------------------------------
bool Demon::handleCollision(Wall& gameObj)
{
	(void)gameObj; // for avoid warning 
	ps->setDemonBlock(true);
	objectBlocked();
	return false;
}
//this function will kill the demon and will
// keep the smart attribute
//-----------------------------------------
void Demon::beDead()
{
	m_deadTime = 200;
	if (ps->isDead())	
		return ;

	SetTopRectangle(100); //get new animation
	bool isSmart = ps->isSmart();
	ps.reset(new DeadDemonState()); //set new state
	ps->setSmart(isSmart);

}
//-----------------------------------------
void Demon::beSmart()
{
	SetTopRectangle(50);
	ps.reset(new SmartDemonState());
}

//-----------------------------------------
bool Demon::isDead() const
{
	return ps->isDead();
}

//-----------------------------------------
void Demon::backToNormal()
{
	setSpeed(1);
	SetTopRectangle(0);
	ps.reset(new NormalDemonState);
}
//--------------------------------------------
void Demon::setBlocked()
{
	ps->setDemonBlock(true);
}

//--------------------------------------------
/*
*  this will be another export move function of the demon
*  that will be used by the smart demon state, this algorithrm is
*  a bit more complicaed and will be able to close up to 2 diractions
*  of the demon and help him find better way to get to the pacmen
*/
//----------------------------------------------
void Demon::huntPacmen(int diraction1, int diraction2)
{
	sf::Vector2f PacmenPosition;
	PacmenPosition = (DataManger::instence().getPacmenPosition());
	float arr[4] = { 0 };
	int newDiraction = -1; // will be the new best diraction for the demon
	arr[DOWN] = caculateSIzeFromPacmen(0, -1);
	arr[UP] = caculateSIzeFromPacmen(0, 1);
	arr[RIGHT] = caculateSIzeFromPacmen(1, 0);
	arr[LEFT] = caculateSIzeFromPacmen(-1, 0);
	if (diraction1 != -1) // -1 in diraction means there is no closed way
		arr[diraction1] = -1;
	if (diraction2 != -1)
		arr[diraction2] = -1;
	for (int i = 0; i < 4; i++)
	{
		if (newDiraction == -1 && arr[i] > -1)
			newDiraction = i;
		else if (arr[i] > -1 && arr[i] < arr[newDiraction])
			newDiraction = i;
	}
	ps->setNewDirection(newDiraction);
	ps->setDemonBlock(false);
}

//caculate the range from the pacmen by sqrt(x^2 + y^2)
//------------------------------------------------------------
float Demon::caculateSIzeFromPacmen(int addToX, int addToY)
{
	sf::Vector2f PacmenPosition;
	PacmenPosition = (DataManger::instence().getPacmenPosition());
	int x = (int)abs(getPosition().x + addToX - PacmenPosition.x);
	int y = (int)abs(getPosition().y + addToY - PacmenPosition.y);
	return (float)sqrt((pow(x, 2) + pow(y, 2)));
}

//---------------------------------------------------------
bool Demon::isSmart() const
{
	return ps->isSmart();
}