#pragma once
#include "MySprite.h"
#include "Player.h"

class AmmoPickup : public MySprite
{
public:
	AmmoPickup();
	~AmmoPickup();

	void update(float dt);
};

