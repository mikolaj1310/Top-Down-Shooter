#include "Menu.h"

Menu::Menu(sf::RenderWindow* hwnd, Input* in, GameState* currentState)
{
	window = hwnd;
	input = in;
	gameState = currentState;


	backgroundTexture.loadFromFile("gfx/MainMenu.png");
	
	background.setTexture(&backgroundTexture);
	background.setSize(sf::Vector2f(800, 800));
	background.setPosition(0, 0);
}


Menu::~Menu()
{
}

void Menu::handleInput(float dt)
{
	if (input->isMouseLeftDown())
	{
		gameState->setCurrentState(State::LEVEL);
	}
}

void Menu::render()
{
	beginDraw();

	window->draw(background);

	endDraw();
}

void Menu::beginDraw()
{
	window->clear(sf::Color::Black);
}

void Menu::endDraw()
{
	window->display();
}