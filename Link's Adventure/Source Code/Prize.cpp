#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include "Prize.h"

// default constructor for derived Prize class
Prize::Prize() : Entity() {}

// parameterized constructor for derived Prize class and passing on values to the Entity base class
Prize ::Prize(int x, int y, int xLimit, int yLimit, std::string spriteFile, EntityType type, int prizeLevel, string phrase) : Entity(x, y, xLimit, yLimit, spriteFile, type) {
	// set the sound buffer and sound of the Prize object
	if (!entitySoundBuffer.loadFromFile("resources/zeldaItem.wav")) {
		std::cout << "cannot open audio";
	}
	entitySound.setBuffer(entitySoundBuffer);
	this->prizeLevel = prizeLevel;
	this->phrase = phrase;
}

// gets the updated score for the Score: message
int Prize::getScoreUpdate(int timeDelay) {
		int scoreUpdate;
		// formula for getting scoreUpdate as a Prize object
		prizeLevel *= 3;
		timeDelay /= 3;
		timeDelay += 1; // add 1 so we don't divide by zero when dividing by timeDelay
		scoreUpdate = prizeLevel / timeDelay;

		return scoreUpdate;
}

// plays Prize object sound and returns statement for message on screen
string Prize::say(){
	entitySound.play();
	return phrase;
}
