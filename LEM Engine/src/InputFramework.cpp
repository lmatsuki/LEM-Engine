#include "InputFramework.h"

InputFramework::InputFramework() : _pendingExit(false), _inputText(""), _displayInputText(false), _inputFinished(false),
	_inputChanged(false)
{

}

InputFramework::~InputFramework()
{
	
}

const std::string & InputFramework::getFrameworkName()
{
	return "Input";
}












void InputFramework::update()
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

bool InputFramework::exitScene()
{
	return _pendingExit;
}

std::string InputFramework::getInputText()
{
	return _inputText;
}

void InputFramework::toggleInputState(const bool toggle)
{
	if (toggle)
		SDL_StartTextInput();
	else
		SDL_StopTextInput();
}

void InputFramework::clearInputText()
{
	_inputText = "";
}

void InputFramework::toggleDisplayInputText(const bool toggle)
{
	_displayInputText = toggle;
}

bool InputFramework::getDisplayInputText()
{
	return _displayInputText;
}

void InputFramework::setInputFinished(const bool finished)
{
	_inputFinished = finished;
}

bool InputFramework::getInputFinished()
{
	return _inputFinished;
}

bool InputFramework::getInputChanged()
{
	return _inputChanged;
}

void InputFramework::setInputChanged(const bool changed)
{
	_inputChanged = changed;
}
