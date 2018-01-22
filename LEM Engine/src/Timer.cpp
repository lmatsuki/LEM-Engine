#include "Timer.h"

Timer::Timer(std::string frameworkName) : Framework(frameworkName)
{
	_clock = std::clock();
}

Timer::~Timer()
{
}

int Timer::getTimeInSeconds()
{	
	return _clock / CLOCKS_PER_SEC;
}

int Timer::getTimeInMilliSeconds()
{
	return _clock;
}

void Timer::printTime()
{
	std::cout << "Time: " << _clock / CLOCKS_PER_SEC << std::endl;
}

void Timer::update()
{
	_clock = std::clock();
}