#pragma once

#include <string>

/*
	An abstract class implemented by file parsers.
*/
class IFileParser
{
public:
	IFileParser();
	virtual ~IFileParser();

	//template <typename T>
	//virtual T loadFile() = 0; // TODO: Return an object containing the parsed data

	//template <typename T>
	//virtual static void saveFile(const std::string & filenameWithPath, T & data) = 0; // TODO: Take in the data to save as second argument
};