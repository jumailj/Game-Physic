#include "GUIText.h"

// it will draw default -> 

	GUIText::GUIText(int posX_, int posY_, int fontSize_, Color color_, bool isDraw_)
		:posX{ posX_ }, posY{ posY_ }, fontSize{ fontSize_ }, color{ color_ }, isDraw{ isDraw_ }
	{
		strcpy(text, "\0");
	}

	void GUIText::UpdateText(const char* format, ...)
	{
		va_list aptr;

		va_start(aptr, format);

		vsprintf(text, format, aptr);
		va_end(aptr);

		Draw();
	}

	void GUIText::Draw() {
		if (isDraw) {
			DrawText(text, posX, posY, fontSize, color);
		}

	}

	GUIText::~GUIText() {


	}