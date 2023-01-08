#include "HealthSprite.h"



HealthSprite::HealthSprite()
{
	currentHealth4.addFrame(sf::IntRect(0, 285, 294, 56));
	currentHealth3.addFrame(sf::IntRect(0, 214, 295, 56));
	currentHealth2.addFrame(sf::IntRect(0, 144, 295, 56));
	currentHealth1.addFrame(sf::IntRect(0, 70, 295, 56));
	currentHealth0.addFrame(sf::IntRect(0, 0, 295, 56));

	currentAnimation = &currentHealth4;
	setTextureRect(currentAnimation->getCurrentFrame());
}


HealthSprite::~HealthSprite()
{
}

void HealthSprite::update(float dt, Player &player)
{
	if (player.health == 4)
		currentAnimation = &currentHealth4;
	else if (player.health == 3)
		currentAnimation = &currentHealth3;
	else if (player.health == 2)
		currentAnimation = &currentHealth2;
	else if (player.health == 1)
		currentAnimation = &currentHealth1;
	else
		currentAnimation = &currentHealth0;

	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());
}