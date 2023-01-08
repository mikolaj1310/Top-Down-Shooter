#include "BulletManager.h"

BulletManager::BulletManager()
{
	//counter = 0;
	texture.loadFromFile("gfx/Bullet.png");

	for (int i = 0; i < 20; i++)
	{
		bullets.push_back(Bullet());
		bullets[i].setAlive(false);
		bullets[i].setTexture(&texture);
		bullets[i].setSize(sf::Vector2f(14, 46));
		bullets[i].setOrigin(7, 23);
		bullets[i].setCollisionBox(sf::FloatRect(0, 0, 7, 23));
	}
}

BulletManager::~BulletManager()
{
}

void BulletManager::update(float dt)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			bullets[i].update(dt, rotation[i]);
		}
	}
	deathCheck();
}

void BulletManager::spawn(sf::Vector2f spawnPosition, Input* input)
{	
	for (int i = 0; i < bullets.size() - 1; i++)
	{		
		if (!bullets[i].isAlive())
		{
			double Pi = 3.14159265;
			float directionX = spawnPosition.x - input->getMouseX();
			float directionY = spawnPosition.y - input->getMouseY();
			rotation[i] = (atan2(directionY, directionX)) * 180 / Pi;
			bullets[i].setAlive(true);
			bullets[i].setPosition(spawnPosition);
			bullets[i].setRotation(rotation[i] - 90);
			//found = true;
			return;
		}
		
	}
	/*
	if (!bullets[counter].isAlive())
	{
		double Pi = 3.14159265;
		float directionX = spawnPosition.x - input->getMouseX();
		float directionY = spawnPosition.y - input->getMouseY();
		rotation[counter] = (atan2(directionY, directionX)) * 180 / Pi;
		bullets[counter].setAlive(true);
		bullets[counter].setPosition(spawnPosition);
		bullets[counter].setRotation(rotation[counter] - 90);
		return;
	}
	if (counter >= bullets.size() -1)
		counter = 0;
	else
		counter++;*/
	
}

void BulletManager::deathCheck()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{

			if (bullets[i].getPosition().x < -100)
			{
				bullets[i].setAlive(false);
			}
			if (bullets[i].getPosition().x > 900)
			{
				bullets[i].setAlive(false);
			}
			if (bullets[i].getPosition().y < -100)
			{
				bullets[i].setAlive(false);
			}
			if (bullets[i].getPosition().y > 900)
			{
				bullets[i].setAlive(false);
			}
			/*
			if (Collision::checkBoundingBox(&player, &bullets[i]))
			{
				player.collisionResponse(&weakEnemies[i]);
				weakEnemies[i].setAlive(false);
			}*/
		}
	}
}

void BulletManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			window->draw(bullets[i]);
		}
	}
}
