#pragma once
#include "SFML\Graphics.hpp"
#include "Input.h"

class MySprite : public sf::RectangleShape
{
public:
	MySprite();
	~MySprite();

	virtual void update(float dt);

	// sprite speed and direction
	void setVelocity(sf::Vector2f vel);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity();

	// sprite state
	void setAlive(bool live) { alive = live; };
	bool isAlive() { return alive; };	

	// for sprite collision
	std::string isCollider() { return collider; };
	void setCollider(std::string b) { collider = b; };
	sf::FloatRect getCollisionBox();
	void setCollisionBox(float x, float y, float width, float height) { collisionBox = sf::FloatRect(x, y, width, height); };
	void setCollisionBox(sf::FloatRect fr) { collisionBox = fr; };
	virtual void collisionResponse(MySprite* sp);

	// input component
	void setInput(Input* in) { input = in; };
	float health = 4;
	float money = 100;
	float ammo = 30;
	float score = 0;
protected:
	// Sprite properties
	sf::Vector2f velocity;
	bool alive;
	

	// Collision vars
	sf::FloatRect collisionBox;
	std::string collider;

	// input component
	Input* input;
};