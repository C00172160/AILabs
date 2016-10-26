#include "stdafx.h"
#include "Player.h"
#include <cmath>


Player::Player(sf::Vector2f pos, sf::Texture &tex)
{
	mPosition = pos;
	mSprite.setTexture(tex);
	mSprite.setPosition(pos);
	
	mSprite.setOrigin(16, 16);
}

void Player::Update(sf::Vector2f windowSize)
{


	borderCheck(windowSize);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (mSpeed < maxSpeed)
		{
			mSpeed++;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (mSpeed > 0)
		{
			mSpeed--;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rotation-=5;
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rotation+=5;
	
	}


		direction.x = (float)cos(rotation*(3.14 / 180));
		direction.y = (float)sin(rotation*(3.14 / 180));

    	mVelocity.x = direction.x * mSpeed;
	    mVelocity.y = direction.y * mSpeed;

	   mPosition += mVelocity;
	   mSprite.setPosition(mPosition);

	if (rotation > 360)
	{
		rotation = 0;
	}
	if (rotation < 0)
	{
		rotation = 360;
	}
	mSprite.setRotation(rotation);

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


