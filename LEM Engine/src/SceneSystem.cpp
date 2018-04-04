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
			std::cout << "�f�[�^���[�h���߂̎�M���m�F�B" << std::endl;
			_xmlParserFramework.get()->loadFile();
			break;
		}
		case MessageType::SaveData:
		{
			std::cout << "�f�[�^�Z�[�u���߂̎�M���m�F�B" << std::endl;
			break;
		}
	}
}

void SceneSystem::update()
{
	
}
