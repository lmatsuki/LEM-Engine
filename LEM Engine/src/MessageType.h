#pragma once

enum class MessageType
{
	InvalidMessage,
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