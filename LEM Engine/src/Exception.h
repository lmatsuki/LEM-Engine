#pragma once

#include <string>

struct Exception
{
	Exception(const std::string& errorMessage)
	{
		this->id = 0;
		this->errorMessage = errorMessage;
	};

	Exception(const int id, const std::string& errorMessage)
	{
		this->id = id;
		this->errorMessage = errorMessage;
	};

	int id;
	std::string errorMessage;
};