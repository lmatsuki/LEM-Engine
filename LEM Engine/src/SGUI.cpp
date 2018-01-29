#include "SGUI.h"

SGUI::SGUI(std::shared_ptr<MessageBus> messageBus, std::shared_ptr<FGraphics> graphicsFramework)
	: _graphicsFramework(graphicsFramework), ISystem(messageBus)
{
	//Exception e("Some SGUI initializiation error.");
	//throw (e);

	// Initialize frameworks

}

SGUI::~SGUI()
{
	std::cout << "SGUI is finally shutdown." << std::endl;
}

const std::string SGUI::getSystemName()
{
	return "SGUI";
}

void SGUI::handleMessages(const std::shared_ptr<Message> & message)
{
	switch (message->type)
	{
/*		case MessageType::LoadBackground:	
		{
			std::string filePath = ((StringMessage*)message.get())->dataString;
			_graphicsFramework.get()->loadImage(filePath);
			break;
		}*/		
	}
}

void SGUI::update()
{
	// Render System already calls render to Graphics Framework
}