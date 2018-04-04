#pragma once

#include <string>
#include <memory>
#include "IDataContainer.h"

/*
	An abstract class implemented by file parsers.
*/
class IParserFramework
{
public:
	IParserFramework();
	virtual ~IParserFramework();
	
	virtual std::shared_ptr<IDataContainer> loadFile() = 0; // TODO: Return an object containing the parsed data
	virtual void saveFile(const std::string & filenameWithPath, std::shared_ptr<IDataContainer>) = 0; // TODO: Take in the data to save as second argument
};