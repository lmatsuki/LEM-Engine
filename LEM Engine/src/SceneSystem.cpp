#include "SceneSystem.h"

SceneSystem::SceneSystem(std::shared_ptr<MessageBus> messageBus, std::shared_ptr<XMLParserFramework> xmlParserFramework) 
	: _xmlParserFramework(xmlParserFramework), ISystem(messageBus)
{

}


SceneSystem::~SceneSystem()
{
}

const std::string SceneSystem::getSystemName()
{
	return "Scene";
}

void SceneSystem::handleMessages(const std::shared_ptr<Message>& message)
{
	switch (message->type)
	{
		case MessageType::LoadData:
		{
			std::cout << "データロード命令の受信を確認。" << std::endl;
			_xmlParserFramework.get()->loadFile();
			break;
		}
		case MessageType::SaveData:
		{
			std::cout << "データセーブ命令の受信を確認。" << std::endl;
			break;
		}
	}
}

void SceneSystem::update()
{
	
}
