#pragma once

#include <vector>
#include <iostream>
#include "Message.h"
#include "Graphics.h"
#include "Console.h"
#include "Render.h"
#include "GUI.h"

class Game;

class MessageBus : public std::enable_shared_from_this<MessageBus>
{
public:
	MessageBus(std::shared_ptr<Game> game);
	~MessageBus();

	bool init();
	void pollMessages();
	void postMessage(std::unique_ptr<Message> message);

	// Add a system and system name by string.
	template <typename T>
	void addSystem(std::string systemName);

	// Add a system and system name by string, and a required framework.
	template <typename T, typename T2>	
	void addSystem(std::string systemName, std::shared_ptr<T2> framework);

	// Runs the update function for every system.
	void updateSystems();

private:
	std::weak_ptr<Game> _game;							// Reference to Game Logic
	std::vector<std::unique_ptr<Message>> _messages;
	std::vector<std::unique_ptr<System>> _systems;		// References to systems	
};