**Super Pacman Project**

**Developer:** Afek Sulimani

**Project Overview**\
This project implements a dynamic and interactive "Super Pacman" game using advanced C++ programming techniques.
The game introduces players to various levels,
 challenging them with time constraints and enhanced gameplay mechanics through intelligent enemy behavior and player abilities.
[Demo video](https://github.com/user-attachments/assets/1917c1f4-1779-4b25-a22f-6face5e39c55)

**Game Description**\
Upon launching, players are greeted with a menu offering options to start the game, learn about gameplay elements, or exit.
The game progresses through multiple levels, escalating in difficulty.
Each level must be completed within a set time, failing which the player must retry.
Advancement is based on consuming all on-screen cookies.

**Game Features:**
-	Multi-level Gameplay: Managed through Playlist.txt which lists all levels and their time limits.

-	Real-time Mechanics: The game operates in real-time without queued actions, enhancing responsiveness.

-	Enhanced Abilities: Players can access special modes and abilities, such as dash and super modes, enhancing gameplay interaction.

-	Object Interaction: Dynamic interaction with game objects like doors and keys, with unique behaviors in different game states.

**Key Technologies**

-	Polymorphism: Used extensively for character state management and dynamic object behaviors.

-	Double Dispatch: Critical for handling collisions uniquely between different game objects, enhancing the game's interaction logic.

****Game Components****

**Controller**
-	Manages game state transitions, level changes, and time-based game events.
**Menu**\
-	Handles user interactions for game start, information display, and exit.
**Board**\
-	Manages all game objects using vectors of unique pointers, facilitating efficient collision handling and object lifecycle management.
**GameObj**
-	Abstract base class for all static objects (key, door, present, cookie, pacman, wall), managing their sprites and interactions.
**DynamicObj**\
-	Inherits from GameObj, adding functionalities for animation and movement, forming the base for dynamic characters like Pacman and Demon.
**Pacman & Demon States**\
-	Implement state design patterns to alter behaviors based on current state (e.g., normal, super, dead).
**DataManager**\
-	Central component for handling game data, interfacing with peripheral managers like MusicManager and TimeManager.

**Collision Handling**\
Leverages double dispatch to execute appropriate collision responses, supported by the polymorphic nature of game objects, ensuring robust and scalable interaction logic.

**Adding Levels**\
New levels can be integrated by using the provided level editor and updating Playlist.txt to include new level configurations.

**Running the Game**\
The game is compiled and run using CMake, ensuring platform-independent build configuration.

**Conclusion**\
This Super Pacman game showcases advanced C++ features and design patterns, delivering a rich and engaging gameplay experience.
It serves as a robust example of modern game development techniques in C++.
