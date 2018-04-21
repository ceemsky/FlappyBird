#include "myText.h"

myText::myText(std::string content,sf::Font font,sf::Vector2f position):content(content),font(font){
	text = sf::Text(content, font);
	text.setFillColor(sf::Color::Black);
	text.setOutlineColor(sf::Color::White);
	text.setOutlineThickness(3);
	centerOrigin();
	text.setPosition(position);
}


myText::~myText()
{
}
void myText::setString(std::string content) {
	text.setString(content);
}
void myText::centerOrigin() {
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin((textRect.left + textRect.width) / 2., (textRect.top + textRect.height) / 2.);
}
void myText::draw(sf::RenderWindow& window) {
	window.draw(text);
}
sf::Text& myText::getText() {
	return text;
}