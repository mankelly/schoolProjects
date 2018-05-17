/****************************************************************
File: Project 2 Fractals
Description: A program that creates various fractals
Author: Manuel Kelly
Class: CSCI 120
Date: 4/16/2018
I hereby certify that this program is entirely my own work.
*****************************************************************/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "TextButton.h"
#include <vector>

using namespace std;

const float TEXT_X = 10;		// x coordinate of text buttons
const float TEXT_HEIGHT = 60;	// height of each row of text button
const float TEXT_WIDTH = 300;	// width of text button panel
const float WINDOW_WIDTH = 1200; // window width
const float WINDOW_HEIGHT = 800; // window height
const float FRACTAL_WIDTH = 250;	// width of a fractal
const float FRACTAL_HEIGHT = 250;	// height of a fractal
const float FRACTAL_LEVEL = 4;		// level of a fractal
const sf::Color LINK_COLOR = sf::Color::White;		// color of text link
const sf::Color HOVER_COLOR = sf::Color::Yellow;	// color of mouse-over link
const sf::Color ACTIVE_COLOR = sf::Color::Blue;		// color of active text link 

enum TextButtonType{CLEAR, FRACTAL1, FRACTAL2, FRACTAL3, FRACTAL4};

vector<sf::Shape*> generateBoxFractal(float x, float y, float width, float height, int level, sf::Color color);
vector<sf::Shape*> generateCrossFractal(float x, float y, float width, float height, int level, sf::Color color);
vector<sf::Shape*> generateTriFractal(float x, float y, float width, float height, int level, sf::Color color);
vector<sf::Shape*> generateSquareFractal(float x, float y, float width, float height, int level, sf::Color color);

int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(1200, 800), "CSCI 120 - Fractals");

	// set up text buttons and white drawing area
	TextButton clearButton("Clear", 40, LINK_COLOR, TEXT_X, TEXT_HEIGHT);
	TextButton fractal1Button("Box Fractal", 40, ACTIVE_COLOR, TEXT_X, TEXT_HEIGHT * 2);
	TextButton fractal2Button("Snowflake", 40, LINK_COLOR, TEXT_X, TEXT_HEIGHT * 3);
	TextButton fractal3Button("Diamond", 40, LINK_COLOR, TEXT_X, TEXT_HEIGHT * 4);
	TextButton fractal4Button("Square", 40, LINK_COLOR, TEXT_X, TEXT_HEIGHT * 5);
	TextButton colorButton("Current Color:", 20, LINK_COLOR, TEXT_X, TEXT_HEIGHT * 6.5);
	sf::RectangleShape drawingArea(sf::Vector2f(WINDOW_WIDTH - TEXT_WIDTH - 5, WINDOW_HEIGHT- 10));
	drawingArea.setPosition(TEXT_WIDTH, 5);
	drawingArea.setFillColor(sf::Color::White);
	TextButtonType activeButton = FRACTAL1; // active text button (which tool is currently used)

	// set up color palette 
	sf::Image colorImage; // creates an image object
	if (!colorImage.loadFromFile("images/color-palette.png")) {    // loads the image file into the object 
		cerr << "Couldn't open image file!" << endl;
		return EXIT_FAILURE;
	}
	sf::Texture texture;
	texture.loadFromImage(colorImage);
	sf::Sprite colorPaletteSprite;		// sprite for color palette
	colorPaletteSprite.setTexture(texture);
	colorPaletteSprite.setPosition(sf::Vector2f(TEXT_X, TEXT_HEIGHT * 8));

	sf::Color currentColor = sf::Color::Red;	// current drawing color

	sf::RectangleShape colorRectangle(sf::Vector2f(50, 50)); // rectangle displaying the currently selected color
	colorRectangle.setFillColor(currentColor);
	colorRectangle.setOutlineThickness(1);
	colorRectangle.setOutlineColor(sf::Color::White);
	colorRectangle.setPosition(TEXT_X, TEXT_HEIGHT * 7);

	vector<sf::Shape*> shapeVector; // vector containing pointers to shapes to be drawn

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed) // "close requested" event: we close the window
				window.close();
			else if (event.type == sf::Event::MouseMoved) { // mouse moved event
				// mouse over effect for text buttons
				if (clearButton.contains(event.mouseMove.x, event.mouseMove.y)) {
					clearButton.setTextColor(HOVER_COLOR);
				}
				else
					clearButton.setTextColor(LINK_COLOR);

				if (fractal1Button.contains(event.mouseMove.x, event.mouseMove.y)) {
					fractal1Button.setTextColor(HOVER_COLOR);
				}
				else {
					if (activeButton == FRACTAL1)
						fractal1Button.setTextColor(ACTIVE_COLOR);
					else
						fractal1Button.setTextColor(LINK_COLOR);
				}
				if (fractal2Button.contains(event.mouseMove.x, event.mouseMove.y)) {
					fractal2Button.setTextColor(HOVER_COLOR);
				}
				else {
					if (activeButton == FRACTAL2)
						fractal2Button.setTextColor(ACTIVE_COLOR);
					else
						fractal2Button.setTextColor(LINK_COLOR);
				}
				if (fractal3Button.contains(event.mouseMove.x, event.mouseMove.y)) {
					fractal3Button.setTextColor(HOVER_COLOR);
				}
				else {
					if (activeButton == FRACTAL3)
						fractal3Button.setTextColor(ACTIVE_COLOR);
					else
						fractal3Button.setTextColor(LINK_COLOR);
				}
				if (fractal4Button.contains(event.mouseMove.x, event.mouseMove.y)) {
					fractal4Button.setTextColor(HOVER_COLOR);
				}
				else {
					if (activeButton == FRACTAL4)
						fractal4Button.setTextColor(ACTIVE_COLOR);
					else
						fractal4Button.setTextColor(LINK_COLOR);
				}
			}
			else if (event.type == sf::Event::MouseButtonPressed) { 
				if (event.mouseButton.button == sf::Mouse::Left &&  // clear button is clicked
					clearButton.contains(event.mouseButton.x, event.mouseButton.y)) {
					shapeVector.clear(); // clear shape vector
				}
				else if (event.mouseButton.button == sf::Mouse::Left &&  // fractal 1 button is clicked
					fractal1Button.contains(event.mouseButton.x, event.mouseButton.y)) {
					activeButton = FRACTAL1;
					fractal1Button.setTextColor(ACTIVE_COLOR); // change text color to indicate that this fractal type is selected
				}
				else if (event.mouseButton.button == sf::Mouse::Left &&  // fractal 2 button is clicked
					fractal2Button.contains(event.mouseButton.x, event.mouseButton.y)) {
					activeButton = FRACTAL2;
					fractal2Button.setTextColor(ACTIVE_COLOR); // change text color to indicate that this fractal type is selected
				}
				else if (event.mouseButton.button == sf::Mouse::Left &&  // fractal 3 button is clicked
					fractal3Button.contains(event.mouseButton.x, event.mouseButton.y)) {
					activeButton = FRACTAL3;
					fractal3Button.setTextColor(ACTIVE_COLOR); // change text color to indicate that this fractal type is selected
				}
				else if (event.mouseButton.button == sf::Mouse::Left &&  // fractal 4 button is clicked
					fractal4Button.contains(event.mouseButton.x, event.mouseButton.y)) {
					activeButton = FRACTAL4;
					fractal4Button.setTextColor(ACTIVE_COLOR); // change text color to indicate that this fractal type is selected
				}
				else if (event.mouseButton.button == sf::Mouse::Left &&  // drawing area is clicked
					drawingArea.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					if (activeButton == FRACTAL1) { // create box fractal
						vector<sf::Shape*> vec1 = generateBoxFractal(event.mouseButton.x, event.mouseButton.y,
							FRACTAL_WIDTH, FRACTAL_HEIGHT, FRACTAL_LEVEL, currentColor);
						shapeVector.insert(shapeVector.end(), vec1.begin(), vec1.end());
					}
					else if (activeButton == FRACTAL2) { 
						// creates the Vicsek Snowflake fractal
						vector<sf::Shape*> vec2 = generateCrossFractal(event.mouseButton.x, event.mouseButton.y,
							FRACTAL_WIDTH, FRACTAL_HEIGHT, FRACTAL_LEVEL, currentColor);
						shapeVector.insert(shapeVector.end(), vec2.begin(), vec2.end());
					}
					else if (activeButton == FRACTAL3) {
						// creates the Polyhedron Diamond fractal
						vector<sf::Shape*> vec3 = generateTriFractal(event.mouseButton.x, event.mouseButton.y,
							FRACTAL_WIDTH, FRACTAL_HEIGHT, FRACTAL_LEVEL, currentColor);
						shapeVector.insert(shapeVector.end(), vec3.begin(), vec3.end());
					}
					else if (activeButton == FRACTAL4) {
						// creates the Polyhedron Box fractal
						vector<sf::Shape*> vec4 = generateSquareFractal(event.mouseButton.x, event.mouseButton.y,
							FRACTAL_WIDTH, FRACTAL_HEIGHT, FRACTAL_LEVEL, currentColor);
						shapeVector.insert(shapeVector.end(), vec4.begin(), vec4.end());
					}
				}
				else if (event.mouseButton.button == sf::Mouse::Left &&  // color palette is clicked
					colorPaletteSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					// get selected color from color palette and change the active drawing color
					currentColor = colorImage.getPixel(event.mouseButton.x - colorPaletteSprite.getPosition().x, 
						event.mouseButton.y - colorPaletteSprite.getPosition().y);
					colorRectangle.setFillColor(currentColor); // change the color rectangle to show the current color
				}
			}
		}

		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw text buttons, color palette, and drawing area background
		window.draw(clearButton.getText());
		window.draw(fractal1Button.getText());
		window.draw(fractal2Button.getText());
		window.draw(fractal3Button.getText());
		window.draw(fractal4Button.getText());
		window.draw(colorButton.getText());
		window.draw(colorPaletteSprite);
		window.draw(colorRectangle);
		window.draw(drawingArea);

		// draw shapes
		for (int i = 0; i < shapeVector.size(); ++i) {
			window.draw(*shapeVector.at(i));
		}

		// end the current frame
		window.display();
	}

	return 0;
}

/**
 * Returns a vector containing pointers to Shape objects that create a box fractal of 
 * the given dimension, location, level, and color.
 * @param x			x-coordinate
 * @param y			y-coordinate
 * @param width		width in pixels
 * @param height	height in pixels
 * @param level		fractal level (nonnegative)
 * @param color		fill color
*/
vector<sf::Shape*> generateBoxFractal(float x, float y, float width, float height, int level, sf::Color color) {
	vector<sf::Shape*> vec;
	if (level <= 0) { // base case
		// create a rectangle of the given dimensions, position, and fill color
		sf::RectangleShape* rect = new sf::RectangleShape(sf::Vector2f(width, height));
		rect->setPosition(x, y);
		rect->setFillColor(color);
		vec.push_back(rect);
		return vec;
	}
	else { // recursive case
		float w = width / 3; // width of fractal of the next lower level
		float h = height / 3; // height of fractal of the next lower level
		// use recursive calls to create five fractals of the next lower level 
		//  at top-left, top-right, center, bottom-left, bottom, right
		// all the vectors returned by the recursive calls are merged into one vector
		vector<sf::Shape*> vec1 = generateBoxFractal(x, y, w, h, level - 1, color);
		vec.insert(vec.end(), vec1.begin(), vec1.end());
		vector<sf::Shape*> vec2 = generateBoxFractal(x + 2 * w, y, w, h, level - 1, color);
		vec.insert(vec.end(), vec2.begin(), vec2.end());
		vector<sf::Shape*> vec3 = generateBoxFractal(x + w, y + h, w, h, level - 1, color);
		vec.insert(vec.end(), vec3.begin(), vec3.end());
		vector<sf::Shape*> vec4 = generateBoxFractal(x, y + 2 * h, w, h, level - 1, color);
		vec.insert(vec.end(), vec4.begin(), vec4.end());
		vector<sf::Shape*> vec5 = generateBoxFractal(x + 2 * w, y + 2 * h, w, h, level - 1, color);
		vec.insert(vec.end(), vec5.begin(), vec5.end());
	}

	return vec;
}

vector<sf::Shape*> generateCrossFractal(float x, float y, float width, float height, int level, sf::Color color) {
	vector<sf::Shape*> vec;
	if (level <= 0) { // base case
	    // creates a square to make up a cross of the given dimensions, position, and fill color
		sf::RectangleShape* rect = new sf::RectangleShape(sf::Vector2f(width, height));
		rect->setPosition(x, y);
		rect->setFillColor(color);
		vec.push_back(rect);
		return vec;
	}
	

	else { // recursive case
		float w = width / 3; // width of fractal of the next lower level
		float h = height / 3; // height of fractal of the next lower level
		// use recursive calls to create five fractals of the next lower level 
		//  at top-middle, bottom-middle, center, left, right
		// all the vectors returned by the recursive calls are merged into one vector
		vector<sf::Shape*> vec1 = generateCrossFractal(x + w, y, w, h, level - 1, color); // top-middle square
		vec.insert(vec.end(), vec1.begin(), vec1.end());
		vector<sf::Shape*> vec2 = generateCrossFractal(x + 2 * w, y + h, w, h, level - 1, color); // right square
		vec.insert(vec.end(), vec2.begin(), vec2.end());
		vector<sf::Shape*> vec3 = generateCrossFractal(x + w, y + h, w, h, level - 1, color); // middle square
		vec.insert(vec.end(), vec3.begin(), vec3.end());
		vector<sf::Shape*> vec4 = generateCrossFractal(x, y + h, w, h, level - 1, color); // left square
		vec.insert(vec.end(), vec4.begin(), vec4.end());
		vector<sf::Shape*> vec5 = generateCrossFractal(x + w, y + 2 * h, w, h, level - 1, color); // bottom-middle square
		vec.insert(vec.end(), vec5.begin(), vec5.end());
	}

	return vec;
}

vector<sf::Shape*> generateTriFractal(float x, float y, float width, float height, int level, sf::Color color) {
	vector<sf::Shape*> vec;
	if (level <= 0) { // base case
		// create a diamond of the given dimensions, position, and fill color
		sf::ConvexShape tri;

		// resize tri to 7 points
		tri.setPointCount(7);

		// define the points
		tri.setPoint(0, sf::Vector2f(width / 2, 0));
		tri.setPoint(1, sf::Vector2f(width, height));
		tri.setPoint(2, sf::Vector2f(width / 2, 2 * height));
		tri.setPoint(3, sf::Vector2f(0, height));
		tri.setPoint(4, sf::Vector2f(width, height));
		tri.setPoint(5, sf::Vector2f(width / 2, 0));
		tri.setPoint(6, sf::Vector2f(0, height));

		sf::ConvexShape* triRec = new sf::ConvexShape(tri);

		triRec->setPosition(x, y);
		// sets fill and outline color of diamond
		triRec->setFillColor(sf::Color::Transparent);
		triRec->setOutlineColor(color);
		triRec->setOutlineThickness(1);
		vec.push_back(triRec);
		return vec;
	}
	else { // recursive case
		float w = width / 2; // width of fractal of the next lower level
		float h = height / 2; // height of fractal of the next lower level
		// use recursive calls to create five fractals of the next lower level 
		//  at top-left, top-right, center, bottom-left, bottom, right
		// all the vectors returned by the recursive calls are merged into one vector
		vector<sf::Shape*> vec1 = generateTriFractal(x + w / 2, y + h, w, h, level - 1, color); // top diamond
		vec.insert(vec.end(), vec1.begin(), vec1.end());
		vector<sf::Shape*> vec2 = generateTriFractal(x + w, y, w, h, level - 1, color); // left diamond
		vec.insert(vec.end(), vec2.begin(), vec2.end());
		vector<sf::Shape*> vec3 = generateTriFractal(x + 3 *w / 2, y + h, w, h, level - 1, color); // right diamond
		vec.insert(vec.end(), vec3.begin(), vec3.end());
		vector<sf::Shape*> vec4 = generateTriFractal(x + w, y + 2 * h, w, h, level - 1, color); // bottom diamond
		vec.insert(vec.end(), vec4.begin(), vec4.end());

	}

	return vec;
}

vector<sf::Shape*> generateSquareFractal(float x, float y, float width, float height, int level, sf::Color color) {
	vector<sf::Shape*> vec;
	if (level <= 0) { // base case
		// create a square with a cross inside with the given dimensions, position, and fill color	
		sf::ConvexShape square;

		// resize it to 8 points
		square.setPointCount(8);

		// define the points
		square.setPoint(0, sf::Vector2f(0, 0));
		square.setPoint(1, sf::Vector2f(width, 0));
		square.setPoint(2, sf::Vector2f(width, height));
		square.setPoint(3, sf::Vector2f(0, height));
		square.setPoint(4, sf::Vector2f(0, 0));
		square.setPoint(5, sf::Vector2f(width, height));
		square.setPoint(6, sf::Vector2f(0, height));
		square.setPoint(7, sf::Vector2f(width, 0));

		sf::ConvexShape* squareRec = new sf::ConvexShape(square);

		squareRec->setPosition(x, y);
		// set fill and outline color of fractal
		squareRec->setFillColor(sf::Color::White);
		squareRec->setOutlineColor(color);
		squareRec->setOutlineThickness(1);
		vec.push_back(squareRec);
		return vec;
	}
	else { // recursive case
		float w = width / 2; // width of fractal of the next lower level
		float h = height / 2; // height of fractal of the next lower level
		// use recursive calls to create five fractals of the next lower level 
		//  at top-left, top-right, center, bottom-left, bottom, right
		// all the vectors returned by the recursive calls are merged into one vector
		vector<sf::Shape*> vec1 = generateSquareFractal(x, y , w, h, level - 1, color); // top-left square fractal
		vec.insert(vec.end(), vec1.begin(), vec1.end());
		vector<sf::Shape*> vec2 = generateSquareFractal(x + w, y, w, h, level - 1, color); // top-right square fractal
		vec.insert(vec.end(), vec2.begin(), vec2.end());
		vector<sf::Shape*> vec3 = generateSquareFractal(x, y + h, w, h, level - 1, color); // bottom-left square fractal
		vec.insert(vec.end(), vec3.begin(), vec3.end());
		vector<sf::Shape*> vec4 = generateSquareFractal(x + w, y + h, w, h, level - 1, color); // bottom-right square fractal
		vec.insert(vec.end(), vec4.begin(), vec4.end());
		vector<sf::Shape*> vec5 = generateSquareFractal(x + w / 2, y + h / 2, w, h, level - 1, color); // center square fractal
		vec.insert(vec.end(), vec5.begin(), vec5.end());
	}

	return vec;
}