#pragma once
#include "MySprite.h"
#include "Animation.h"
#include "Collision.h"
class WeakEnemy : public MySprite
{
public:
	WeakEnemy();
	~WeakEnemy();

	void update(float dt, sf::Vector2f playerPos, sf::Vector2f enemyPos);

	void collisionResponse(MySprite * sp);


protected:
	Animation walk;
	Animation* currentAnimation;
	Collision* collision;

	
};