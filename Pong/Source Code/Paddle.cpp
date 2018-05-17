#include "Paddle.h"

//Default constructor for class Paddle
Paddle::Paddle() {
	paddleShape.setSize(sf::Vector2f(25, 100) - sf::Vector2f(3, 3));
	paddleShape.setOutlineThickness(3);
	paddleShape.setOutlineColor(sf::Color::Black);
	paddleShape.setFillColor(sf::Color::Blue);
	paddleShape.setOrigin(sf::Vector2f(25, 100) / 2.f);
	this->speed = DEFAULT_SPEED;
}
//Allows user to create a rectangle object in class Paddle and select the fill color of the rectangle
Paddle::Paddle(sf::Color fillcolor) {
	paddleShape.setSize(sf::Vector2f(25, 100) - sf::Vector2f(3, 3));
	paddleShape.setOutlineThickness(3);
	paddleShape.setOutlineColor(sf::Color::Black);
	paddleShape.setFillColor(fillcolor);
	paddleShape.setOrigin(sf::Vector2f(25, 100) / 2.f);
	this->speed = DEFAULT_SPEED;
}
//gets speed of paddle
float Paddle::getSpeed() {
	return speed;
}
//allows input for movement of the paddles
void Paddle::move(float x, float y) {
	paddleShape.move(x, y);
}
//sets the position of the paddle
void Paddle::setPosition(float x, float y) {
	paddleShape.setPosition(x, y);
}
//sets speed of the paddle
void Paddle::setSpeed(float speed) {
	this->speed = speed;
}
//returns the shape of the paddle to print
sf::RectangleShape Paddle::getShape() {
	return paddleShape;
}
//gets the size of the paddle
sf::Vector2f Paddle::getSize() {
	return paddleShape.getSize();
}
//gets the position of the paddle
sf::Vector2f Paddle::getPosition() {
	return paddleShape.getPosition();
}