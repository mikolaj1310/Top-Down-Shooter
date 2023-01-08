#pragma once
#include "MySprite.h"
#include "Animation.h"
class Coin : public MySprite
{
public:
	Coin();
	~Coin();

	void update(float dt);



private:
	Animation spin;
	Animation* currentAnimation;
};

