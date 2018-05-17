/****************************************************************
File:			Trap.cpp
Description:	Member function definitions for class Trap
Author:			Manuel Kelly
Class:			CSCI 120
Date:			5/16/2018
I hereby certify that this program is entirely my own work.
*****************************************************************/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include "Trap.h"

// default constructor for derived Trap class
Trap::Trap() : Entity() {}

// parameterized constructor for derived Trap class and passing on values to the Entity base class
Trap::Trap(int x, int y, int xLimit, int yLimit, std::string spriteFile, EntityType type, int penaltyLevel, string phrase, std::string soundFile) : Entity(x, y, xLimit, yLimit, spriteFile, type) {
	// set the sound buffer and sound of the Trap object
	if (!entitySoundBuffer.loadFromFile(soundFile)) {
		std::cout << "cannot open audio";
	}
	entitySound.setBuffer(entitySoundBuffer);
	this->penaltyLevel = penaltyLevel;
	this->phrase = phrase;
}

// gets the updated score for the Score: message with collision of Trap object
int Trap::getScoreUpdate(int timeDelay) {
		int scoreUpdate = 0;
		// formula for getting scoreUpdate as a Trap object
		timeDelay /= 3;
		timeDelay += 1; // add 1 so we don't divide by zero when dividing by timeDelay
		penaltyLevel = 10 * -penaltyLevel;
		scoreUpdate = penaltyLevel / timeDelay;
		return scoreUpdate;
}

// plays Trap object's sound and returns statement for message on screen
string Trap::say() {
	entitySound.play();
	return phrase;
}
