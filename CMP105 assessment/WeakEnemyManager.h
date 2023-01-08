#pragma once
#include "WeakEnemy.h"
#include "MySprite.h"
#include "Player.h"
#include "BulletManager.h"
#include "Bullet.h"
#include <math.h>
#include <vector>
class WeakEnemyManager
{
public:
	WeakEnemyManager();
	~WeakEnemyManager();

	void spawn();
	void update(float dt, sf::Vector2f playerPos, Player& player);
	void deathCheck(Player& player);
	void render(sf::RenderWindow* window);
	std::vector<WeakEnemy>* getWeakEnemy() { return &weakEnemies; };

	void setBulletManager(BulletManager* bulletManagerThing) { bulletManager = bulletManagerThing; };
	void setBulletVector() { bulletsVector = bulletManager->getBullets(); };
private:
	BulletManager * bulletManager;
	std::vector<Bullet>* bulletsVector; 
	sf::Clock spawnTimer;
	sf::Time time;
	std::vector<WeakEnemy> weakEnemies;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
	
	float multiplier = 1;
	float incrementer = 0;
	int counter = 0;
	float rotation;
};