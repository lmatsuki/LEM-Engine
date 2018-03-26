#pragma once

#include <SDL.h>
#include <iostream>
#include "IFramework.h"

class InputFramework : public IFramework
{
public:
	InputFramework();
	~InputFramework();

	virtual const std::string & getFrameworkName() override;







	// Legacy code //
	void update();
	bool exitScene();
	std::string getInputText();
	void toggleInputState(const bool toggle = false);
	void clearInputText();

	bool getDisplayInputText();
	void toggleDisplayInputText(const bool toggle = false);

	bool getInputFinished();
	void setInputFinished(const bool finished);
	bool getInputChanged();
	void setInputChanged(const bool changed);

private:
	bool _pendingExit;
	std::string _inputText;
	bool _displayInputText;
	bool _inputFinished;
	bool _inputChanged;
};