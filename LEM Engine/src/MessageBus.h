#pragma once

#include <vector>
#include <iostream>
#include "Message.h"
#include "System.h"
#include "Console.h"
#include "GUI.h"
#include "Graphics.h"

class MessageBus : public std::enable_shared_from_this<MessageBus>
{
public:
	MessageBus();
	~MessageBus();

	bool init();
	void pollMessages();
	void postMessage(std::unique_ptr<Message> message);
	// Runs the update function for every system.
	void updateSystems();

private:
	std::vector<std::unique_ptr<Message>> _messages;
	std::vector<std::unique_ptr<System>> _systems;			// References to systems
	//std::vector<std::shared_ptr<Framework>> _frameworks;	// References to frameworks
	
};