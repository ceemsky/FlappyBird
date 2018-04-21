#include "Bird.h"



Bird::Bird()
{
	shape = sf::CircleShape(Variables::birdSize);
	shape.setFillColor(birdColor);
	shape.setPosition(startPosition);
	shape.setOrigin(Variables::birdSize, Variables::birdSize);
	speed = 0;
	isDead = true;

	
	birdTexture.loadFromFile("frame-1.png");
	birdSprite.setTexture(birdTexture);
	birdSprite.setPosition(startPosition);
	sf::FloatRect birdRect = birdSprite.getLocalBounds();
	birdSprite.setOrigin(birdRect.left + birdRect.width / 2., birdRect.top + birdRect.height / 2.);
	birdSprite.setScale(Variables::birdSize/birdRect.width*3, Variables::birdSize/birdRect.width*3);
}
Bird::~Bird()
{
}
void Bird::flyUp() {
	speed = -maxSpeed;
}
void Bird::gravitation() {
	speed += fallingAcceleration;
	if (speed > maxSpeed)
		speed = maxSpeed;
}
void Bird::move() {
	if (shape.getPosition().y + speed >= 0) {
		shape.move(0, speed);
		birdSprite.setPosition(shape.getPosition());
	}
	else speed /=10;
}
void Bird::kill() {
	isDead = true;
}
void Bird::setAlive() {
	isDead = false;
	setPosition(sf::Vector2f(Variables::birdDistFromEdge, Variables::winHeight / 2));
	speed = -maxSpeed;
}
void Bird::draw(sf::RenderWindow& window) {
	window.draw(shape);
	window.draw(birdSprite);
}
sf::Vector2f Bird::getPosition() {
	return shape.getPosition();
}
void Bird::setPosition(sf::Vector2f position) {
	shape.setPosition(position);
}
double Bird::getSpeed() {
	return speed;
}
bool Bird::dead() {
	return isDead;
}
bool Bird::isUnderScreen() {
	if (shape.getPosition().y -Variables::birdSize > Variables::winHeight)return true;
	else return false;
}
void Bird::rotate() {
	birdSprite.setRotation(speed*4.5);
}