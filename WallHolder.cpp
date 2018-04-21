#include "WallHolder.h"



WallHolder::WallHolder()
{
}


WallHolder::~WallHolder()
{
}
void WallHolder::add(Wall wall) {
	walls.push_back(wall);
}
void WallHolder::addRandomWall() {
	Wall tempWall(Wall(Variables::randInt(0, Variables::winHeight - Variables::wallGapSize)));
	if(walls.size()>0)
		tempWall.setPosition(walls[walls.size()-1].getPosition().x + Variables::wallDistance);
	walls.push_back(tempWall);
}
Wall& WallHolder::operator[] (int i) {
	return walls[i];
}
void WallHolder::generateWalls() {
	int wallsCounter = Variables::winWidth / Variables::wallDistance + 1;
	for (int i = 0; i < wallsCounter; i++) {
		addRandomWall();
	}
}
void WallHolder::move() {
	for (int i = 0; i < walls.size(); i++) {
		walls[i].move(speed);


		if (walls[i].isOutOfDisplay()) {
			walls.erase(walls.begin() + i);	
			howManyPasses++;
			addRandomWall();
		}
	}
}
void WallHolder::draw(sf::RenderWindow &window) {
	for(int i=0;i<walls.size();i++)
		walls[i].draw(window);
}
bool WallHolder::checkCollision(sf::Vector2f birdPos) {
	if (walls[0].collided(birdPos))
		return true;
	else
		return false;
}
int WallHolder::getVecSize() {
	return walls.size();
}
int WallHolder::getScore() {
	return howManyPasses;
}
void WallHolder::cleanScore() {
	howManyPasses = 0;
}
void WallHolder::deleteWalls() {
	walls.clear();
}

