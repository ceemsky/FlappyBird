#include <SFML/Graphics.hpp>
#include "Wall.h"
#include <vector>
#include <iostream>
#include "Variables.h"
#include "WallHolder.h"
#include "Bird.h"
#include "myText.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(Variables::winWidth, Variables::winHeight), "sth");
	window.setFramerateLimit(60);
	WallHolder someHolder;
	someHolder.generateWalls();
	Bird someBird;
	int score = 0;
	bool gameStartFlag = false;
	bool isKeyPressed = false;

	sf::Font font;
	font.loadFromFile("arial.ttf");

	/*myText scoreT("0", font, sf::Vector2f(Variables::winWidth / 2, Variables::winHeight / 6));
	myText gameOverT("GameOver", font, sf::Vector2f(Variables::winWidth / 2, Variables::winHeight / 3));
	myText pressToStartT("press spacebar to start", font, sf::Vector2f(Variables::winWidth / 2, Variables::winHeight / 1.5));*/

	sf::Text scoreT;
	scoreT.setFont(font);
	scoreT.setFillColor(sf::Color::Black);
	scoreT.setOutlineColor(sf::Color::White);
	scoreT.setOutlineThickness(3);
	Variables::centerTextOrigin(scoreT);
	scoreT.setPosition(Variables::winWidth / 2, Variables::winHeight / 6);

	sf::Text gameOverT;
	gameOverT.setFont(font);
	gameOverT.setFillColor(sf::Color::Black);
	gameOverT.setOutlineColor(sf::Color::White);
	gameOverT.setOutlineThickness(3);
	gameOverT.setScale(2, 2);
	gameOverT.setString("Game Over");
	Variables::centerTextOrigin(gameOverT);
	gameOverT.setPosition(Variables::winWidth / 2, Variables::winHeight / 3);

	sf::Text pressToStartT;
	pressToStartT.setFont(font);
	pressToStartT.setFillColor(sf::Color::Black);
	pressToStartT.setOutlineColor(sf::Color::White);
	pressToStartT.setOutlineThickness(3);
	pressToStartT.setScale(.5, .5);
	pressToStartT.setString("press spacebar to start");
	Variables::centerTextOrigin(pressToStartT);
	pressToStartT.setPosition(Variables::winWidth / 2, Variables::winHeight / 1.5);



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed: {
				window.close();
				break;
			}
			case sf::Event::KeyPressed: {

				if (event.key.code == sf::Keyboard::Space && !isKeyPressed) {

					someBird.flyUp();	// code while game is running or havent started
					isKeyPressed = true;

					//code while game havent started
					gameStartFlag = true;

					//code while game starts
					if (someBird.dead()) {

						someHolder.deleteWalls();
						someHolder.generateWalls();
						someHolder.cleanScore();
						window.clear();
						someBird.setAlive();
						std::cout << someBird.getSpeed() << std::endl;
					}
				}
				break;
			}
			case sf::Event::KeyReleased: {
				if (event.key.code == sf::Keyboard::Space)
					isKeyPressed = false;
				break;
			}
			}
		}
		scoreT.setString(std::to_string(someHolder.getScore()));
		
		if (!someBird.dead()) {										//game running
			someBird.gravitation();
			someBird.move();
			someHolder.move();
		}
		if (!someBird.dead() && someHolder.checkCollision(someBird.getPosition()) || someBird.isUnderScreen())
			someBird.kill();
		window.clear();
		someHolder.draw(window);
		someBird.draw(window);
		someBird.rotate();
		window.draw(scoreT);
		
		if (someBird.dead()) {										//game ended-ready to next
			if (gameStartFlag)
				window.draw(gameOverT);
			window.draw(pressToStartT);
		}
		window.display();
	//	std::cout << someBird.getSpeed() << std::endl;
	}
	return 0;
}