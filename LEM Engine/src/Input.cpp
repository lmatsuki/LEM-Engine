#include "Input.h"

Input::Input() : _pendingExit(false), _inputText(""), _displayInputText(false), _inputFinished(false),
	_inputChanged(false)
{

}

Input::~Input()
{
	
}

const std::string & Input::getFrameworkName()
{
	return "Input";
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
			if (e.key.keysym.sym == SDLK_ESCAPE)
			{
				_pendingExit = true;
			}
			else if (e.key.keysym.sym == SDLK_RETURN)
			{
				// Disable text input
				SDL_StopTextInput();
				_inputFinished = true;
				_inputChanged = false;
			}
			else if (e.key.keysym.sym == SDLK_BACKSPACE && _inputText.length() > 0)
			{
				// Lop off character
				_inputText.pop_back();
				_inputChanged = true;
				std::cout << "Path: " << _inputText.c_str() << std::endl;
			}
			else if (e.key.keysym.sym == SDLK_i && SDL_GetModState() & KMOD_CTRL)
			{
				if (!SDL_IsTextInputActive())
				{
					clearInputText();
					SDL_StartTextInput();
					_inputChanged = true;
					std::cout << "Enter path:" << std::endl;
				}
			}

			//switch (e.key.keysym.sym)
			//{
			//case SDLK_q:
			//	_pendingExit = true;
			//	break;
			//case SDLK_RETURN:
			//	// Disable text input
			//	SDL_StopTextInput();
			//	_inputFinished = true;
			//	break;
			//case SDLK_BACKSPACE:
			//	// Lop off character
			//	if (_inputText.length() > 0)
			//		_inputText.pop_back();
			//	break;
			//case SDLK_c:
			//	if (SDL_GetModState() & KMOD_CTRL)
			//	{
			//		if (!SDL_IsTextInputActive)
			//		{
			//			clearInputText();
			//			SDL_StartTextInput();
			//			std::cout << "Enter path:" << std::endl;
			//		}
			//	}
			//	break;
			//}
		}
		else if (e.type == SDL_TEXTINPUT)
		{
			std::cout << "Entered: " << e.text.text << std::endl;
			_inputText += e.text.text;
			std::cout << "Path: " << _inputText.c_str() << std::endl;
			_inputChanged = true;
		}
		else if (e.type == SDL_MOUSEBUTTONUP)
		{
			if (e.button.button == SDL_BUTTON_LEFT)
			{
				// Enable text input
				//SDL_StartTextInput();
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

bool Input::getDisplayInputText()
{
	return _displayInputText;
}

void Input::setInputFinished(const bool finished)
{
	_inputFinished = finished;
}

bool Input::getInputFinished()
{
	return _inputFinished;
}

bool Input::getInputChanged()
{
	return _inputChanged;
}

void Input::setInputChanged(const bool changed)
{
	_inputChanged = changed;
}
