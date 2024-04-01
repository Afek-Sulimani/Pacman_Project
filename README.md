***SuperPacmen project***
 Afek Sulimani , 211417035 
 The game is realized in cooperation with a partner

**explanation of the project:**
In this project we created a Super Pacmen game.
The game starts with an opening screen, The screen offers the user to start a game,
 read information about the game and exit, selection is made by clicking with the mouse on the wanted object.
Clicking on the information button will display all the game objects and their abilities.
Clicking the start button will load the first step file, and the game will begin.
There are few different levels, some with a countdown clock,
 if the user has not finished the level and the time has passed, he will have try again the level.
Level up in the game when the player has eaten all the cookies.
The game will end if the player dies 3 times and lost, or when the player finished all the levels of the game and won!.
The levels in the game are managed by a file called Playlist.txt which contains a number (how many levels in the game) and the names of all the levels by lines.
In our game we created 4 stages. To add a level, use the level editor we created in exercise 4, add the time of the level to it in the first line or 0 if there is no time.
And add it to the Cmakelist line.
The game is clock driven, every move is made in real-time, 
 there are no queue in this game. 
This means that some games will experience pacman who will be able to go faster , 
 as well as demons in the game there are 4 types of gifts which will be detailed on the opening screen.  
At any time in the game, except transition screens, the player's status will be displayed and will present: 
 The number of the level, 
 what is the player score, 
 how many lives he has left, 
 how much time has passed since the start of the game, 
 and (if the level is limited in time) how much time is left for the stage will also be displayed.
In addition there is animation of the SuperPacman and dash mode, that show the cooldown skills status.
In the game there are doors that will block the normal Pacman from passing through them, 
 in order to be able to pass through them, he can take a key that will open one door without knowing which one.
When the player is in super mode he will be able to break the doors without taking a key.
Pacman has a dash skill that allows him to dash for a few seconds. 
It can be activated  by using the ALT button.  
In addition, in super mode will the player be able to attack the demons and kill them. Using the Ctrl (LEFT) button.
Colliding with alive demon in attack mode will kill the demons .if attack mode is NOT activated the pacmen will die, even in super pacmen mode.
Any normal demon can take one gift (no matter what kind) ,And so they will become smart demon.
In smart mode they try to hunt the player and will becomes faster than normal,
They will be able to move throw doors.


**design:**

-	Controller: will control the game, will hold the game clock and will reset him after every 1.0 seconds, will also change levels, call the menu and close the game if asked.
-	Menu: will be responsible on the menu, the controller class have object of this class.
-	Board: will be responsible on the board itself, will hold a vector of unique ptr to base class GameObj, those will be used to handle collision with the dynamic obj.
        The class will also hold unique ptr to a demons objects and an object to the player (pacmen) class. 
        The class will be responsible to delete objects, handle them and reset the board if needed.  
-	GameObj, will be the base abstract class of the every object in the board 
-	(key, door, present, cookie, pacmen, and wall), the class will hold as a private member the sprite and will export functions that will handle this sprite (such as move, draw..) .
       The GameObj class declaring all the  pure virtual function of the HandleCollision between the GameObj objects.
-	DynamicObj will be another base abstract class of the dynamic object in this game, 
       this class will Inherit from the GameObj class and will also export functions of animations and other moving attributes.
-	Pacmen: will Inherit from the DynamicObj, is responsible on any attribute of the pacmen. 
       The pacmen will hold an unique ptr to the pacmen state base class which will use polymorphism to act according the current pacmen state
-	PacmenState: will be abstract base class of the pacmen state, will define function that will inform about the state,
	     and will act in different ways when colliding with demon and a door here are 2 pacmen states: super pacmen and normal pacmen.
-	Demon: will Inherit from the DynamicObj, is responsible on any attribute of the demon. 
       The demon will hold an unique ptr to the demon state base class which will use polymorphism to act according the current demon state
-	PacmenDemon: will be abstract  base class of the demon state, will define function that will inform about the state,
       and will act in different ways when colliding with pacmen and a door, will also move different (most of the state is for the different ways between the demons)
       There are 3 demon states: smart demon ,normal pacmen and dead demon(temporary).
-	staticObj: will inherit from the base class GameObj, most of this class purpose is to Implements  the collision between the static object collision on the board (they cannot collide)
-	Present: this will inherit from the staticObj, will hold a state for 4 different presents.
-	DataManger will manage most of the game-related information and data,
       will mostly receive information about the game and will export the information with public functions,
 	     the data manger will hold 2 private members of another managers, which are musicManger,
- TimeManger. Will also hold the gameTexture struct. 
-	The program is using a double dispatch so the game will be able to act differently between every collision, 
       the double dispatch is between the GameObj objects,
 	     and the collision function is called by the board that will call each of the moving objects HandleCollison function with any other object on the board,
 	     that will be possible by using polymorphism of the gameObj objects.
-	There are another 2 classes that we want elaborate about, and that are 
       Level: that reading a new level and saving the level information in a string, and backround that handle the backround of the board

