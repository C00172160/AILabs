#include "SFML\Graphics.hpp"

#ifndef PLAYER_H
#define PLAYER_H


class Player
{
private:
	sf::Vector2f mPosition;
	sf::Vector2f mVelocity;
	sf::Sprite mSprite;
public:
    Player(sf::Vector2f pos, sf::Vector2f vel, sf::Texture &tex);
	void Update(sf::Vector2f windowSize);
	void borderCheck(sf::Vector2f windowSize);
	sf::Sprite getSprite();
	
};
#endif

