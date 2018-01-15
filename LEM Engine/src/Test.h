#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include "Game.h"

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

struct Base
{
	Base() 
	{ 
		std::cout << "Base created.\n";
		_id = 0;
	}
	virtual ~Base() { std::cout << "Base destroyed.\n"; };
	virtual void Call() { std::cout << "It'sa me Base!\n"; }

	int _id;
};

struct Derived : public Base
{
	Derived() 
	{ 
		std::cout << "Derived created.\n"; 
		_id = 1;
		_did = 2;
	}
	~Derived() { std::cout << "Derived destroyed.\n"; }
	void Call() { std::cout << "It'sa me Derived!\n"; }
	void DerivedOnlyCall() { std::cout << "ID: " << _id << " / DID: " << _did << " - I can only be derived.\n"; }

	int _did;
};

class Test
{
public:
	void runTests()
	{
		//std::shared_ptr<Mothership> pMothership = std::make_shared<Mothership>("Mothership");
		//std::unique_ptr<Aircraft> pAircraft = std::make_unique<Aircraft>("Aircraft");
		//std::unique_ptr<Aircraft> pAircraft2 = std::make_unique<Aircraft>("Aircraft2");
		//std::unique_ptr<Aircraft> pAircraft3 = std::make_unique<Aircraft>("Aircraft3");

		//pAircraft->setParent(pMothership);
		//pAircraft2->setParent(pMothership);
		//pAircraft3->setParent(pMothership);
		//pMothership->setChild(std::move(pAircraft));
		//pMothership->setChild(std::move(pAircraft2));
		//pMothership->setChild(std::move(pAircraft3));

		runOwnershipTests();
	}

	void runOwnershipTests()
	{
		std::unique_ptr<Derived> originalMessage = std::make_unique<Derived>();		
		std::vector<std::unique_ptr<Base>> messageVector; 
		messageVector.push_back(std::move(originalMessage));

		//std::unique_ptr<Derived>(static_cast<Derived*>(messageVector[0].release()))->DerivedOnlyCall();
		//static_cast_ptr<Derived>(messageVector[0])->DerivedOnlyCall();
		//std::unique_ptr<Derived> derived = std::unique_ptr<Derived>(static_cast<Derived*>(baseMessage.release()));
		//derived.get()->Call();
		//derived.get()->DerivedOnlyCall();
	}

	void runGame()
	{
		std::shared_ptr<Game> game = std::make_shared<Game>();
		if (game.get()->init())
			game.get()->run();
	}
};