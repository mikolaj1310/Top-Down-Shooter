#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Input.h"
#include "MySprite.h"
#include "GameState.h"
class Menu
{
public:
	Menu(sf::RenderWindow* hwnd, Input* input, GameState* gameState);
	~Menu();

	void handleInput(float dt);
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

