#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "rapidxml.hpp"
#include "IParserFramework.h"

class XMLParserFramework : public IParserFramework
{
public:
	XMLParserFramework();
	virtual ~XMLParserFramework();

	virtual std::shared_ptr<IDataContainer> loadFile() override;
	virtual void saveFile(const std::string & filenameWithPath, std::shared_ptr<IDataContainer> data) override;
};