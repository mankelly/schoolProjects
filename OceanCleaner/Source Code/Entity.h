/****************************************************************
File:			Entity.h
Description:	Class and enumeration declaration related to game entities
Author:			Manuel Kelly
Class:			CSCI 120
Date:			5/16/2018
I hereby certify that this program is entirely my own work.
*****************************************************************/

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

using namespace std;

// type of game entities
enum EntityType { UNKNOWN, PLAYER, PRIZE, WALL, TRAP, DESTINATION, DEFAULT, ENEMY };

// Class representing a game entity 
class Entity {
public:
	/*
	* Initializes the object to default values
	*/
	Entity();

	/* 
	* Initializes the object based on parameter values
	* @param x x-coordinate
	* @param y y-coordinate
	* @param xLimit maximum value of x-coordinate
	* @param yLimit maximum value of y-coordinate
	* @param spriteFile path to sprite file
	* @param type entity type
	*/
	Entity(int x, int y, int xLimit, int yLimit, std::string spriteFile, EntityType type);

	/*
	* Returns x-coordinate of entity
	* @return x-coordinate
	*/
	int getX();

	/*
	* Returns y-coordinate of entity
	* @return y-coordinate
	*/
	int getY();

	/*
	* Moves entity up by one unit by updating y-coordinate as appropriate
	*/
	void moveUp();

	/*
	* Moves entity down by one unit by updating y-coordinate as appropriate
	*/
	void moveDown();

	/*
	* Moves entity left by one unit by updating x-coordinate as appropriate
	*/
	void moveLeft();

	/*
	* Moves entity right by one unit by updating x-coordinate as appropriate
	*/
	void moveRight();

	/*
	* Returns sprite object belonging to the entity
	* @return sprite
	*/
	sf::Sprite getSprite();

	/*
	* Returns the entity type of the entity
	* @return type
	*/
	EntityType getType();

	// gets the updated score for the Score: message and will be overriden by a derived class
	virtual int getScoreUpdate(int timeDelay);

	// returns statement for message on screen and will be overriden by a derived class
	virtual string say();

	// allows to reset the sprite file for an entity
	void setSpriteFile(std::string spriteFile);

	// allows to reset both the x and y value for an entity
	void setXY(int x, int y);
protected:
	int timeDelay; // time delay from game play time
	int x;	// x-coordinate of location (lowest value is 0)
	int y;	// y-coordinate of location (lowest value is 0)
	int xLimit; // highest value of x-coordinate
	int yLimit; // highest value of y-coordinate
	std::string spriteFile; // path to sprite image
	sf::Sprite sprite;	// Sprite object
	sf::Texture texture; // texture for sprite
	EntityType type; // type of entity
	std::string name; // name of entity
	sf::SoundBuffer SoundBuffer; // Entity sound buffer
};

#endif
