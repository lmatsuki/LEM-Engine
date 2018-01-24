#include "ClockLib.h"

#include <ctime>

int Clock::getTimeInSeconds()
{
	return std::clock() / CLOCKS_PER_SEC;
}
int Clock::getTimeInMilliSeconds()
{
	return std::clock();
}