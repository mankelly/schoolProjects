/****************************************************************
File:			main.cpp
Description:	Link's Adventure!
Author:			Manuel Kelly
Class:			CSCI 120
Date:			3/21/2018
I hereby certify that this program is entirely my own work.
*****************************************************************/


/****************************************************************
PLEASE READ BEFORE PLAYING!

You want to collect as many chest as possible as quickly as possible.
Bombs are traps and will take points away from your score.
The Triforce entity is YOUR destination!

ENJOY!
*****************************************************************/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <vector>
#include "Entity.h"
#include "Prize.h"
#include "Trap.h"
#include <sstream>

using namespace std;

const int NUM_HORIZONTAL = 15;	// number of adventure game sprites horizontally tiled
const int NUM_VERTICAL = 10;	// number of adventure game sprites vertically tiled
const int SIZE_SPRITE = 48;		// size of a sprite (square)
const int WIDTH = SIZE_SPRITE * NUM_HORIZONTAL;	// width of the game window
const int HEIGHT = SIZE_SPRITE * (NUM_VERTICAL + 2);	// height of the game window (including score and message board)
string message = ""; // message is initialized to output to screen
int z = 0; // z is an integer that stores the current score diplayed
float  totalTime = 0; // totalTime initialized to later pass onto getScoreUpdate function

enum Direction { NONE, UP, DOWN, LEFT, RIGHT };

/*
* Determines and returns the type of collision between a player and another entity
* in a given vector. The location is based on the current position of the player
* moving towards the given direction of movement. In the case of colliding with
* a prize entity, the entity is removed from the vector.
* @param entityPtrVector vector containing pointers to entities in the game
* @param x x-coordinate of the current player location
* @param y y-coordinate of the current player location
* @param dir direction of the player movement
*/
EntityType checkCollision(Entity* entityPtrGrid[NUM_HORIZONTAL][NUM_VERTICAL], int x, int y, Direction dir) {
	if (dir == UP) {
		y--;
	}
	else if (dir == DOWN) {
		y++;
	}
	else if (dir == LEFT) {
		x--;
	}
	else if (dir == RIGHT) {
		x++;
	}
	if (x >= 0 && y >= 0 && x < NUM_HORIZONTAL && y < NUM_VERTICAL && entityPtrGrid[x][y] != NULL) {
		Entity* entity = entityPtrGrid[x][y];
		message = entityPtrGrid[x][y]->say();
		if (entity->getType() == PRIZE) {
		
			// adds the score update from the entity to the integer z which holds the score
			z = z + entityPtrGrid[x][y]->getScoreUpdate(totalTime);

			// if score is negative, z resets itself to 0
			if (z < 0)
				z = 0;

			delete entity;
			entityPtrGrid[x][y] = NULL;
			return PRIZE;
		}

		if (entity->getType() == TRAP) {

			// adds the score update from the entity to the integer z which holds the score
			z = z + entityPtrGrid[x][y]->getScoreUpdate(totalTime);

			// if score is negative, z resets itself to 0
			if (z < 0)
				z = 0;

			delete entity;
			entityPtrGrid[x][y] = NULL;
			return TRAP;
		}

		// deletes the DESTINATION entity when the user collides with it
		if (entity->getType() == DESTINATION) {
			sf::SoundBuffer winSoundBuffer;
			winSoundBuffer.loadFromFile("resources/win.wav");
			sf::Sound winSound(winSoundBuffer);
			winSound.play();
			delete entity;
			entityPtrGrid[x][y] = NULL;
			return DESTINATION;
		}
		
		else {
			message = entityPtrGrid[x][y]->say();
			return entityPtrGrid[x][y]->getType();
		}
	}

	return UNKNOWN;
}

int main()
{
	Entity* entityPtrGrid[NUM_HORIZONTAL][NUM_VERTICAL]; // vector containing all game entities (player, prizes, walls)

	for (int i = 0; i < NUM_HORIZONTAL; ++i)
		for (int j = 0; j < NUM_VERTICAL; ++j)
			entityPtrGrid[i][j] = NULL;

	srand((unsigned int)time(0));

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "CSCI 120 - Link's Adventure Project");

	// create player entity
	Entity player(0, 0, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Link.png", PLAYER);
	entityPtrGrid[0][0] = &player;

	// create 5 prize entities
	int x, y;

	// use a for loop to create 5 Prize entities
	for (int p = 0; p < 5; p++) {
		bool prizeCheck = false;

		while (prizeCheck == false) {
			x = rand() % NUM_HORIZONTAL;
			y = rand() % NUM_VERTICAL;

			if (entityPtrGrid[x][y] == NULL) {
				entityPtrGrid[x][y] = new Prize(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Chest.gif", PRIZE, 9, "Message: Rupees!!");
				prizeCheck = true;
			}
		}
	}
	
	// create 5 trap entites
	// use a for loop to create 5 Trap entities
	for (int p = 0; p < 5; p++) {
		bool trapCheck = false;

		while (trapCheck == false) {
			x = rand() % NUM_HORIZONTAL;
			y = rand() % NUM_VERTICAL;

			if (entityPtrGrid[x][y] == NULL) {
				entityPtrGrid[x][y] = new Trap(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/bomb.png", TRAP, 3, "Message: Your leg has been blown away!!");
				trapCheck = true;
			}
		}
	}

	// create wall entities
	// use a for loop to create 20 Wall entities
	for (int p = 0; p < 20; p++) {
		bool wallCheck = false;

		while (wallCheck == false) {
			x = rand() % NUM_HORIZONTAL;
			y = rand() % NUM_VERTICAL;

			if (entityPtrGrid[x][y] == NULL) {
				entityPtrGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/wall.png", WALL);
				wallCheck = true;
			}
		}
	}

	// create destination entity
	// use a for loop to create a wanted amount of destination entities
	// this case uses 1 destination entity
	for (int p = 0; p < 1; p++) {
		bool destinationCheck = false;

		while (destinationCheck == false) {
			x = rand() % NUM_HORIZONTAL;
			y = rand() % NUM_VERTICAL;

			if (entityPtrGrid[x][y] == NULL) {
				entityPtrGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Tri.png", DESTINATION);
				destinationCheck = true;
			}
		}
	}


	// load background sprite
	sf::Texture texture;
	if (!texture.loadFromFile("resources/background.png"))
	{
		cout << "Error loading background";
		return EXIT_FAILURE;
	}
	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(texture);

	// load the text font
	sf::Font font;
	if (!font.loadFromFile("resources/Quicksand-Regular.otf")) {
		cout << "cannot open font";
		sf::sleep(sf::seconds(5));
		return EXIT_FAILURE;
	}

	// initialize score board
	sf::Text scoreBoard;
	scoreBoard.setFont(font);
	scoreBoard.setCharacterSize(25);
	scoreBoard.setPosition(10.f, (NUM_VERTICAL + 1) * SIZE_SPRITE); // at the bottom of the window
	scoreBoard.setFillColor(sf::Color::Black);
	scoreBoard.setString("Score: 0");

	// initialize message board
	sf::Text messageBoard;
	messageBoard.setFont(font);
	messageBoard.setCharacterSize(25);
	messageBoard.setPosition(10.f, NUM_VERTICAL * SIZE_SPRITE); // at the bottom of the window
	messageBoard.setFillColor(sf::Color::Blue);
	messageBoard.setString("Message: none.");

	// load the sound used in the game
	sf::SoundBuffer backgroundSoundBuffer;
	if (!backgroundSoundBuffer.loadFromFile("resources/LostWoods.wav")) {
		std::cout << "cannot open audio";
		sf::sleep(sf::seconds(5));
		return EXIT_FAILURE;
	}
	sf::Sound backgroundSound(backgroundSoundBuffer);
	backgroundSound.play(); // play background music


	// timer for time delays
	sf::Clock clock;
	float timer = 0, delay = 0.2;

	Direction dir = NONE; // direction of player move

						  // main game loop
	// isPlaying is used when user is playing the game
	bool isPlaying = true;
	while (window.isOpen())
	{
		// if statement to allow processes to happen if isPlaying is true
		if (isPlaying) {
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		totalTime += time; //totalTime is passed onto getScoreUpdate function as timeDelay

		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed) // close button
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { // left key
			dir = LEFT;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { // right key
			dir = RIGHT;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { // up key
			dir = UP;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { // down key
			dir = DOWN;
		}

		if (timer > delay) { // time delay to accomodate user key input 
			timer = 0;

			// check for collision
			EntityType collisionType = checkCollision(entityPtrGrid, player.getX(), player.getY(), dir);
			if (collisionType == PRIZE) {
				messageBoard.setString(message);
				// uses a string stream to create a string with both the phrase "Score: " and the integer z that holds the score
				stringstream ss;
				ss << "Score: " << z;
				// outputs string stream to scoreBoard
				scoreBoard.setString(ss.str());
			}
			if (collisionType == TRAP) {
				messageBoard.setString(message);
				// uses a string stream to create a string with both the phrase "Score: " and the integer z that holds the score
				stringstream ss;
				ss << "Score: " << z;
				// outputs string stream to scoreBoard
				scoreBoard.setString(ss.str());
			}
			if (collisionType == DESTINATION) {
				isPlaying = false;
			}
								   // update player position based on direction
			if (collisionType != WALL) {
				entityPtrGrid[player.getX()][player.getY()] = NULL;
				if (dir == UP) {
					player.moveUp();
				}
				else if (dir == DOWN) {
					player.moveDown();
				}
				else if (dir == LEFT) {
					player.moveLeft();
				}
				else if (dir == RIGHT) {
					player.moveRight();
				}
				entityPtrGrid[player.getX()][player.getY()] = &player;
				dir = NONE;
			}
		}

		// draw game interface
		// checks if playing to know which screen output to use
		
			window.clear();
			window.draw(backgroundSprite); // display background
			window.draw(scoreBoard); // display score board
			window.draw(messageBoard); // display message board

									   // draw all adventure game sprites
			for (int i = 0; i < NUM_HORIZONTAL; ++i)
				for (int j = 0; j < NUM_VERTICAL; ++j)
				{
					Entity* entity = entityPtrGrid[i][j];
					if (entity != NULL) {
						sf::Sprite sprite = entity->getSprite();
						sprite.setPosition(i * SIZE_SPRITE, j * SIZE_SPRITE);
						window.draw(sprite);
					}
				}
		}
		// else statement if player is not playing. Does NOT let player move
		else {
			// creates a string stream to store a victory message
			stringstream win;
			win << "You win and have\nsaved Hyrule!\nHold Escape to exit\nYour score was: " << z;

			window.clear(); // clears the window
			window.draw(backgroundSprite); // display background

			sf::Text pauseMessage; // creates a vitory message

			// font, size, position and color of victory message
			pauseMessage.setFont(font);
			pauseMessage.setCharacterSize(40);
			pauseMessage.setPosition(170.f, 150.f);
			pauseMessage.setFillColor(sf::Color::White);

			// uses the win string stream to output a message to the screen
			pauseMessage.setString(win.str());
			window.draw(pauseMessage);
			
			// uses a while loop to check if the user wants to exit the game by pressing escape
			sf::Event event;
			while (window.pollEvent(event)) {
				if ((event.type == sf::Event::Closed) ||
					((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
				{
					window.close();
					break;
				}
			}
		}

		window.display();

	}

	return 0;
}