#pragma once

#include <SDL.h>
#include <iostream>

class Input
{
public:
	Input();
	~Input();

	void update();
	bool exitScene();

private:
	bool _pendingExit;
};