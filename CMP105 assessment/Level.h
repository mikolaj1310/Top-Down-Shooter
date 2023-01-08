#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Input.h"
#include "MySprite.h"
#include "Player.h"
#include "Collision.h"
#include "WeakEnemyManager.h"
#include "BulletManager.h"
#include "AmmoPickup.h"
#include "GameState.h"
#include "Coin.h"
#include "HealthSprite.h"
#include "AudioManager.h"
class Level
{
public:
	Level(sf::RenderWindow* hwnd, Input* input, GameState* gamestate);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();
private:
	GameState * gameState;
	sf::RectangleShape rect;
	sf::RenderWindow* window;
	bool hasStarted = false;
	AudioManager audioManager;

	MySprite ammoPickup;
	sf::Texture ammoPickupTexture;

	HealthSprite healthSprite;
	sf::Texture healthSpriteTexture;

	Player player;
	sf::Texture playerTexture;

	Coin coin;
	sf::Texture coinTexture;

	BulletManager bulletManager;
	WeakEnemyManager weakEnemyManager;
	
	MySprite background;
	sf::Texture backgroundTexture;

	MySprite ammoIcon;
	sf::Texture ammoIconTexture;

	MySprite ground;
	sf::Texture groundTexture;

	MySprite heartIcon;
	sf::Texture heartIconTexture;

	sf::Clock spawnTimer;
	sf::Time time;
		
	sf::Text moneyText;
	sf::Text ammoText;
	sf::Text text;
	sf::Font font;
	Input* input;
	void beginDraw();
	void endDraw();

	sf::Vector2f playerPos;
	sf::Vector2f enemyPos;
};