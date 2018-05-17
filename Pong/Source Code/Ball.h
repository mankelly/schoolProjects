#ifndef BALL_H
#define BALL_H


#include "Paddle.h"
#include <SFML/Audio.hpp>

class Ball {
public:
	//default contructor for class Ball
	Ball();

	//gets postion of the ball
	sf::Vector2f getPosition();	

	//gets the shape of the ball to print
	sf::CircleShape getShape();	

	//gets the radius of the ball
	float getRadius();

	//gets the angle in which the ball is hit
	float getAngle();

	//sets the position of the ball
	void setPosition(int x, int y);

	//allows for movement of the ball
	void move(float deltaTime);

	//sets the angle in which the ball is hit
	void setAngle(float angle);

	//resets the angle, in which the ball is hit, to 0.f
	void resetAngle();

	//checks if there is collision between a paddle and the ball
	void checkPaddleCollision(Paddle leftPaddle, Paddle rightPaddle); 

	//loads sound of ball collision
	void loadSound();

	//pays sound of ball collision
	void playSound();

	//sets value of PI to 3.14159f
	const float PI = 3.14159f;
private:
	//creates sound for the ball
	sf::Sound ballSound;

	//creates buffer for sound
	sf::SoundBuffer ballSoundBuffer;

	//creates the ball
	sf::CircleShape ballShape;

	//variables for radius, speed and angle of the ball
	float radius;
	float speed;	
	float angle;
};

#endif