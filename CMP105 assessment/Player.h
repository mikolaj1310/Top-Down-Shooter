#pragma once
#include "MySprite.h"
#include "Animation.h"
#include "Collision.h"
#include "WeakEnemy.h"
#include "BulletManager.h"
#include "AmmoPickup.h"
class Player : public MySprite
{
public:
	Player();
	~Player();

	void update(float dt, Input* input);

	void collisionResponse(MySprite * sp);
	int getAmmo() { return ammo; };
	void setAmmo(float passedAmmo) { ammo = passedAmmo; };

protected:
	Animation rifle;
	Animation rifleShoot;
	Animation* currentAnimation;
	Input* input;
	//class BulletManager* bulletManager;
	class AmmoPickup* ammoPickup;
	Collision* collision;

};