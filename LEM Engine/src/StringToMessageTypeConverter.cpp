#include "StringToMessageTypeConverter.h"

StringToMessageTypeConverter::StringToMessageTypeConverter()
{
	// Initialize the conversions here
	_stringToMessageTypeMap =
	{
		{ "QuitGame", MessageType::QuitGame }
	};
}

StringToMessageTypeConverter::~StringToMessageTypeConverter()
{

}

const std::string & StringToMessageTypeConverter::getFrameworkName()
{
	return "StringToMessageTypeConverter";
}

const MessageType StringToMessageTypeConverter::getMessageTypeByString(const std::string & messageType)
{
	std::map<std::string, MessageType>::const_iterator iter = _stringToMessageTypeMap.find(messageType);

	if (iter != _stringToMessageTypeMap.end())
	{
		return iter->second;
	}
	else
	{
		return MessageType::InvalidMessage;
	}
}