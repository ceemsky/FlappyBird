#pragma once
#include <random>
#include<SFML/Graphics.hpp>
static class Variables
{
public:
	static const int winWidth = 640;
	static const int winHeight = 480;

	static const int wallGapSize = winHeight*0.3125; 
	static const int wallWidth = winWidth*0.0625;
	static const int wallDistance = winWidth*0.4;
	static const int wallStartX = winWidth;
	static const int wallMinGapHeight = winHeight / 12;

	static const int birdSize = wallGapSize/10.;
	static const int birdDistFromEdge = birdSize*3;

	static int randInt(int min, int max);
	static void centerTextOrigin(sf::Text& text);
};

