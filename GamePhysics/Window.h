#pragma once
#include <raylib.h>

class Window
{

private:
	int WindowWidth;
	int WindowHeight;
	const char* WindowTitle;

	int frameRate = 60;

public:
	Window(int windowWidth_ = 1200, int windowHeight_ = 700, const char * windowTitle_ = "game physics")
		:WindowWidth{ windowWidth_ }, WindowHeight{ windowHeight_ }, WindowTitle{ windowTitle_ }
	{

	}

	~Window() {
		CloseWindow();
	}

	void WindowInit()
	{
		// window created;
		InitWindow(WindowWidth, WindowHeight, WindowTitle);
		SetTargetFPS(frameRate);
	}

	bool WindowClosed() {
		return WindowShouldClose();
	}

	// getters;

	float getWindowWidht() {
		return WindowWidth;
	}

	float getWindowHeight() {
		return WindowHeight;
	}
};

