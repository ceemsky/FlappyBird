#pragma once
#include "Wall.h"
#include <vector>
#include "Variables.h"
#include <random>
#include<SFML/Graphics.hpp>
class WallHolder
{
	friend class Wall;
	std::vector<Wall> walls;
	double speed = Variables::winWidth*0.0078125;
	int howManyPasses = 0;


public:
	WallHolder();
	~WallHolder();
	void add(Wall wall);
	void addRandomWall();
	Wall& operator[] (int i);
	void generateWalls();
	void move();
	void draw(sf::RenderWindow &window);
	bool checkCollision(sf::Vector2f birdPos);
	int getVecSize();
	int getScore();
	void cleanScore();
	void deleteWalls();
};

