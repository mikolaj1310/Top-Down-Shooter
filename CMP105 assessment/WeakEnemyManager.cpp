#include "WeakEnemyManager.h"

WeakEnemyManager::WeakEnemyManager()
{
	
	counter = 0;
	texture.loadFromFile("gfx/Zombie.png");

	for (int i = 0; i < 40; i++)
	{
		weakEnemies.push_back(WeakEnemy());
		weakEnemies[i].setAlive(false);
		weakEnemies[i].setTexture(&texture);
		weakEnemies[i].setSize(sf::Vector2f(81, 97));
		weakEnemies[i].setCollisionBox(sf::FloatRect(-40, -48, 81, 97));
		weakEnemies[i].setOrigin(81 / 2, 97 / 2);
	}
}

WeakEnemyManager::~WeakEnemyManager()
{
}

void WeakEnemyManager::update(float dt, sf::Vector2f playerPos, Player& player)
{
	for (int i = 0; i < weakEnemies.size(); i++)
	{
		if (weakEnemies[i].isAlive())
			rotation = (atan2(weakEnemies[i].getPosition().y - playerPos.y , 
				weakEnemies[i].getPosition().x - playerPos.x)) * 180 / 3.14159265;
			weakEnemies[i].setRotation(rotation + 270);

			weakEnemies[i].update(dt , playerPos, weakEnemies[i].getPosition());
	}
	deathCheck(player);
}

void WeakEnemyManager::spawn()
{
	time = spawnTimer.getElapsedTime();

	
	if (time.asMilliseconds() > (1000 - incrementer) * multiplier)
	{
		if (time.asMilliseconds() <= 300)
			multiplier = 0.95;
		else
			incrementer += 3;
		if (!weakEnemies[counter].isAlive())
		{
			spawnPoint = sf::Vector2f(rand() % 700 + 100, 100);
			weakEnemies[counter].setAlive(true);
			weakEnemies[counter].setVelocity(rand() % 400 + 100, rand() % 400 + 100);
			weakEnemies[counter].setPosition(spawnPoint);
			
			return;
		}
		if (counter >= 39)
			counter = 0;
		else
			counter++;
		spawnTimer.restart();
	}
	
}

void WeakEnemyManager::deathCheck(Player& player)
{
	//std::vector<Bullet>* bulletsVector = bulletManager->getBullets();
	for (int i = 0; i < weakEnemies.size(); i++)
	{
		if (weakEnemies[i].isAlive())
		{
			
			if (weakEnemies[i].getPosition().x < -100)
			{
				weakEnemies[i].setAlive(false);
			}
			if (weakEnemies[i].getPosition().x > 900)
			{
				weakEnemies[i].setAlive(false);
			}
			if (weakEnemies[i].getPosition().y < -100)
			{
				weakEnemies[i].setAlive(false);
			}
			if (weakEnemies[i].getPosition().y > 900)
			{
				weakEnemies[i].setAlive(false);
			}
			if (Collision::checkBoundingBox(&player, &weakEnemies[i]))
			{
				player.collisionResponse(&weakEnemies[i]);
				weakEnemies[i].setAlive(false);
			}

			std::vector<Bullet>& currentBullet = *bulletsVector;
			for (int j = 0; j < 20; j++)
			{
				if (Collision::checkBoundingBox(&weakEnemies[i], &(*bulletsVector)[j]))
				{
					if (currentBullet[j].isAlive() && weakEnemies[i].isAlive())
					{
						currentBullet[j].setAlive(false);
						weakEnemies[i].setAlive(false);
						player.money = player.money + 4;
						player.score++;
					}
				}
			}
		}
		
	}
}

void WeakEnemyManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < weakEnemies.size(); i++)
	{
		if (weakEnemies[i].isAlive())
			window->draw(weakEnemies[i]);
	}
}
