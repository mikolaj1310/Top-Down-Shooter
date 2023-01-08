#include "Coin.h"



Coin::Coin()
{
	spin.addFrame(sf::IntRect(0, 21, 109, 110));
	spin.addFrame(sf::IntRect(171, 21, 109, 110));
	spin.addFrame(sf::IntRect(343, 21, 109, 110));
	spin.addFrame(sf::IntRect(510, 21, 109, 110));
	spin.addFrame(sf::IntRect(678, 21, 109, 111));

	spin.addFrame(sf::IntRect(0, 188, 109, 110));
	spin.addFrame(sf::IntRect(169, 187, 109, 111));
	spin.addFrame(sf::IntRect(338, 187, 109, 111));
	spin.addFrame(sf::IntRect(504, 187, 109, 111));
	spin.addFrame(sf::IntRect(679, 187, 109, 111));
	spin.setFrameSpeed(1.f / 10.f);

	currentAnimation = &spin;
	setTextureRect(currentAnimation->getCurrentFrame());
}


Coin::~Coin()
{
}

void Coin::update(float dt)
{
	currentAnimation = &spin;
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());
}

