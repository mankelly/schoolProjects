/****************************************************************
File:			Level.cpp
Description:	Member function definition for Level Function
Author:			Manuel Kelly
Class:			CSCI 120
Date:			5/16/2018
I hereby certify that this program is entirely my own work.
*****************************************************************/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Level.h"

// allows for different levels to be loaded
void Lvl(Entity* entityGrid[NUM_HORIZONTAL][NUM_VERTICAL], int L) {

	int x, y; // x and y values for the entity to be stored
	if (L == 1) {

		// create coral (wall) entities
		x = 1;
		y = 0;
		for (int p = 0; p < 19; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++x;
			}
		}
		x = 1;
		y = 1;
		for (int p = 0; p < 9; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
		x = 4;
		y = 9;
		for (int p = 0; p < 7; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++x;
			}
		}
		x = 3;
		y = 2;
		for (int p = 0; p < 9; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
		x = 4;
		y = 2;
		for (int p = 0; p < 5; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++x;
			}
		}
		x = 10;
		y = 1;
		for (int p = 0; p < 6; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
		x = 5;
		y = 4;
		for (int p = 0; p < 4; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++x;
			}
		}
		x = 7;
		y = 5;
		for (int p = 0; p < 2; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
		x = 8;
		y = 6;
		for (int p = 0; p < 3; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++x;
			}
		}
		x = 4;
		y = 6;
		for (int p = 0; p < 2; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++x;
			}
		}
		x = 5;
		y = 7;
		for (int p = 0; p < 1; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++x;
			}
		}
		x = 7;
		y = 8;
		for (int p = 0; p < 5; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++x;
			}
		}
		x = 12;
		y = 2;
		for (int p = 0; p < 5; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
		x = 8;
		y = 6;
		for (int p = 0; p < 3; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++x;
			}
		}
		x = 12;
		y = 10;
		for (int p = 0; p < 8; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++x;
			}
		}
		x = 13;
		y = 6;
		for (int p = 0; p < 4; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
		x = 14;
		y = 2;
		for (int p = 0; p < 3; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
		x = 15;
		y = 2;
		for (int p = 0; p < 1; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++x;
			}
		}
		x = 16;
		y = 1;
		for (int p = 0; p < 2; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
		x = 14;
		y = 6;
		for (int p = 0; p < 3; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++x;
			}
		}
		x = 16;
		y = 4;
		for (int p = 0; p < 2; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
		x = 14;
		y = 8;
		for (int p = 0; p < 5; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++x;
			}
		}
		x = 18;
		y = 2;
		for (int p = 0; p < 6; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
		// create destination entity
		x = 14;
		y = 9;

		if (entityGrid[x][y] == NULL) {
			entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Trash.png", DESTINATION);
		}

		// create 10 trap entites
		// use a for loop to create 10 Trap entities
		for (int p = 0; p < 10; p++) {
			bool trapCheck = false;

			while (trapCheck == false) {
				x = rand() % NUM_HORIZONTAL;
				y = rand() % NUM_VERTICAL;

				if (entityGrid[x][y] == NULL) {
					entityGrid[x][y] = new Trap(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/2.png", TRAP, 3, "Message: Your tail has been bitten off!!", "resources/offfinal.wav");
					trapCheck = true;
				}
			}
		}

	}
	else if (L == 2) {
		// create coral (wall) entities
		x = 1;
		y = 0;
		for (int p = 0; p < 19; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++x;
			}
		}

		x = 1;
		y = 1;
		for (int p = 0; p < 9; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
		x = 2;
		y = 9;
		for (int p = 0; p < 4; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++x;
			}
		}

		x = 3;
		y = 2;
		for (int p = 0; p < 8; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
		x = 5;
		y = 2;
		for (int p = 0; p < 6; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}

		x = 6;
		y = 7;
		for (int p = 0; p < 2; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++x;
			}
		}

		x = 7;
		y = 8;
		for (int p = 0; p < 3; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}

		x = 7;
		y = 1;
		for (int p = 0; p < 5; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}

		x = 8;
		y = 5;
		for (int p = 0; p < 4; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++x;
			}
		}

		x = 9;
		y = 7;
		for (int p = 0; p < 5; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++x;
			}
		}
	
		x = 11;
		y = 2;
		for (int p = 0; p < 3; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
	
		x = 10;
		y = 9;
		for (int p = 0; p < 2; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++x;
			}
		}

		x = 13;
		y = 8;
		for (int p = 0; p < 3; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
		//
		x = 13;
		y = 2;
		for (int p = 0; p < 5; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
		
		x = 15;
		y = 1;
		for (int p = 0; p < 5; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
		
		x = 15;
		y = 7;
		for (int p = 0; p < 4; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
		
		x = 17;
		y = 2;
		for (int p = 0; p < 4; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
		
		x = 17;
		y = 7;
		for (int p = 0; p < 4; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
		
		x = 18;
		y = 10;
		if (entityGrid[x][y] == NULL) {
			entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
			}
		
		x = 18;
		y = 4;
		if (entityGrid[x][y] == NULL) {
			entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
		}
		
		x = 16;
		y = 10;
		if (entityGrid[x][y] == NULL) {
			entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
		}
		// create destination entity

		x = 18;
		y = 3;

		if (entityGrid[x][y] == NULL) {
			entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Trash.png", DESTINATION);
		}

		// create 10 trap entites
		// use a for loop to create 10 Trap entities
		for (int p = 0; p < 10; p++) {
			bool trapCheck = false;

			while (trapCheck == false) {
				x = rand() % NUM_HORIZONTAL;
				y = rand() % NUM_VERTICAL;

				if (entityGrid[x][y] == NULL) {
					entityGrid[x][y] = new Trap(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/2.png", TRAP, 3, "Message: Your tail has been bitten off!!", "resources/offfinal.wav");
					trapCheck = true;
				}
			}
		}
	}

	else {
		// create coral (wall) entities
		x = 8;
		y = 0;
		for (int p = 0; p < 2; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
		x = 10;
		y = 0;
		for (int p = 0; p < 2; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
		x = 1;
		y = 2;
		for (int p = 0; p < 18; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++x;
			}
		}
		x = 1;
		y = 3;
		for (int p = 0; p < 4; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
		x = 1;
		y = 7;
		for (int p = 0; p < 8; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++x;
			}
		}
		x = 10;
		y = 7;
		for (int p = 0; p < 9; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++x;
			}
		}
		x = 18;
		y = 3;
		for (int p = 0; p < 4; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
		x = 8;
		y = 8;
		for (int p = 0; p < 3; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}
		x = 10;
		y = 8;
		for (int p = 0; p < 3; p++) {
			if (entityGrid[x][y] == NULL) {
				entityGrid[x][y] = new Entity(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Coral.png", WALL);
				++y;
			}
		}

		// create destination entity
		x = 17;
		y = 6;

		if (entityGrid[x][y] == NULL) {
			entityGrid[x][y] = new Trap(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/Trash.png", DESTINATION, 1, "Message: None", "resources/Party-blower.wav");
		}

		// create 7 trap entites
		x = 6;
		y = 3;

		if (entityGrid[x][y] == NULL) {
			entityGrid[x][y] = new Trap(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/2.png", TRAP, 3, "Message: Your tail has been bitten off!!", "resources/offfinal.wav");
		}
		x = 3;
		y = 5;

		if (entityGrid[x][y] == NULL) {
			entityGrid[x][y] = new Trap(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/2.png", TRAP, 3, "Message: Your tail has been bitten off!!", "resources/offfinal.wav");
		}
		x = 6;
		y = 6;

		if (entityGrid[x][y] == NULL) {
			entityGrid[x][y] = new Trap(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/2.png", TRAP, 3, "Message: Your tail has been bitten off!!", "resources/offfinal.wav");
		}
		x = 12;
		y = 4;

		if (entityGrid[x][y] == NULL) {
			entityGrid[x][y] = new Trap(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/2.png", TRAP, 3, "Message: Your tail has been bitten off!!", "resources/offfinal.wav");
		}
		x = 13;
		y = 6;

		if (entityGrid[x][y] == NULL) {
			entityGrid[x][y] = new Trap(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/2.png", TRAP, 3, "Message: Your tail has been bitten off!!", "resources/offfinal.wav");
		}
		x = 15;
		y = 3;

		if (entityGrid[x][y] == NULL) {
			entityGrid[x][y] = new Trap(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/2.png", TRAP, 3, "Message: Your tail has been bitten off!!", "resources/offfinal.wav");
		}
		x = 16;
		y = 5;

		if (entityGrid[x][y] == NULL) {
			entityGrid[x][y] = new Trap(x, y, NUM_HORIZONTAL - 1, NUM_VERTICAL - 1, "resources/2.png", TRAP, 3, "Message: Your tail has been bitten off!!", "resources/offfinal.wav");
		}
	}

}