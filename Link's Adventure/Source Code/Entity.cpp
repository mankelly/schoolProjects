/****************************************************************
File:			Entity.cpp
Description:	Member function definitions for class Entity
Author:
Class:			CSCI 120
Date:
I hereby certify that this program is entirely my own work.
*****************************************************************/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include "Entity.h"

using namespace std;

// Default Contructor of Entity class
Entity::Entity() {
	x = 0;
	y = 0;
	xLimit = 0;
	yLimit = 0;
	type = DEFAULT;
}

// Parameterized constructor of Entity class
Entity::Entity(int x, int y, int xLimit, int yLimit, std::string spriteFile, EntityType type) {
	if (!texture.loadFromFile(spriteFile)) {
		cout << "Error loading " << spriteFile << endl;
	}
	sprite = sf::Sprite(texture);
	this->x = x;
	this->y = y;
	this->xLimit = xLimit;
	this->yLimit = yLimit;
	this->spriteFile = spriteFile;
	this->type = type;

}

// Returns X value from positon on screen and in Array
int Entity::getX() {
	return x;
}

// Returns Y value from positon on screen and in Array
int Entity::getY() {
	return y;
}

// Moves Player entity up
void Entity::moveUp() {
	if (y > 0)
		y--;
}

// Moves Player entity down
void Entity::moveDown() {
	if (y < yLimit)
		y++;
}

// Moves Player entity left
void Entity::moveLeft() {
	if (x > 0)
		x--;
}

// Moves Player entity right
void Entity::moveRight() {
	if (x < xLimit)
		x++;
}

// Gets sprite of stored entity
sf::Sprite Entity::getSprite() {
	return sprite;
}

// Gets type of stored entity
EntityType Entity::getType() {
	return type;
}

// gets the updated score for the Score: message and will be overriden by a derived class
int Entity::getScoreUpdate(int timeDelay) {
	return 0;
}

// returns statement for message on screen and will be overriden by a derived class
string Entity::say() {
	return "";
}
