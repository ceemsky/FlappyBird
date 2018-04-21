#pragma once
#include <SFML/Graphics.hpp>
#include "Variables.h"
class Wall
{
	int gapHeight;
	sf::Color wallColor = sf::Color::White;
	sf::RectangleShape upperShape;
	sf::RectangleShape lowerShape;
public:
	Wall(int gapHeight);
	~Wall();
	sf::Vector2f getPosition();
	void setPosition(double x, double y=0);
	void move(double speed);								//shifts single wall to left
	void draw(sf::RenderWindow& window);
	bool isOutOfDisplay();
	bool collided(sf::Vector2f birdPos);
	bool isPassed(sf::Vector2f birdPos);
};

