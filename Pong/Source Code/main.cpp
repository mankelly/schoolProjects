/****************************************************************
File:			main.cpp
Description:	OOP Pong Project
Author:			Manuel Kelly
Class:			CSCI 120
Date:			2/21/2018
I hereby certify that the modification of the given Pong program 
is entirely my own work.

Based on https://github.com/SFML/SFML/blob/master/examples/pong/Pong.cpp
*****************************************************************/

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Ball.h"
#include "Paddle.h"

////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	// Define constants
	const int gameWidth = 800;
	const int gameHeight = 600;

	// Create the window of the application
	sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight, 32), "CSCI 120 - Pong",
		sf::Style::Titlebar | sf::Style::Close);
	window.setVerticalSyncEnabled(true);

	// Create the left paddle
	Paddle leftPaddle(sf::Color::Green);

	// Create the right paddle
	Paddle rightPaddle;

	// Create the ball and load sound for ball
	Ball ball;
	ball.loadSound();

	// Load the text font
	sf::Font font;
	if (!font.loadFromFile("Quicksand-Regular.otf")) {
		std::cout << "cannot open font";
		sf::sleep(sf::seconds(5));
		return EXIT_FAILURE;
	}

	// Initialize the pause message
	sf::Text pauseMessage;
	pauseMessage.setFont(font);
	pauseMessage.setCharacterSize(40);
	pauseMessage.setPosition(170.f, 150.f);
	pauseMessage.setFillColor(sf::Color::White);
	pauseMessage.setString("Welcome to SFML pong!\nPress space to start the game");

	// Define the paddles properties
	sf::Clock AITimer;
	const sf::Time AITime = sf::seconds(0.1f);

	// set the speeds of paddles
	leftPaddle.setSpeed(400.f);
	rightPaddle.setSpeed(0.f);
		
	sf::Clock clock;
	bool isPlaying = false;
	while (window.isOpen()) // MAIN GAME LOOP -- should be more concise and readable after modification
	{
		// Handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Window closed or escape key pressed: exit
			if ((event.type == sf::Event::Closed) ||
				((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
			{
				window.close();
				break;
			}

			// Space key pressed: play
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
			{
				if (!isPlaying)
				{
					// (re)start the game
					isPlaying = true;
					clock.restart();

					// Reset the position of the paddles and ball
					leftPaddle.setPosition(20, 300);
					rightPaddle.setPosition(780, 300);
					ball.setPosition((gameWidth / 2), (gameHeight / 2));
					ball.resetAngle();
				}
			}
		}

		if (isPlaying)
		{
			float deltaTime = clock.restart().asSeconds();

			// Move the player's paddle
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
				(leftPaddle.getPosition().y - (leftPaddle.getSize()).y / 2 > 5.f))
			{
				leftPaddle.move(0.f, -leftPaddle.getSpeed() * deltaTime);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
				(leftPaddle.getPosition().y + (leftPaddle.getSize()).y / 2 < gameHeight - 5.f))
			{
				leftPaddle.move(0.f, leftPaddle.getSpeed() * deltaTime);
			}

			// Move the computer's paddle
			if (((rightPaddle.getSpeed() < 0.f) && (rightPaddle.getPosition().y - (rightPaddle.getSize()).y / 2 > 5.f)) ||
				((rightPaddle.getSpeed() > 0.f) && (rightPaddle.getPosition().y + (rightPaddle.getSize()).y / 2 < gameHeight - 5.f)))
			{
				rightPaddle.move(0.f, rightPaddle.getSpeed() * deltaTime);
			}

			// Update the computer's paddle direction according to the ball position
			if (AITimer.getElapsedTime() > AITime)
			{
				AITimer.restart();
				if (ball.getPosition().y + ball.getRadius() > rightPaddle.getPosition().y + (rightPaddle.getSize()).y / 2)
					rightPaddle.setSpeed(400.f);
				else if (ball.getPosition().y - ball.getRadius() < rightPaddle.getPosition().y - (rightPaddle.getSize()).y / 2)
					rightPaddle.setSpeed(-400.f);
				else
					rightPaddle.setSpeed(0.f);
			}

			// Move the ball
			ball.move(deltaTime);

			// Check collisions between the ball and the screen
			if (ball.getPosition().x - ball.getRadius() < 0.f)
			{
				isPlaying = false;
				pauseMessage.setString("You lost!\nPress space to restart or\nescape to exit");
			}
			if (ball.getPosition().x + ball.getRadius() > gameWidth)
			{
				isPlaying = false;
				pauseMessage.setString("You won!\nPress space to restart or\nescape to exit");
			}
			if (ball.getPosition().y - ball.getRadius() < 0.f)
			{
				ball.playSound();
				ball.setAngle(ball.getAngle()*(-1));
				ball.setPosition(ball.getPosition().x, ball.getRadius() + 0.1f);
			}
			if (ball.getPosition().y + ball.getRadius() > gameHeight)
			{
				ball.playSound();
				ball.setAngle(ball.getAngle()*(-1));
				ball.setPosition(ball.getPosition().x, gameHeight - ball.getRadius() - 0.1f);
			}

			// Check the collisions between the ball and the paddles
			ball.checkPaddleCollision(leftPaddle, rightPaddle);
		}

		// Clear the window
		window.clear(sf::Color::Black);

		if (isPlaying)
		{
			// Draw the paddles and the ball
			window.draw(rightPaddle.getShape());
			window.draw(leftPaddle.getShape());
			window.draw(ball.getShape());
		
		}
		else
		{
			// Draw the pause message
			window.draw(pauseMessage);
		}

		// Display things on screen
		window.display();
	}

	return EXIT_SUCCESS;
}