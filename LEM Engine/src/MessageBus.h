#pragma once

#include <vector>
#include <iostream>
#include "UtilityLib.h"
#include "Message.h"
#include "InputSystem.h"
#include "ConsoleSystem.h"
#include "RenderSystem.h"
#include "GUISystem.h"
#include "TimedEventSystem.h"
#include "SceneSystem.h"

class Game;

class MessageBus : public std::enable_shared_from_this<MessageBus>
{
public:
	MessageBus(std::shared_ptr<Game> game);
	~MessageBus();

	bool init();
	void pollMessages();
	void postMessage(const std::shared_ptr<Message> & message);

	// Add a framework.
	template <typename T>
	std::shared_ptr<T> addFramework();

	// Add a system.
	template <typename T>
	void addSystem();

	// Add a system and a required framework.
	template <typename T, typename T2>	
	void addSystem(std::shared_ptr<T2> & framework);

	// Add a system and two required frameworks.
	template <typename T, typename T2, typename T3>
	void addSystem(std::shared_ptr<T2> & firstFramework, std::shared_ptr<T3> & secondFramework);

	// Runs the update function for every system.
	void updateSystems();

private:
	std::weak_ptr<Game> _game;							// Reference to Game Logic
	std::vector<std::shared_ptr<Message>> _messages;	// References to queued messages
	std::vector<std::unique_ptr<ISystem>> _systems;		// References to systems	
};