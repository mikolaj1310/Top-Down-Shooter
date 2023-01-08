#include "PauseState.h"

PauseState::PauseState(sf::RenderWindow* hwnd, Input* in, GameState* currentState)
{
	window = hwnd;
	input = in;
	gameState = currentState;

	
	backgroundTexture.loadFromFile("gfx/PauseBackground.png");

	background.setTexture(&backgroundTexture);
	background.setSize(sf::Vector2f(800, 800));
	background.setPosition(0, 0);
}


PauseState::~PauseState()
{
}

void PauseState::update(float dt)
{

}

void PauseState::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		gameState->setCurrentState(State::LEVEL);
	}
}

void PauseState::render()
{
	//beginDraw();

	window->draw(background);

	endDraw();
}

void PauseState::beginDraw()
{
	window->clear(sf::Color::Black);
}

void PauseState::endDraw()
{
	window->display();
}