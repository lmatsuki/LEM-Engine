#pragma once

enum class MessageType
{
	Console,

	// Scene System
	LoadData,
	SaveData,

	// GUI System	
	LoadBackground,
	LoadImage,
	RemoveImage,

	// Render System
	CreateMainWindow,
	
	// Game Logic
	QuitGame,

	// Timed Events
	TimedMilliSecondsEvent,
	TimedSecondsEvent,
};