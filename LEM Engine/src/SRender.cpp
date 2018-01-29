#include "SRender.h"

SRender::SRender(std::shared_ptr<MessageBus> messageBus, std::shared_ptr<FGraphics> graphicsFramework)
	: _graphicsFramework(graphicsFramework), ISystem(messageBus)
{

}

SRender::~SRender()
{
	std::cout << "SRender is finally shutdown." << std::endl;
}

const std::string SRender::getSystemName()
{
	return "SRender";
}

void SRender::handleMessages(const std::shared_ptr<Message> & message)
{
	switch (message->type)
	{
		case MessageType::CreateMainWindow:
		{
			std::string windowName = ((StringMessage*)message.get())->dataString;
			_graphicsFramework.get()->createMainWindow(windowName);
			break;
		}
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
		case MessageType::RemoveImage:
		{
			std::string filePath = ((StringMessage*)message.get())->dataString;
			_graphicsFramework.get()->unrenderImage(filePath);
			break;
		}
	}
}

void SRender::update()
{
	_graphicsFramework.get()->render();
}
