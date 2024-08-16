#include "Board.h"

Board::Board()
	:m_gameSizeCol(0),
	 m_gameSizeRow(0)
{
}

//Initializes the board's variables
//Creates the objects from the file and puts them into vectors
// also update the size of the window 
//------------------------------------------------------------
void Board::initBoard(float& windowRow, float& windowCol, LevelType type)
{
	if (type == NEXT_LEVEL)
	{
		if (m_level.nextLevel(windowRow, windowCol))
		{
			m_gameSizeRow = windowRow;
			m_gameSizeCol = windowCol;
			m_backround.initBackRound(m_gameSizeCol, m_gameSizeRow);// for Place the board background
		}
		
		windowRow += 50;
	}
	m_level.fillFromStr(&m_objects,&m_demons ,m_player); //creat the objects and update the vectors
}

//The main move func that moves the dynamic objects on the board
// Checking which collisions were in the move
//-------------------------------------------------------------
void Board::moveObj(const sf::Time& deltaTime)
{
	// check if in the last move the pacman collide with the kill demons present
	if (m_player.isSpacielAttack())  
		killAllDemons(); // kill al the demons for few seconds and shaking the window
	DataManger::instence().getTime().handleTime(deltaTime);// updating the clock string 
	m_player.move(deltaTime);// call to pacman move func
	handleCollisions(m_player);
	for (int i = 0; i < m_demons.size(); i++)
	{
		m_demons[i]->move(deltaTime);
		handleCollisions(*m_demons[i]);
	}
}
//The main object drawing function
//Calls the drawing function of all objects on the board
//-------------------------------------------------------------
void Board::draw(sf::RenderWindow& window)
{
	m_backround.draw(window);
	for (size_t i = 0; i < m_objects.size(); i++)
	{
		if (m_objects[i] != nullptr)
			m_objects[i]->draw(window);
	}
	for (size_t i = 0; i < m_demons.size(); i++)
	{
		if (m_demons[i] != nullptr)
			m_demons[i]->draw(window);
	}
	m_player.draw(window);
	DataManger::instence().drawText(window);
	m_player.drawBars(window);
}

//This function handles collision of objects in the board in the form of double dispatch
//--------------------------------------------------------------
void Board::handleCollisions(DynamicObj& gameObject)
{
	if (m_backround.isCollideWithBounds(gameObject))//bounds collision
		gameObject.objectBlocked();
	if (gameObject.checkCollision(m_player))
	{
		gameObject.handleCollision(m_player);
	}
	for (auto& demon : m_demons) // check if was a collision of each demon
	{
		if (gameObject.checkCollision(*demon))
		{
			if (gameObject.handleCollision(*demon))
			{
				setDefualt(); // only the pacman can return true so he died
				break;
			}
		}
	}
	int i = 0;
	for (auto& staticObjects : m_objects)// check collision with the static objects
	{
		if (gameObject.checkCollision(*staticObjects))
		{
			if (gameObject.handleCollision(*staticObjects))
			{
				// check if it was a key we need to delete both 
				bool key = typeid(Key) == typeid(*staticObjects);  
				m_objects.erase(m_objects.begin() + i);
				if (key)
					deleteDoor();
				break;
			}
		}
		i++;
	}
}

//find the first door object and deletes it 
//-------------------------------------------------------
void Board::deleteDoor()
{
	for (int i = 0; i < m_objects.size(); i++)
	{
		if (typeid(Door) == typeid(*m_objects[i]))
		{
			m_objects.erase(m_objects.begin() + i);
			break;
		}
	}
}

//When Pacman collides with an demon, we have to take a life from him
//  and return al the dynamic objects to the starting place of the level
//---------------------------------------------------
void Board::setDefualt()
{
	DataManger::instence().diedOnce();
	std::this_thread::sleep_for(std::chrono::milliseconds(350));
	m_player.backToOriginal();
	for (int i = 0; i < m_demons.size(); i++)
	{
		m_demons[i]->backToOriginal();
	}
}

// called from the controller when need up to the next level
//  or just clear the vectors according the leveltype
//-------------------------------------------------
void Board::changelevel()
{
	m_objects.clear();
	m_demons.clear();
}

// when the pacman collide wuth kill pacman present
//-----------------------------------------
void Board::killAllDemons()
{
	for (int i = 0; i < m_demons.size(); i++)
	{
		m_demons[i]->beDead();
	}
	m_player.setSpecialAttack(false);
}

