#pragma once
#include <SFML/Graphics.hpp>
#include "Input.h"
#include "MySprite.h"
#include "GameState.h"
class HelpScreen
{
public:
	HelpScreen(sf::RenderWindow* hwnd, Input* input, GameState* gameState);
	~HelpScreen();

	void handleInput(float dt);
	void render();
protected:

	MySprite background;
	sf::Texture backgroundTexture;

	GameState* gameState;

	sf::RenderWindow* window;
	Input * input;
	void beginDraw();
	void endDraw();
};

