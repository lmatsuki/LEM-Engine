#pragma once

#include "ISystem.h"
#include "InputFramework.h"
#include "XMLParserFramework.h"
#include "StringToMessageTypeConverter.h"

class InputSystem : public ISystem
{
public:
	InputSystem(std::shared_ptr<MessageBus> messageBus, std::shared_ptr<InputFramework> inputFramework, 
		std::shared_ptr<IParserFramework> parserFramework, std::shared_ptr<StringToMessageTypeConverter> stringToMessageTypeConverter);
	~InputSystem();

	void loadInputMaps();

	virtual const std::string getSystemName() override;
	void handleMessages(const std::shared_ptr<Message> & message) override;
	void update() override;

private:
	std::shared_ptr<InputFramework> _inputFramework;
	std::shared_ptr<IParserFramework> _parserFramework;
	std::shared_ptr<StringToMessageTypeConverter> _stringToMessageTypeConverter;
	std::map<Uint32, std::map<SDL_Keycode, MessageType>> _eventToMessageTypeMap;
};