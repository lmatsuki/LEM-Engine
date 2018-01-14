#include "Framework.h"

Framework::Framework(std::string frameworkName) : _frameworkName(frameworkName)
{
	std::cout << _frameworkName << " framework created." << std::endl;
}

Framework::~Framework()
{
	std::cout << _frameworkName << " framework deleted." << std::endl;
}
