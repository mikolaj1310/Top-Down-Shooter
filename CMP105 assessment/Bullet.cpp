#include "Bullet.h"



Bullet::Bullet()
{
	//angle = atan2(playerPos.y - input->getMouseY(), playerPos.x - input->getMouseX());
	airborn.addFrame(sf::IntRect(0, 0, 100, 375));
	currentAnimation = &airborn;
	setTextureRect(currentAnimation->getCurrentFrame());

}


Bullet::~Bullet()
{
}

void Bullet::update(float dt, float angle)
{
	currentAnimation->animate(dt);

	//velocity.x = sin(angle) * 100;
	//velocity.y = cos(angle) * 100;
	velocity.x = (float)sin((3.14159265 / 180.0f) * (270.0f - angle));
	velocity.y = (float)cos((3.14159265 / 180.0f) * (270.0f - angle));

	move(velocity.x * 700 * dt, velocity.y* 700 * dt);
}

void Bullet::collisionResponse(MySprite* sp)
{
	/*
	WeakEnemy* objectName = dynamic_cast<WeakEnemy*>(sp);

	if (objectName != 0)
	{
		if (health > 0)
		{
			health = health - 1;
		}
	}*/
}