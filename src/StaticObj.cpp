#include "StaticObj.h"

//all the func of the collision return false
//Because they are not affected by the static objects

//---------------------------------------
bool StaticObj::handleCollision(GameObj& gameObj) 
{
	(void)gameObj; // to avoid warning 
	return false;
}
//----------------------------------------
bool StaticObj::handleCollision(Door& gameObj) 
{
	(void)gameObj; // to avoid warning 
	return false;
}
//----------------------------------------
bool StaticObj::handleCollision(Key& gameObj) 
{
	(void)gameObj; // to avoid warning 
	return false;
}
//----------------------------------------
bool StaticObj::handleCollision(Present& gameObj) 
{
	(void)gameObj; // to avoid warning
	return false;
}
//----------------------------------------
bool StaticObj::handleCollision(Wall& gameObj) 
{
	(void)gameObj; // to avoid warning
	return false;
}
//----------------------------------------
bool StaticObj::handleCollision(Cookie& gameObj)
{
	(void)gameObj; // to avoid warning
	return false;
}