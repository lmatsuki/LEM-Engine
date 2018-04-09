#pragma once

#include <string>
#include <memory>
#include "IFramework.h"
#include "IDataContainer.h"

/*
	An abstract class implemented by file parsers.
*/
class IParserFramework : IFramework
{
public:
	IParserFramework();
	virtual ~IParserFramework();
	
	virtual const std::string & getFrameworkName() override;
	virtual std::shared_ptr<IDataContainer> loadFile(const std::string & filenameWithPath) = 0;
	virtual void saveFile(const std::string & filenameWithPath, std::shared_ptr<IDataContainer>) = 0;
};