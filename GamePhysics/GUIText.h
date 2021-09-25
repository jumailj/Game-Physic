#pragma once
#include"raylib.h"
#include <string>
#include <cstdarg>

#include <iostream>

// it will draw default -> 
class GUIText
{
	char text[50];
	int posX;
	int posY;
	int fontSize;
	Color color;

	bool isDraw;

public:
	GUIText(int posX_, int posY_, int fontSize_, Color color_, bool isDraw_ = true);
	void UpdateText(const char* format, ...);
	void Draw();
	~GUIText();

};

