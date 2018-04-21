#include "Variables.h"



int Variables::randInt(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(min, max);
	return dist(gen);
}
void Variables::centerTextOrigin(sf::Text& text) {
		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin((textRect.left + textRect.width) / 2., (textRect.top + textRect.height) / 2.);
}
