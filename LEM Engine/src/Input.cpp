#include "Input.h"

Input::Input() : _pendingExit(false)
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
		else if (e.type == SDL_KEYUP)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_q:
				_pendingExit = true;
			}
		}
	}
}

bool Input::exitScene()
{
	return _pendingExit;
}