#pragma once
#include<SFML/Graphics.hpp>
class myText: public sf::Text
{
	sf::Font font;
	std::string content;
	sf::Text text;
public:
	myText(std::string content,sf::Font font,sf::Vector2f position);
	~myText();
	void setString(std::string content);
	void centerOrigin();
	void draw(sf::RenderWindow& window);
	sf::Text& getText();
};

