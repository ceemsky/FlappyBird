#pragma once
#include<SFML/Graphics.hpp>
class GameMode
{
	mode gMode;


public:
	GameMode(mode gMode);
	~GameMode();
	void runGame(sf::Event event, sf::RenderWindow& window);
};

