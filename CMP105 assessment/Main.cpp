#include "Level.h"
#include "Menu.h"
#include "LooseScreen.h"
#include "Input.h"
#include "GameState.h"
#include "Main.h"
#include "PauseState.h"
#include "WinScreen.h"
#include "HelpScreen.h"

void main()
{
	// Create window
	sf::RenderWindow window(sf::VideoMode(800, 800), "A Top Down Shooter");
	// Initialise level object
	Input input;	
	GameState gameState;

	Level level(&window, &input, &gameState);
	Menu menu(&window, &input, &gameState);
	HelpScreen helpScreen(&window, &input, &gameState);
	PauseState pauseState(&window, &input, &gameState);
	LooseScreen looseScreen(&window, &input, &gameState);
	WinScreen winScreen(&window, &input, &gameState);
	

	//Delta time
	sf::Clock clock;
	float deltaTime;

	gameState.setCurrentState(State::MENU);

	// Game loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				window.setView(sf::View(sf::FloatRect(0.f, 0.f,
					(float)event.size.width, (float)event.size.height)));
				break;
			case sf::Event::KeyPressed:
				// update input class
				input.setKeyDown(event.key.code);
				break;
			case sf::Event::KeyReleased:
				//update input class
				input.setKeyUp(event.key.code);
				break;
			case sf::Event::MouseMoved:
				//update input class
				input.setMousePosition(event.mouseMove.x,
					event.mouseMove.y);
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					//update input class
					input.setMouseLeftDown(true);
				}
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					//update input class
					input.setMouseLeftDown(false);
				}
				break;
			default:
				// don't handle other events
				break;
			}
		}
		// Level
		deltaTime = clock.restart().asSeconds();

		

		switch (gameState.getCurrentState())
		{
		case (State::MENU):
			menu.handleInput(deltaTime);
			menu.render();
			break;
		case(State::HELP):
			helpScreen.handleInput(deltaTime);
			helpScreen.render();
		case(State::LEVEL):
			level.handleInput(deltaTime);
			level.update(deltaTime);
			level.render();
			break;
		case(State::PAUSE):
			pauseState.handleInput(deltaTime);
			pauseState.update(deltaTime);
			pauseState.render();
		case(State::WINSCREEN):
			winScreen.handleInput(deltaTime);
			winScreen.update(deltaTime);
			winScreen.render();
		case(State::LOOSESCREEN):
			looseScreen.handleInput(deltaTime);
			looseScreen.update(deltaTime);
			looseScreen.render();
		}
	}
}