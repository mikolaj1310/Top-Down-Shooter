#pragma once
#include "Bullet.h"
#include "Player.h"
#include "WeakEnemy.h"
#include "MySprite.h"
#include <math.h>
#include <vector>
class BulletManager
{
public:
	BulletManager();
	~BulletManager();

	void spawn(sf::Vector2f spawnPosition, Input* input);
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);
	std::vector<Bullet>* getBullets() { return &bullets; };
	/*void setWeakEnemyManager(WeakEnemyManager* weakEnemyManagerThing) { weakEnemyManager = weakEnemyManagerThing; };
	void setWeakEnemies() { weakEnemies = weakEnemyManager->getWeakEnemy(); };*/
private:
	//WeakEnemyManager * weakEnemyManager;
	
	std::vector<WeakEnemy>* weakEnemies;
	std::vector<Bullet> bullets;
	sf::Texture texture;




	float rotation[20] = { 0 };
	int counter = 0;
};

