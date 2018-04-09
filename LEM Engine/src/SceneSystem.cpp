#include "SceneSystem.h"

SceneSystem::SceneSystem(std::shared_ptr<MessageBus> messageBus, std::shared_ptr<IParserFramework> parserFramework)
	: _parserFramework(parserFramework), ISystem(messageBus)
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
		// Check the event to current Scene (context) and post message
		case MessageType::LoadData:
		{
			//std::cout << "�f�[�^���[�h���߂̎�M���m�F�B" << std::endl;
			//_parserFramework.get()->loadFile();
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
