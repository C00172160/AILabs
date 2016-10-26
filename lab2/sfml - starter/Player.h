#include "SFML\Graphics.hpp"

#ifndef PLAYER_H
#define PLAYER_H


class Player
{
private:
	sf::Vector2f mPosition;
	sf::Vector2f mVelocity = sf::Vector2f(0,0);
	float mSpeed = 0;;
	float maxSpeed = 10;
	sf::Sprite mSprite;
	sf::Vector2f direction;
	float rotation = 0;
public:
    Player(sf::Vector2f pos, sf::Texture &tex);
	void Update(sf::Vector2f windowSize);
	void borderCheck(sf::Vector2f windowSize);
	sf::Sprite getSprite();
	
};
#endif

