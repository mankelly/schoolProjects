/****************************************************************
File:			Trap.h
Description:	Class and enumeration declaration related to game entities
Author:			Manuel Kelly
Class:			CSCI 120
Date:			3/21/2018
I hereby certify that this program is entirely my own work.
*****************************************************************/

#ifndef TRAP_H
#endif TRAP_H

#define TRAP_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "Entity.h"
#include <iostream>

class Trap : public Entity {
public:
	// default constructor for derived Trap class
	Trap();

	// parameterized constructor for derived Trap class
	Trap(int x, int y, int xLimit, int yLimit, std::string spriteFile, EntityType type, int penaltyLevel, string phrase);

	// gets the updated score for the Score: message with collision of Trap object
	int getScoreUpdate(int timeDelay) override;

	// plays Trap object sound and returns statement for message on screen
	string say() override;

private:
	// the level of penalty the Trap object that is passed onto the getScoreUpdate function
	int penaltyLevel;

	// stores statement for message on screen
	string phrase;

	// sound of Trap object
	sf::Sound entitySound;

	// sound buffer of Trap object
	sf::SoundBuffer entitySoundBuffer;
};