#include "GameTexture.h"


//load all the texture of the game
//------------------------------------
void GameTexture::loadTexture()
{
	cookie.loadFromFile("cookie.png");
	key.loadFromFile("key.png");
	door.loadFromFile("door.png");
	present.loadFromFile("present.png");
	present1.loadFromFile("present1.png");
	present2.loadFromFile("present2.png"); 
	present3.loadFromFile("present3.png"); 
	wall.loadFromFile("wall.png");
	demon[0].loadFromFile("demon1.png");
	demon[1].loadFromFile("demon2.png");
	demon[2].loadFromFile("demon3.png");
	demon[3].loadFromFile("demon4.png");
	demon[4].loadFromFile("demon5.png");
	upperRow.loadFromFile("upper.png");
	bottomRow.loadFromFile("bottom.png");
	leftRow.loadFromFile("left.png");
	rightRow.loadFromFile("right.png");
	gameBackround.loadFromFile("backround.png");
	upperBlock.loadFromFile("upperBlock.png");
	bottoBlock.loadFromFile("bottomBlock.png");
	pacmen.loadFromFile("pacmen3.png");
	pacmen.loadFromFile("pacmen3.png");
	hearts.loadFromFile("hearts.png");
	font.loadFromFile("C:/Windows/Fonts/Impact.ttf");
	dash.loadFromFile("dash1.png");
	superPacmenBar.loadFromFile("super1.png");
	transitionBoard.loadFromFile("transitionTexture.png");
	byebyeBoard.loadFromFile("lose.png");
	menu.loadFromFile("menu.png");
	wonBoard.loadFromFile("wingame.png");
	timeGoneBoard.loadFromFile("timegone.png");
}