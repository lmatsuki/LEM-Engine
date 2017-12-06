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
	void toggleInputState(const bool toggle = false);
	void clearInputText();

	void toggleDisplayInputText(const bool toggle = false);
	bool getInputTextEnabled();

private:
	bool _pendingExit;
	std::string _inputText;
	bool _displayInputText;
};