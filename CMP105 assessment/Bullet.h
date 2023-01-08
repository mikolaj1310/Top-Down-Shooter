#pragma once
#include "MySprite.h"
#include "Animation.h"
#include "Collision.h"
class Bullet : public MySprite
{
public:
	Bullet();
	~Bullet();

	void update(float dt, float angle);

	void collisionResponse(MySprite * sp);


protected:
	Animation airborn;
	Animation* currentAnimation;
	Input* input;
	Collision* collision;

	float angle;
};