#include "Input.h"

Input::Input() : _pendingExit(false), _inputText(""), _displayInputText(false)
{

}

Input::~Input()
{
	
}

void Input::update()
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		// User requests quit
		if (e.type == SDL_QUIT)
		{
			_pendingExit = true;
		}
		else if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_q:
				_pendingExit = true;
				break;
			case SDLK_RETURN:
				// Disable text input
				SDL_StopTextInput();
				break;
			case SDLK_BACKSPACE:
				// Lop off character
				if (_inputText.length() > 0)
					_inputText.pop_back();
				break;
			}
		}
		else if (e.type == SDL_TEXTINPUT)
		{
			std::cout << "Entered: " << e.text.text << std::endl;
			_inputText += e.text.text;
		}
		else if (e.type == SDL_MOUSEBUTTONUP)
		{
			if (e.button.button == SDL_BUTTON_LEFT)
			{
				// Enable text input
				SDL_StartTextInput();
			}
		}
	}
}

bool Input::exitScene()
{
	return _pendingExit;
}

std::string Input::getInputText()
{
	return _inputText;
}

void Input::toggleInputState(const bool toggle)
{
	if (toggle)
		SDL_StartTextInput();
	else
		SDL_StopTextInput();
}

void Input::clearInputText()
{
	_inputText = "";
}

void Input::toggleDisplayInputText(const bool toggle)
{
	_displayInputText = toggle;
}

bool Input::getInputTextEnabled()
{
	return _displayInputText;
}
