#include "XMLFileParser.h"

XMLFileParser::XMLFileParser()
{
}


XMLFileParser::~XMLFileParser()
{
}

std::shared_ptr<IDataContainer> XMLFileParser::loadFile()
{
	return std::make_shared<IDataContainer>();
}

void XMLFileParser::saveFile(const std::string & filenameWithPath, std::shared_ptr<IDataContainer> data)
{

}
