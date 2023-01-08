#include "Player.h"
#include <typeinfo>


Player::Player()
{
	
	rifle.addFrame(sf::IntRect(0, 0, 40, 17));

	rifleShoot.addFrame(sf::IntRect(0, 0, 40, 17));
	rifleShoot.addFrame(sf::IntRect(53, 0, 40, 17));
	rifleShoot.addFrame(sf::IntRect(52, 27, 40, 17));
	rifleShoot.setFrameSpeed(1.f / 9.f);

	currentAnimation = &rifle;
	setTextureRect(currentAnimation->getCurrentFrame());

	setVelocity(400, 400);
	health = 4;
}

Player::~Player()
{
}

void Player::update(float dt, Input* input)
{
	if (getPosition().x < 100)
		setPosition(100, getPosition().y);
	if (getPosition().x > 695)
		setPosition(695, getPosition().y);
	if (getPosition().y < 100)
		setPosition(getPosition().x, 100);
	if (getPosition().y > 695)
		setPosition(getPosition().x, 695);

	if (input->isMouseLeftDown())
	{
		if (ammo != 0)
		{
			currentAnimation = &rifleShoot;
		}
		else
			currentAnimation = &rifle;
	}
	else
		currentAnimation = &rifle;
	
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());

	if (input->isKeyDown(sf::Keyboard::D))
	{
		currentAnimation->animate(dt);
		move(velocity.x*dt, 0);
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		currentAnimation->animate(dt);
		move(-velocity.x*dt, 0);
	}
	if (input->isKeyDown(sf::Keyboard::W))
	{
		currentAnimation->animate(dt);
		move(0, -velocity.y*dt);
	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		currentAnimation->animate(dt);
		move(0, velocity.y*dt);
	}


}

void Player::collisionResponse(MySprite* sp)
{
	WeakEnemy* isWeakEnemy = dynamic_cast<WeakEnemy*>(sp);
	
	if (isWeakEnemy != 0)
	{
		if (health > 0)
		{
			health = health - 1;
		}
	}
	
	AmmoPickup* isAmmoPickup = dynamic_cast<AmmoPickup*>(sp);

	if (isAmmoPickup != 0)
	{
		if (money >= 20)
		{
			ammo = ammo + 10;
			money = money - 20;
		}
	}
}