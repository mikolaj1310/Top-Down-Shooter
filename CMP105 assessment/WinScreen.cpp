#include "WinScreen.h"

WinScreen::WinScreen(sf::RenderWindow* hwnd, Input* in, GameState* currentState)
{
	window = hwnd;
	input = in;
	gameState = currentState;


	backgroundTexture.loadFromFile("gfx/WinScreen.png");

	background.setTexture(&backgroundTexture);
	background.setSize(sf::Vector2f(800, 800));
	background.setPosition(0, 0);
}


WinScreen::~WinScreen()
{
}

void WinScreen::update(float dt)
{

}

void WinScreen::handleInput(float dt)
{

}

void WinScreen::render()
{
	beginDraw();

	window->draw(background);

	endDraw();
}

void WinScreen::beginDraw()
{
	window->clear(sf::Color::Black);
}

void WinScreen::endDraw()
{
	window->display();
}