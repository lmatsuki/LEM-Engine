#pragma once

#include <ctime>
#include <SDL.h>
#include <iostream>
#include "Framework.h"

class Timer : public Framework
{
public:
	Timer(std::string frameworkName);
	~Timer();

	int getTimeInSeconds();
	int getTimeInMilliSeconds();

	void printTime();
	void update();

private:
	std::clock_t _clock;
};