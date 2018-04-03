#pragma once

#include "IFileParser.h"

class XMLFileParser : public IFileParser
{
public:
	XMLFileParser();
	virtual ~XMLFileParser();

	virtual std::shared_ptr<IDataContainer> loadFile() override;
	virtual void saveFile(const std::string & filenameWithPath, std::shared_ptr<IDataContainer> data) override;
};