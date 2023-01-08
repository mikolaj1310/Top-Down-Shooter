#include "LooseScreen.h"

LooseScreen::LooseScreen(sf::RenderWindow* hwnd, Input* in, GameState* currentState)
{
	window = hwnd;
	input = in;
	gameState = currentState;


	backgroundTexture.loadFromFile("gfx/LooseScreen.png");

	background.setTexture(&backgroundTexture);
	background.setSize(sf::Vector2f(800, 800));
	background.setPosition(0, 0);
}


LooseScreen::~LooseScreen()
{
}

void LooseScreen::update(float dt)
{

}

void LooseScreen::handleInput(float dt)
{

}

void LooseScreen::render()
{
	beginDraw();

	window->draw(background);

	endDraw();
}

void LooseScreen::beginDraw()
{
	window->clear(sf::Color::Black);
}

void LooseScreen::endDraw()
{
	window->display();
}