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
	std::string getInputText();

private:
	bool _pendingExit;
	std::string _inputText;
};