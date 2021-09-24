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
	GUIText(int posX_, int posY_, int fontSize_, Color color_, bool isDraw_ = true)
		:posX{ posX_ }, posY{ posY_ }, fontSize{ fontSize_ }, color{ color_ }, isDraw{isDraw_}
	{
		strcpy(text, "\0");
	}
	
	void UpdateText(const char* format, ...) 
	{
		va_list aptr;
		
		va_start(aptr, format);

		vsprintf(text, format, aptr);
		va_end(aptr);

		Draw();	
	}

	void Draw() {
		if (isDraw) {
			DrawText(text, posX, posY, fontSize, color);
		}

	}

	~GUIText() {


	}
};

