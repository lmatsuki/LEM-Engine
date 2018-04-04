#include "XMLParserFramework.h"

XMLParserFramework::XMLParserFramework()
{
	
}


XMLParserFramework::~XMLParserFramework()
{
	
}

std::shared_ptr<IDataContainer> XMLParserFramework::loadFile()
{
	// Read the file as a string
	char saveData[200];
	std::string filepath = "Assets/Data/Scenes.xml";
	std::ifstream ifs(filepath);
	std::string content((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));

	rapidxml::xml_document<> document;
	document.parse<0>(&content[0]);

	// Walk through the DOM tree
	std::cout << "Name of my first node is: " << document.first_node()->name() << "\n";
	rapidxml::xml_node<> *node = document.first_node("Scenes");
	//std::cout << "Node foobar has value " << node->value() << "\n";
	/*for (rapidxml::xml_attribute<> *attr = node->first_attribute(); attr; attr = attr->next_attribute())*/
	for (rapidxml::xml_node<> *subnode = node->first_node(); subnode; subnode = subnode->next_sibling())
	{
		std::cout << "Node foobar has attribute " << subnode->name() << " ";
		std::cout << "with value " << subnode->first_node()->value() << "\n";
	}

	return std::make_shared<IDataContainer>();
}

void XMLParserFramework::saveFile(const std::string & filenameWithPath, std::shared_ptr<IDataContainer> data)
{

}
