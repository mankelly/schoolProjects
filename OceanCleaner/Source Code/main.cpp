/****************************************************************
File:			main.cpp
Description:	Ocean Adventure!
Author:			Manuel Kelly
Class:			CSCI 120
Date:			5/16/2018
I hereby certify that this program is entirely my own work.
*****************************************************************/


/****************************************************************
PLEASE READ BEFORE PLAYING!

The ocean has been ruined by toxic waste and trash. You want to 
collect as much trash as possible. The toxic slime entities will
kill the player in one hit.
Help save the ocean and all the fish who inhabit it!

ENJOY!
*****************************************************************/


#include <time.h>
#include <vector>
#include <sstream>
#include "Level.h"

using namespace std;

string message = ""; // message is initialized to output to screen
float  totalTime = 0; // totalTime initialized to later pass onto getScoreUpdate function
int z = 100; // z is an integer that stores the current score diplayed

bool EnemyMoveRight = true;
bool Enemy2MoveRight = true;
bool Enemy3MoveRight = true;

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
	int lvl = 1; // is used to choose which level will be loaded
	stringstream s; // used to show health at bottom/left corner of screen
	s << "Health: " << z;
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "CSCI 120 - Underwater Adventure");

	// keeps player in game until win or loss
	while (lvl < 4 && lvl > 0) {
		z = 100; // sets life to 100 after each level

		Entity* entityPtrGrid[NUM_HORIZONTAL][NUM_VERTICAL]; // vector containing all game entities (player, prizes, walls)

		for (int i = 0; i < NUM_HORIZONTAL; ++i)
			for (int j = 0; j < NUM_VERTICAL; ++j)
				entityPtrGrid[i][j] = NULL;

		srand((unsigned int)time(0));

		// create player entity
		Entity player(0, 0, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/DOWN.png", PLAYER);

		// create enemy entities
		Trap enemy(7, 10, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Enemy.png", ENEMY, 6, "Message: You've been slimed!!", "resources/slimesquish.wav");
		Trap enemy2(22, 12, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Enemy.png", ENEMY, 6, "Message: You've been slimed!!", "resources/slimesquish.wav");
		Trap enemy3(22, 12, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Enemy.png", ENEMY, 6, "Message: You've been slimed!!", "resources/slimesquish.wav");
	
		// set location of player and enemy on level 1
		if (lvl == 1) {
			player.setXY(0, 0);
			entityPtrGrid[0][0] = &player;
			enemy.setXY(7, 10);
			entityPtrGrid[7][10] = &enemy;
		}
		// set location of player and enemies on level 2
		else if (lvl == 2) {
			player.setXY(0, 0);
			entityPtrGrid[0][0] = &player;
			enemy.setXY(9, 3);
			entityPtrGrid[9][3] = &enemy;
			enemy2.setXY(2, 3);
			entityPtrGrid[2][3] = &enemy;
		}
		// set location of player and enemies on level 3
		else {
			player.setXY(9, 10);
			entityPtrGrid[9][10] = &player;
			enemy.setXY(9, 3);
			entityPtrGrid[9][3] = &enemy;
			enemy2.setXY(2, 3);
			entityPtrGrid[2][3] = &enemy;
			enemy3.setXY(15, 6);
			entityPtrGrid[15][6] = &enemy;
		}

		// level function to load the correct level
		Lvl(entityPtrGrid, lvl);

		// load background sprite
		sf::Texture texture;
		if (!texture.loadFromFile("resources/merBackground.png")) {
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
		scoreBoard.setFillColor(sf::Color::Yellow);
		scoreBoard.setString(s.str());

		// initialize message board
		sf::Text messageBoard;
		messageBoard.setFont(font);
		messageBoard.setCharacterSize(25);
		messageBoard.setPosition(10.f, NUM_VERTICAL * SIZE_SPRITE); // at the bottom of the window
		messageBoard.setFillColor(sf::Color::White);
		messageBoard.setString("Message: none.");

		// load the sound used in the game
		sf::SoundBuffer backgroundSoundBuffer;
		if (!backgroundSoundBuffer.loadFromFile("resources/DireDocks.wav")) {
			std::cout << "cannot open audio";
			sf::sleep(sf::seconds(5));
			return EXIT_FAILURE;
		}
		sf::Sound backgroundSound(backgroundSoundBuffer);
		backgroundSound.play(); // play background music
		backgroundSound.setLoop(true); // loops music

		// load sound for losing screen
		sf::SoundBuffer LoseBuff;
		if (!LoseBuff.loadFromFile("resources/DUN_DUN.wav")) {
			std::cout << "cannot open audio";
			sf::sleep(sf::seconds(5));
			return EXIT_FAILURE;
		}
		sf::Sound Lose(LoseBuff);

		// timer for time delays
		sf::Clock clock;
		sf::Clock enemyClock;
		float timer = 0, delay = 0.2;


		Direction dir = NONE; // direction of player move

		// main game loop
		// isPlaying is used when user is playing the game
		bool isPlaying = true;
		bool open = true;
		while (open)
		{
			// if statement to allow processes to happen if isPlaying is true
			if (isPlaying) {
				float time = clock.getElapsedTime().asSeconds();
				float enemyTime = enemyClock.getElapsedTime().asSeconds();
				clock.restart();
				timer += time;
				totalTime += time; //totalTime is passed onto getScoreUpdate function as timeDelay
				int Whatever = enemyTime; // Whatever is based from enemyTime and used to move the enemies

				sf::Event e;
				while (window.pollEvent(e))
				{
					if (e.type == sf::Event::Closed) // close button
						window.close();
				}

				// if/else statements to move the enemies on the grid
				if (lvl == 1) {
					if ((Whatever) % 2 == 1) {
						entityPtrGrid[enemy.getX()][enemy.getY()] = NULL;
						// moves enemy 1
						if (EnemyMoveRight == true) {
							if (entityPtrGrid[enemy.getX() + 1][enemy.getY()] == NULL) {
								enemy.moveRight();
								enemy.setSpriteFile("resources/Enemy.png");
							}
							else {
								enemy.moveLeft();
								enemy.setSpriteFile("resources/Enemy2.png");
								EnemyMoveRight = false;
							}
						}
						else {
							if (entityPtrGrid[enemy.getX() - 1][enemy.getY()] == NULL) {
								enemy.moveLeft();
								enemy.setSpriteFile("resources/Enemy2.png");
							}
							else {
								enemy.moveRight();
								EnemyMoveRight = true;
								enemy.setSpriteFile("resources/Enemy.png");
							}
						}
						entityPtrGrid[enemy.getX()][enemy.getY()] = &enemy;
						enemyClock.restart();
					}
				}
				else if (lvl == 2) {
					if ((Whatever) % 2 == 1) {
						entityPtrGrid[enemy.getX()][enemy.getY()] = NULL;
						entityPtrGrid[enemy2.getX()][enemy2.getY()] = NULL;
						// moves enemy 1
						if (EnemyMoveRight == true) {
							if (entityPtrGrid[enemy.getX()][enemy.getY() + 1] == NULL) {
								enemy.moveDown();
								enemy.setSpriteFile("resources/Enemy.png");
							}
							else {
								enemy.moveUp();
								enemy.setSpriteFile("resources/Enemy2.png");
								EnemyMoveRight = false;
							}
						}
						else {
							if (entityPtrGrid[enemy.getX()][enemy.getY() - 1] == NULL) {
								enemy.moveUp();
								enemy.setSpriteFile("resources/Enemy2.png");
							}
							else {
								enemy.moveDown();
								enemy.setSpriteFile("resources/Enemy.png");
								EnemyMoveRight = true;
							}
						}
						// moves enemy 2
						if (Enemy2MoveRight == true) {
							if (entityPtrGrid[enemy2.getX()][enemy2.getY() + 1] == NULL) {
								enemy2.moveDown();
								enemy2.setSpriteFile("resources/Enemy.png");
							}
							else {
								enemy2.moveUp();
								enemy2.setSpriteFile("resources/Enemy2.png");
								Enemy2MoveRight = false;
							}
						}
						else {
							if (entityPtrGrid[enemy2.getX()][enemy2.getY() - 1] == NULL) {
								enemy2.moveUp();
								enemy2.setSpriteFile("resources/Enemy2.png");
							}
							else {
								enemy2.moveDown();
								enemy2.setSpriteFile("resources/Enemy.png");
								Enemy2MoveRight = true;
							}
						}
						entityPtrGrid[enemy.getX()][enemy.getY()] = &enemy;
						entityPtrGrid[enemy2.getX()][enemy2.getY()] = &enemy2;
						enemyClock.restart();
					}
				}
				else {
					if ((Whatever) % 2 == 1) {
						entityPtrGrid[enemy.getX()][enemy.getY()] = NULL;
						entityPtrGrid[enemy2.getX()][enemy2.getY()] = NULL;
						entityPtrGrid[enemy3.getX()][enemy3.getY()] = NULL;
						// moves enemy 1
						if (EnemyMoveRight == true) {
							if (entityPtrGrid[enemy.getX()][enemy.getY() + 1] == NULL) {
								enemy.moveDown();
								enemy.setSpriteFile("resources/Enemy.png");
							}
							else {
								enemy.moveUp();
								enemy.setSpriteFile("resources/Enemy2.png");
								EnemyMoveRight = false;
							}
						}
						else {
							if (entityPtrGrid[enemy.getX()][enemy.getY() - 1] == NULL) {
								enemy.moveUp();
								enemy.setSpriteFile("resources/Enemy2.png");
							}
							else {
								enemy.moveDown();
								enemy.setSpriteFile("resources/Enemy.png");
								EnemyMoveRight = true;
							}
						}
						// moves enemy 2
						if (Enemy2MoveRight == true) {
							if (entityPtrGrid[enemy2.getX()][enemy2.getY() + 1] == NULL) {
								enemy2.moveDown();
								enemy2.setSpriteFile("resources/Enemy.png");
							}
							else {
								enemy2.moveUp();
								enemy2.setSpriteFile("resources/Enemy2.png");
								Enemy2MoveRight = false;
							}
						}
						else {
							if (entityPtrGrid[enemy2.getX()][enemy2.getY() - 1] == NULL) {
								enemy2.moveUp();
								enemy2.setSpriteFile("resources/Enemy2.png");
							}
							else {
								enemy2.moveDown();
								enemy2.setSpriteFile("resources/Enemy.png");
								Enemy2MoveRight = true;
							}
						}
						// moves enemy 3
						if (Enemy3MoveRight == true) {
							if (entityPtrGrid[enemy3.getX()][enemy3.getY() + 1] == NULL) {
								enemy3.moveDown();
								enemy3.setSpriteFile("resources/Enemy.png");
							}
							else {
								enemy3.moveUp();
								enemy3.setSpriteFile("resources/Enemy2.png");
								Enemy3MoveRight = false;
							}
						}
						else {
							if (entityPtrGrid[enemy3.getX()][enemy3.getY() - 1] == NULL) {
								enemy3.moveUp();
								enemy3.setSpriteFile("resources/Enemy2.png");
							}
							else {
								enemy3.moveDown();
								enemy3.setSpriteFile("resources/Enemy.png");
								Enemy3MoveRight = true;
							}
						}
						entityPtrGrid[enemy.getX()][enemy.getY()] = &enemy;
						entityPtrGrid[enemy2.getX()][enemy2.getY()] = &enemy2;
						entityPtrGrid[enemy3.getX()][enemy3.getY()] = &enemy3;
						enemyClock.restart();
					}
				}

				// used to take damage to the play if touching an enemy
				if ((player.getX() == enemy.getX()) && (player.getY() == enemy.getY())) {
					z = z - 10;
				}
				if ((player.getX() == enemy2.getX()) && (player.getY() == enemy2.getY())) {
					z = z - 15;
				}
				if ((player.getX() == enemy3.getX()) && (player.getY() == enemy3.getY())) {
					z = z - 20;
				}
				
				if (z <= 0) {
					isPlaying = false;
					lvl = 10;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { // left key
					dir = LEFT;
					player.setSpriteFile("resources/LEFT.png");
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { // right key
					dir = RIGHT;
					player.setSpriteFile("resources/RIGHT.png");
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { // up key
					dir = UP;
					player.setSpriteFile("resources/UP.png");
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { // down key
					dir = DOWN;
					player.setSpriteFile("resources/DOWN.png");
				}



				if (timer > delay) { // time delay to accomodate user key input 
					timer = 0;

					// check for collision
					EntityType collisionType = checkCollision(entityPtrGrid, player.getX(), player.getY(), dir);
					if (collisionType == PRIZE) {
						messageBoard.setString(message);
						// uses a string stream to create a string with both the phrase "Score: " and the integer z that holds the score
						stringstream ss;
						ss << "Health: " << z;
						// outputs string stream to scoreBoard
						scoreBoard.setString(ss.str());
					}
					if (collisionType == TRAP) {
						messageBoard.setString(message);
						// uses a string stream to create a string with both the phrase "Score: " and the integer z that holds the score
						stringstream ss;
						ss << "Health: " << z;
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
					window.display();
				}
			// else statement if player is not playing. Does NOT let player move
			else {
				// creates a string stream to store a victory or loss message
				stringstream win;
				if (lvl == 3) {
					win << "You win and have\nsaved The ocean!\nHold Escape to exit\n";
				}
				else if (lvl == 2) {
					win << "Fun Fact:\nHumans suck\nHold Space to continue ";
				}
				else if (lvl == 1) {
					win << "Fun Fact:\n14 billion pounds of\ngarbage are dumped into\nthe ocean every year.\nHold Space to continue ";
				}
				else {
					win << "You lost and have\nruined the ocean!\nHold Escape to exit\n";
				}

				window.clear(); // clears the window
				window.draw(backgroundSprite); // display background

				sf::Text pauseMessage; // creates a vitory message

									   // font, size, position and color of victory message
				pauseMessage.setFont(font);
				pauseMessage.setCharacterSize(63);
				pauseMessage.setPosition(220.f, 170.f);
				pauseMessage.setFillColor(sf::Color::White);
				// uses the win string stream to output a message to the screen
				pauseMessage.setString(win.str());
				window.draw(pauseMessage);

				// if you are a winner
				if (lvl == 3) {
					sf::Event event;
					while (window.pollEvent(event)) {
						if ((event.type == sf::Event::Closed) ||
							((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
						{
							window.close();
							open = false;
							break;
						}
					}
				}
				// if you are a loser
				else if (lvl == 10) {
					Lose.play(); // play lose music

					sf::Event event;
					while (window.pollEvent(event)) {
						if ((event.type == sf::Event::Closed) ||
							((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
						{
							window.close();
							open = false;
							break;
						}
					}
				}
				else {
					sf::Event event;
					while (window.pollEvent(event)) {
						if ((event.type == sf::Event::Closed) ||
							((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space)))
						{
							open = false;
							win << "\nLoading...";
							pauseMessage.setString(win.str());
							window.draw(pauseMessage);
						}
					}
				}
				window.display();
			}
		}
		lvl++;
		window.clear();
	}
	return 0;
}
