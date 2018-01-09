#pragma once

#include <vector>
#include <iostream>
#include "Message.h"
#include "System.h"
#include "Framework.h"
#include "Console.h"
#include "GUI.h"
#include "Graphics.h"

class MessageBus : public std::enable_shared_from_this<MessageBus>
{
public:
	MessageBus();
	~MessageBus();

	void init();
	void pollMessages();
	void postMessage(Message message);

private:
	std::vector<Message> _messages;
	std::vector<std::unique_ptr<System>> _systems;			// References to systems
	std::vector<std::shared_ptr<Framework>> _frameworks;	// References to frameworks
	
};