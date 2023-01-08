#pragma once
class Input
{
private:
	//Structure to represent mouse
	struct Mouse
	{
		int x, y;
		bool left;
	};

public:
	void setKeyDown(int key);
	void setKeyUp(int key);
	bool isKeyDown(int key);

	void setMouseX(int lx);
	void setMouseY(int ly);
	void setMousePosition(int lx, int ly);
	int getMouseX();
	int getMouseY();
	void setMouseLeftDown(bool down);
	bool isMouseLeftDown();
	//void setInput(int in);

private:

	bool keys[256]{ false };
	Mouse mouse;
};