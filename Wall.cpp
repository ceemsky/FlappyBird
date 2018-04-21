#include "Wall.h"



Wall::Wall(int gapHeight) :gapHeight(gapHeight)
{
	upperShape = sf::RectangleShape(sf::Vector2f(Variables::wallWidth, gapHeight));
	upperShape.setFillColor(wallColor);
	upperShape.setPosition(Variables::wallStartX, 0);

	lowerShape = sf::RectangleShape(sf::Vector2f(Variables::wallWidth, Variables::winHeight - gapHeight - Variables::wallGapSize));
	lowerShape.setFillColor(wallColor);
	lowerShape.setPosition(Variables::wallStartX, gapHeight + Variables::wallGapSize);
}
Wall::~Wall()
{
}
sf::Vector2f Wall::getPosition() {
	return upperShape.getPosition();
}
void Wall::setPosition(double x, double y) {
	upperShape.setPosition(x, y);
	lowerShape.setPosition(x, y + gapHeight + Variables::wallGapSize);
}
void Wall::move(double speed) {
	upperShape.move(-speed, 0);
	lowerShape.move(-speed, 0);
}
void Wall::draw(sf::RenderWindow& window) {
	window.draw(upperShape);
	window.draw(lowerShape);
}
bool Wall::isOutOfDisplay() {
	if (upperShape.getPosition().x < -Variables::wallWidth)
		return true;
	else return false;
}
bool Wall::collided(sf::Vector2f birdPos) {
	if (birdPos.x+Variables::birdSize >= upperShape.getPosition().x && birdPos.x-Variables::birdSize <= upperShape.getPosition().x + Variables::wallWidth)
		if (birdPos.y-Variables::birdSize < gapHeight || birdPos.y+Variables::birdSize >gapHeight + Variables::wallGapSize)
			return true;
	return false;
}
bool Wall::isPassed(sf::Vector2f birdPos) {
	if (birdPos.x > upperShape.getPosition().x + Variables::wallWidth && !collided(birdPos))
		return true;
	else return false;
}
