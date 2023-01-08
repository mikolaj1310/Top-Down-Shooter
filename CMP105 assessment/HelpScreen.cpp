#include "HelpScreen.h"



HelpScreen::HelpScreen(sf::RenderWindow* hwnd, Input* in, GameState* currentState)
{
	window = hwnd;
	input = in;
	gameState = currentState;


	backgroundTexture.loadFromFile("gfx/HelpScreen.png");

	background.setTexture(&backgroundTexture);
	background.setSize(sf::Vector2f(800, 800));
	background.setPosition(0, 0);
}

HelpScreen::~HelpScreen()
{
}

void HelpScreen::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		//gameState->setCurrentState(State::LEVEL);
	}
}

void HelpScreen::render()
{
	beginDraw();

	window->draw(background);

	endDraw();
}

void HelpScreen::beginDraw()
{
	window->clear(sf::Color::Black);
}

void HelpScreen::endDraw()
{
	window->display();
}
