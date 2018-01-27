#include "GUI.h"

GUI::GUI(std::shared_ptr<MessageBus> messageBus, std::shared_ptr<Graphics> graphicsFramework) 
	: _graphicsFramework(graphicsFramework), System(messageBus)
{
	//Exception e("Some GUI initializiation error.");
	//throw (e);

	// Initialize frameworks

}

GUI::~GUI()
{
	std::cout << "GUI is finally shutdown." << std::endl;
}

const std::string GUI::getSystemName()
{
	return "GUI";
}

void GUI::handleMessages(const std::shared_ptr<Message> & message)
{
	switch (message->type)
	{
		case MessageType::LoadBackground:	
		{
			std::string filePath = ((StringMessage*)message.get())->dataString;
			_graphicsFramework.get()->loadImage(filePath);
			break;
		}
		case MessageType::LoadImage:
		{
			std::string filename = ((ImageMessage*)message.get())->imageData->fileName;
			if (_graphicsFramework.get()->storeImage(filename, std::move(((ImageMessage*)message.get())->imageData)))
				_graphicsFramework.get()->renderImage(filename);
			break;
		}
	}
}

void GUI::update()
{
	// Render System already calls render to Graphics Framework
}