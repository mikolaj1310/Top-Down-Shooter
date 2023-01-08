#include "WeakEnemy.h"

WeakEnemy::WeakEnemy()
{
	
	walk.addFrame(sf::IntRect(41, 23, 54, 65));
	walk.addFrame(sf::IntRect(170, 22, 53, 67));
	walk.addFrame(sf::IntRect(299, 22, 53, 66));
	walk.addFrame(sf::IntRect(427, 22, 53, 65));
	walk.addFrame(sf::IntRect(555, 22, 53, 63));
	walk.addFrame(sf::IntRect(683, 24, 53, 57));
	walk.addFrame(sf::IntRect(811, 24, 53, 54));
	walk.addFrame(sf::IntRect(939, 25, 54, 51));
	walk.addFrame(sf::IntRect(1068, 25, 53, 51));

	walk.addFrame(sf::IntRect(45, 153, 53, 53));
	walk.addFrame(sf::IntRect(174, 153, 53, 55));
	walk.addFrame(sf::IntRect(302, 152, 53, 58));
	walk.addFrame(sf::IntRect(431, 152, 52, 60));
	walk.addFrame(sf::IntRect(559, 152, 52, 63));
	walk.addFrame(sf::IntRect(686, 151, 53, 66));
	walk.addFrame(sf::IntRect(813, 150, 54, 68));
	walk.addFrame(sf::IntRect(941, 150, 54, 69));
	walk.addFrame(sf::IntRect(1068, 149, 55, 69));

	walk.addFrame(sf::IntRect(43, 277, 56, 67));
	walk.addFrame(sf::IntRect(171, 276, 56, 65));
	walk.addFrame(sf::IntRect(298, 276, 56, 61));
	walk.addFrame(sf::IntRect(426, 276, 56, 58));
	walk.addFrame(sf::IntRect(554, 276, 55, 58));
	walk.addFrame(sf::IntRect(682, 277, 54, 56));
	walk.addFrame(sf::IntRect(809, 277, 54, 57));
	walk.addFrame(sf::IntRect(937, 278, 54, 58));
	walk.addFrame(sf::IntRect(1065, 278, 53, 60));

	walk.addFrame(sf::IntRect(41, 406, 53, 62));
	walk.addFrame(sf::IntRect(169, 406, 54, 64));
	walk.addFrame(sf::IntRect(297, 407, 54, 65));
	walk.setFrameSpeed(1.f / 30.f);

	currentAnimation = &walk;
	setTextureRect(currentAnimation->getCurrentFrame());

	//setVelocity(200, 200);
}

WeakEnemy::~WeakEnemy()
{
}

void WeakEnemy::update(float dt, sf::Vector2f playerPos, sf::Vector2f enemyPos)
{
	currentAnimation = &walk;
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());

	float angle = atan2(playerPos.y - enemyPos.y, playerPos.x - enemyPos.x);
	move(cos(angle) * velocity.x * dt, velocity.y * sin(angle) * dt);
}

void WeakEnemy::collisionResponse(MySprite* sp)
{
	
}