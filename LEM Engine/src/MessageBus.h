#pragma once

#include <vector>
#include <iostream>
#include "Message.h"
#include "System.h"
#include "Console.h"

class MessageBus : public std::enable_shared_from_this<MessageBus>
{
public:
	MessageBus();
	~MessageBus();

	void init();
	void pollMessages();

private:
	std::vector<Message> _messages;
	std::vector<std::unique_ptr<System>> _systems;	// References to systems
	

	// References to frameworks
	
};