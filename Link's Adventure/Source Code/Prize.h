/****************************************************************
File:			Prize.h
Description:	Class and enumeration declaration related to game entities
Author:			Manuel Kelly
Class:			CSCI 120
Date:			3/21/2018
I hereby certify that this program is entirely my own work.
*****************************************************************/

#ifndef PRIZE_H
#endif PRIZE_H

#define PRIZE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "Entity.h"
#include <iostream>

class Prize : public Entity {
public:
	// default constructor for derived Prize class
	Prize();

	// parameterized constructor for derived Prize class
	Prize(int x, int y, int xLimit, int yLimit, std::string spriteFile, EntityType type, int prizeLevel, string phrase);

	// gets the updated score for the Score: message with collision of Prize object
	int getScoreUpdate(int timeDelay) override;

	// plays Prize object's sound and returns statement for message on screen
	string say() override;

private:
	// the level of prize of the Prize object that is passed onto the getScoreUpdate function
	int prizeLevel;

	// stores statement for message on screen
	string phrase;

	// sound of Prize object
	sf::Sound entitySound;

	// sound buffer of Prize object
	sf::SoundBuffer entitySoundBuffer;
};