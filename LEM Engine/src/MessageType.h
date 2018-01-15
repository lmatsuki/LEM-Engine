#pragma once

enum class MessageType
{
	Console,

	// GUI System	
	LoadBackground,
	LoadImage,

	// Render System
	CreateMainWindow,
	
	// Game Logic
	QuitGame,
};