#pragma once

//enum direction : char { left = 'l', right = 'r' };

enum class State { MENU, HELP, LEVEL, PAUSE, WINSCREEN, LOOSESCREEN };

class GameState
{
public:
	//GameState();

	void setCurrentState(State s);
	State getCurrentState();

	enum GState { MENU, HELP, LEVEL, PAUSE, WINSCREEN, LOOSESCREEN
	};

protected:
	State currentState;
};