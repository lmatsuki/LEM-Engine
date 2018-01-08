#pragma once

#include <iostream>
#include <memory>
#include <stack>
#include <SDL.h>

#include "Input.h"
#include "Graphics.h"
#include "AssetManager.h"

#include "MessageBus.h"

class GameState;

// Test classes
class Aircraft;
class Mothership
{
public:
	Mothership(std::string name) : name(name) { std::cout << "Mothership " << name << " created." << std::endl; };
	~Mothership() { std::cout << "Mothership " << name << " destroyed." << std::endl; }
	void setChild(std::unique_ptr<Aircraft> wingMan) { _wingMan = std::move(wingMan); }

private:
	std::string name;
	std::unique_ptr<Aircraft> _wingMan;
};

class Aircraft
{
public:
	Aircraft(std::string name) : name(name) { std::cout << "Aircraft " << name << " created." << std::endl; };
	~Aircraft() { std::cout << "Aircraft " << name << " destroyed." << std::endl; }
	void setParent(std::shared_ptr<Mothership> wingMan) { _wingMan = wingMan; }

private:
	std::string name;
	std::weak_ptr<Mothership> _wingMan;
};

class Game
{
public:
	Game();
	~Game();

	// Initialize SDL
	int init();
	void shutdown();

	bool isRunning();
	void run();

	void test();

	// GameState methods
	void pushState(std::unique_ptr<GameState> state);
	void popState();
	void changeState(std::unique_ptr<GameState> state);
	GameState* peekState();

	/********* Engine calls *********/
	// Graphics Engine
	bool loadImage(const std::string path);
	bool loadText(const std::string inputText);

	// Input Engine
	bool finishedInput();
	bool inputEnabled();
	bool inputChanged();
	void setInputChanged(const bool changed);
	std::string getInputText();

	// engine parts
	Input _inputEngine;
	Graphics _graphicsEngine;
	AssetManager _assetManagerEngine;

private:
	// Properties
	bool _running;
	std::shared_ptr<MessageBus> _messageBus;

	std::stack<std::unique_ptr<GameState>> _states;
};