#pragma once
#include "MySprite.h"
#include "Animation.h"
#include "Player.h"
class HealthSprite : public MySprite
{
public:
	HealthSprite();
	~HealthSprite();

	void update(float dt, Player &player);

private:
	Animation currentHealth0;
	Animation currentHealth1;
	Animation currentHealth2;
	Animation currentHealth3;
	Animation currentHealth4;
	
	Animation* currentAnimation;
};

