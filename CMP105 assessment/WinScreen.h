#pragma once
#include <SFML/Graphics.hpp>
#include "Input.h"
#include "MySprite.h"
#include "GameState.h"
class WinScreen
{
public:
	WinScreen(sf::RenderWindow* hwnd, Input* input, GameState* gameState);
	~WinScreen();

	void handleInput(float dt);
	void update(float dt);
	void render();
private:

	MySprite background;
	sf::Texture backgroundTexture;

	GameState* gameState;

	sf::RenderWindow* window;
	Input * input;
	void beginDraw();
	void endDraw();
};