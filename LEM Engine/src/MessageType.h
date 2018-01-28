#pragma once

enum class MessageType
{
	Console,

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