// sfml - starter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

int main()
{
 	sf::Vector2f windowSize(1024, 768);
    sf::RenderWindow window(sf::VideoMode(windowSize.x,windowSize.y), "lab1");
	window.setFramerateLimit(60);
	sf::Texture playerTexture;
	sf::Texture enemyTexture;
	playerTexture.setSmooth(true);
	enemyTexture.setSmooth(true);
	if (!playerTexture.loadFromFile("Player.png"))
	{
		// error...
	}
	if (!enemyTexture.loadFromFile("Enemy.png"))
	{
		// error...
	}
	
	Player player1(sf::Vector2f((window.getSize().x /3) * 2 , window.getSize().y / 2), playerTexture);
	Enemy enemy1(sf::Vector2f((window.getSize().x / 3), window.getSize().y / 2), sf::Vector2f(0, -5), enemyTexture);
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		player1.Update(windowSize);
		enemy1.Update(windowSize);

		window.clear();
		window.draw(player1.getSprite());
		window.draw(enemy1.getSprite());
		window.display();
	}

	return 0;
}

