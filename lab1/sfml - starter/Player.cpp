#include "stdafx.h"
#include "Player.h"


Player::Player(sf::Vector2f pos,sf::Vector2f vel, sf::Texture &tex)
{
	mPosition = pos;
	mVelocity = vel;
	mSprite.setTexture(tex);
	mSprite.setPosition(pos);
}

void Player::Update(sf::Vector2f windowSize)
{
	mPosition += mVelocity;
	mSprite.setPosition(mPosition);

	borderCheck(windowSize);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		mVelocity.y--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		mVelocity.y++;
	}



}

void Player::borderCheck(sf::Vector2f windowSize)
{
	if (mPosition.x > windowSize.x)//past rightmost border
	{
		mPosition.x = 0 - mSprite.getGlobalBounds().width;

	}

	if (mPosition.x + mSprite.getGlobalBounds().width < 0)//past leftmost border
	{
		mPosition.x = windowSize.x - 1;

	}

	if (mPosition.y + mSprite.getGlobalBounds().height < 0)//past topmost border
	{
		mPosition.y = windowSize.y - 1;

	}

	if (mPosition.y  > windowSize.y)//past bottommost border
	{
		mPosition.y = 0 - mSprite.getGlobalBounds().height;

	}
}

sf::Sprite Player::getSprite()
{
	return mSprite;
}


