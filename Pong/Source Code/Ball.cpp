#include "Ball.h"
#include <iostream>

//default contructor for class Ball
Ball::Ball() {
	radius = 10.f;
	speed = 400.f;
	angle = 0.f;
	ballShape.setRadius(radius - 3);
	ballShape.setOutlineThickness(3.0);
	ballShape.setOutlineColor(sf::Color::White);
	ballShape.setFillColor(sf::Color::Red);
	ballShape.setOrigin(5.0 , 5.0);
}
//loads sound of ball collision
void Ball::loadSound() {
	ballSoundBuffer.loadFromFile("ball.wav");
	if (!ballSoundBuffer.loadFromFile("ball.wav")) {
		std::cout << "cannot open audio";
		sf::sleep(sf::seconds(5));
	}
}
//pays sound of ball collision
void Ball::playSound() {
	ballSound.setBuffer(ballSoundBuffer);
	ballSound.play();
}
//gets the angle in which the ball is hit
float Ball::getAngle() {
	return angle;
}
//gets the radius of the ball
float Ball::getRadius() {
	return radius;
}
//gets postion of the ball
sf::Vector2f Ball::getPosition() {
	return ballShape.getPosition();
}
//gets the shape of the ball to print
sf::CircleShape Ball::getShape(){
	return ballShape;
}
//allows for movement of the ball
void Ball::move(float deltaTime) {
	ballShape.move(std::cos(angle) * (speed * deltaTime), std::sin(angle) * (speed * deltaTime));
}
//sets the angle in which the ball is hit
void Ball::setAngle(float angle) {
	this->angle = angle;
}
//resets the angle, in which the ball is hit, to 0.f
void Ball::resetAngle() {
	angle = 0.f;
}
//sets the position of the ball
void Ball::setPosition(int x, int y) {
	ballShape.setPosition(x, y);
}
//checks if there is collision between a paddle and the ball
void Ball::checkPaddleCollision(Paddle leftPaddle, Paddle rightPaddle) {
	// Left Paddle
	if (ballShape.getPosition().x - ballShape.getRadius() < leftPaddle.getPosition().x + (leftPaddle.getSize()).x / 2 &&
		ballShape.getPosition().x - ballShape.getRadius() > leftPaddle.getPosition().x &&
		ballShape.getPosition().y + ballShape.getRadius() >= leftPaddle.getPosition().y - (leftPaddle.getSize()).y / 2 &&
		ballShape.getPosition().y - ballShape.getRadius() <= leftPaddle.getPosition().y + (leftPaddle.getSize()).y / 2)
	{
		if (ballShape.getPosition().y > leftPaddle.getPosition().y)
			angle = PI - angle + (std::rand() % 20) * PI / 180;
		else
			angle = PI - angle - (std::rand() % 20) * PI / 180;

		ballSound.play();
		ballShape.setPosition(leftPaddle.getPosition().x + radius + leftPaddle.getSize().x / 2 + 0.1f, ballShape.getPosition().y);
	}

	// Right Paddle
	if (ballShape.getPosition().x + ballShape.getRadius() > rightPaddle.getPosition().x - (rightPaddle.getSize()).x / 2 &&
		ballShape.getPosition().x + ballShape.getRadius() < rightPaddle.getPosition().x &&
		ballShape.getPosition().y + ballShape.getRadius() >= rightPaddle.getPosition().y - (rightPaddle.getSize()).y / 2 &&
		ballShape.getPosition().y - ballShape.getRadius() <= rightPaddle.getPosition().y + (rightPaddle.getSize()).y / 2)
	{
		if (ballShape.getPosition().y > rightPaddle.getPosition().y)
			angle = PI - angle + (std::rand() % 20) * PI / 180;
		else
			angle = PI - angle - (std::rand() % 20) * PI / 180;

		ballSound.play();
		ballShape.setPosition(rightPaddle.getPosition().x - radius - rightPaddle.getSize().x / 2 - 0.1f, ballShape.getPosition().y);
	}

}
