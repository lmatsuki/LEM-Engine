#include "XMLParserFramework.h"

XMLParserFramework::XMLParserFramework()
{
	
}


XMLParserFramework::~XMLParserFramework()
{
	
}

std::shared_ptr<IDataContainer> XMLParserFramework::loadFile(const std::string & filenameWithPath)
{
	// Read the file as a string
	char saveData[200];
	std::string filepath = filenameWithPath;
	std::ifstream ifStream(filepath);
	std::string content((std::istreambuf_iterator<char>(ifStream)),
		(std::istreambuf_iterator<char>()));

	rapidxml::xml_document<> document;
	document.parse<0>(&content[0]);

	// Walk through the DOM tree
	std::cout << "Name of my first node is: " << document.first_node()->name() << "\n";
	rapidxml::xml_node<> *node = document.first_node("Scenes");
	for (rapidxml::xml_node<> *sceneNode = node->first_node(); sceneNode; sceneNode = sceneNode->next_sibling())
	{
		std::cout << "Scene name: " << sceneNode->first_attribute()->value() << "\n";
		
		for (rapidxml::xml_node<> *mapNode = sceneNode->first_node(); mapNode; mapNode = mapNode->next_sibling())
		{
			std::cout << "Mapping: " << mapNode->first_attribute()->value() << " - " 
				<< mapNode->first_attribute()->next_attribute()->value() << "\n";
		}
	}

	return std::make_shared<IDataContainer>();
}

void XMLParserFramework::saveFile(const std::string & filenameWithPath, std::shared_ptr<IDataContainer> data)
{

}
