#include "Level.h"
#include <string>

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* theStateofTheGame)
{

	weakEnemyManager.setBulletManager(&bulletManager);
	weakEnemyManager.setBulletVector();

	window = hwnd;
	input = in;
	gameState = theStateofTheGame;
	input->setMouseLeftDown(false);

	audioManager.addMusic("sfx/BackgroundMusic.ogg", "background");
	audioManager.addSound("sfx/Gunshot.ogg", "gunshot");

	
		
	font.loadFromFile("font/arial.ttf");

	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(350, 5);
	
	ammoText.setFont(font);
	ammoText.setCharacterSize(32);
	ammoText.setFillColor(sf::Color::White);
	ammoText.setPosition(50, 47);

	moneyText.setFont(font);
	moneyText.setCharacterSize(32);
	moneyText.setFillColor(sf::Color::White);
	moneyText.setPosition(50, 98);
	
	backgroundTexture.loadFromFile("gfx/Background.png");
	playerTexture.loadFromFile("gfx/Player.png");
	ammoPickupTexture.loadFromFile("gfx/AmmoPickup.png");
	coinTexture.loadFromFile("gfx/Coin.png");
	ammoIconTexture.loadFromFile("gfx/AmmoIcon.png");
	healthSpriteTexture.loadFromFile("gfx/HealthBar.png");
	heartIconTexture.loadFromFile("gfx/HeartIcon.png");

	background.setTexture(&backgroundTexture);
	background.setSize(sf::Vector2f(800, 800));
	background.setPosition(0, 0);
	
	player.setTexture(&playerTexture);
	player.setSize(sf::Vector2f(120, 68));
	player.setCollisionBox(sf::FloatRect((120 / 2) -50, (120 / 2) - 50, 50, 50));
	player.setPosition(400, 400);
	player.setOrigin(120 / 2 - 9, 68 / 2);

	healthSprite.setTexture(&healthSpriteTexture);
	healthSprite.setSize(sf::Vector2f(296 / 1.5, 56 / 1.5));
	healthSprite.setPosition(47, 5);

	heartIcon.setTexture(&heartIconTexture);
	heartIcon.setSize(sf::Vector2f(37, 37));
	heartIcon.setPosition(5, 5);

	ammoPickup.setTexture(&ammoPickupTexture);
	ammoPickup.setSize(sf::Vector2f(314 /2.5, 180 /2.5));
	ammoPickup.setPosition(40, 800 - 124);
	ammoPickup.setCollisionBox(sf::FloatRect(0, 0, 314 / 2.5, 180 / 2.5));

	ammoIcon.setTexture(&ammoIconTexture);
	ammoIcon.setSize(sf::Vector2f(83 / 2.2, 91 / 2.2));
	ammoIcon.setPosition(5, 47);

	coin.setTexture(&coinTexture);
	coin.setSize(sf::Vector2f(40, 40));
	coin.setPosition(5, 98);	
}
Level::~Level()
{

}

void Level::update(float dt)
{
	if (!hasStarted)
	{
		audioManager.playMusicbyName("background");
		hasStarted = true;
	}
	playerPos.x = player.getPosition().x;
	playerPos.y = player.getPosition().y;
	

	double Pi = 3.14159265;

	float directionX = player.getPosition().x - input->getMouseX();
	float directionY = player.getPosition().y - input->getMouseY();
	float rotation = (atan2(directionY, directionX)) * 180 / Pi;
	player.setRotation(rotation + 180);

	healthSprite.update(dt, player);
	coin.update(dt);
	bulletManager.update(dt);
	
	weakEnemyManager.update(dt, playerPos, player);
	weakEnemyManager.spawn();
	

	time = spawnTimer.getElapsedTime();

	if (player.ammo == 0)
		ammoText.setFillColor(sf::Color::Red);
	else
		ammoText.setFillColor(sf::Color::White);
	ammoText.setString(std::to_string((int)player.ammo));
	moneyText.setString(std::to_string((int)player.money));
	text.setString("Score: " + std::to_string((int)player.score));
	if (player.score >= 100)
		gameState->setCurrentState(State::WINSCREEN);

	if (player.health == 0)
		gameState->setCurrentState(State::LOOSESCREEN);

	
}
void Level::handleInput(float dt)
{
	
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		gameState->setCurrentState(State::PAUSE);
	}
	if (input->isKeyDown(sf::Keyboard::F))
	{
		if (player.money >= 20)
		{
			if (Collision::checkBoundingBox(&player, &ammoPickup))
			{
				player.collisionResponse(&ammoPickup);
				player.setAmmo(player.getAmmo() + 7);
				player.money = player.money - 20;
			}
			input->setKeyUp(sf::Keyboard::F);
		}

		
	}
	
	if (input->isMouseLeftDown())
	{
		if (time.asMilliseconds() > 230)
		{
			audioManager.playSoundbyName("gunshot");
			if (player.ammo > 0)
			{		
				spawnTimer.restart();

				player.setAmmo(player.getAmmo() - 1);
				bulletManager.spawn(playerPos, input);
			}
		}
	}
	
	player.update(dt, input);

}
void Level::render()
{
	beginDraw();

	window->draw(background);
	window->draw(ammoPickup);
	window->draw(heartIcon);
	window->draw(healthSprite);
	window->draw(coin);
	window->draw(ammoIcon);
	bulletManager.render(window);
	window->draw(player);
	weakEnemyManager.render(window);
	
	window->draw(text);	
	window->draw(ammoText);
	window->draw(moneyText);
	

	endDraw();
}
void Level::beginDraw()
{
	window->clear(sf::Color::Black);
}
void Level::endDraw()
{
	window->display();
}