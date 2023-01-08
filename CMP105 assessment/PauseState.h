#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameState.h"
#include "Input.h"
#include "MySprite.h"
class PauseState
{
public:
	PauseState(sf::RenderWindow* hwnd, Input* input, GameState* gameState);
	~PauseState();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:

	GameState * gameState;

	MySprite background;
	sf::Texture backgroundTexture;

	sf::RenderWindow* window;
	Input * input;
	void beginDraw();
	void endDraw();
};

