/****************************************************************
File:			Level.h
Description:	Function and enumeration declaration related level structure
Author:			Manuel Kelly
Class:			CSCI 120
Date:			5/16/2018
I hereby certify that this program is entirely my own work.
*****************************************************************/

#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include "Trap.h"

const int SIZE_SPRITE = 60;		// size of a sprite (square)
const int NUM_HORIZONTAL = 20;	// number of adventure game sprites horizontally tiled
const int NUM_VERTICAL = 11;	// number of adventure game sprites vertically tiled
const int WIDTH = SIZE_SPRITE * NUM_HORIZONTAL;	// width of the game window (1200)
const int HEIGHT = SIZE_SPRITE * (NUM_VERTICAL + 2);	// height of the game window (including score and message board) (800)

// allows for different levels to be loaded
void Lvl(Entity* entityGrid[NUM_HORIZONTAL][NUM_VERTICAL], int L);

#endif