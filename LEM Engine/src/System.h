#pragma once

#include <iostream>
#include <memory>
#include "Message.h"
#include "StringMessage.h"
#include "Exception.h"

class MessageBus;

class System
{
public:
	System(std::shared_ptr<MessageBus> messageBus, std::string systemName);
	virtual ~System();

	virtual void handleMessages(std::unique_ptr<Message> & message) = 0;
	virtual void update() = 0;

private:
	std::weak_ptr<MessageBus> _messageBus;
	std::string _systemName;
};

// Useful template functions for the project
template<typename D, typename B>
std::unique_ptr<D> static_cast_ptr(std::unique_ptr<B>& base)
{
	std::unique_ptr<D> castPtr = std::unique_ptr<D>(static_cast<D*>(base.release()));
	return castPtr;
}