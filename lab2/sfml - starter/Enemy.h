#pragma once
#include "SFML\Graphics.hpp"

#ifndef ENEMY_H
#define ENEMY_H


class Enemy
{
private:
	sf::Vector2f mPosition;
	sf::Vector2f mVelocity;
	sf::Sprite mSprite;
public:
	Enemy(sf::Vector2f pos, sf::Vector2f vel, sf::Texture &tex);
	void Update(sf::Vector2f windowSize);
	void borderCheck(sf::Vector2f windowSize);
	sf::Sprite getSprite();

};
#endif

