#pragma once

#include <map>
#include "IFramework.h"
#include "MessageType.h"

class StringToMessageTypeConverter : IFramework
{
public:
	StringToMessageTypeConverter();
	~StringToMessageTypeConverter();

	virtual const std::string & getFrameworkName() override;
	const MessageType getMessageTypeByString(const std::string & messageType);

private:
	std::map<std::string, MessageType> _stringToMessageTypeMap;
};