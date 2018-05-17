#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

class Paddle {
public:
	//Default constructor for class Paddle
	Paddle();

	//Allows user to create a rectangle object in class Paddle and select the fill color of the rectangle
	Paddle(sf::Color fillColor);

	//gets speed of paddle
	float getSpeed();

	//allows input for movement of the paddles
	void move(float x, float y);

	//sets the position of the paddle
	void setPosition(float x, float y);

	//sets speed of the paddle
	void setSpeed(float speed);

	//returns the shape of the paddle to print
	sf::RectangleShape getShape();

	//gets the size of the paddle
	sf::Vector2f getSize();

	//gets the position of the paddle
	sf::Vector2f getPosition();

	//used to set default speed of paddle to 400.f
	const float DEFAULT_SPEED = 400.f;
private:
	//creates rectangle (or paddle)
	sf::RectangleShape paddleShape;	

	//variable passed on through the class that stores speed
	float speed;	
};


#endif	PADDLE_H
