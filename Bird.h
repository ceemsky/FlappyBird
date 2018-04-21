#pragma once
#include <SFML\Graphics.hpp>
#include "Variables.h"
class Bird
{
	sf::CircleShape shape;
	sf::Color birdColor = sf::Color::White;
	sf::Sprite birdSprite;
	sf::Texture birdTexture;
	double speed;	//shows how fast bird is moving in Y axis
	double maxSpeed = 10;
	double fallingAcceleration = Variables::winHeight*0.017*.0625;
	sf::Vector2f startPosition = sf::Vector2f(Variables::birdDistFromEdge, Variables::winHeight / 2);
	bool isDead;
	
public:
	Bird();
	~Bird();
	void flyUp();
	void gravitation();
	void move();
	void kill();
	void setAlive();
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f position);
	double getSpeed();
	bool dead();
	bool isUnderScreen();
	void rotate();
};

