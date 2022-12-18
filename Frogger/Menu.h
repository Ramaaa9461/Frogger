#pragma once

#include "raylib.h"
#include "SceneManager.h"
#include "AssetsImporter.h"

class Menu
{
private: 

	AssetsImporter* AI;
	Texture background;
	Font font;

	Rectangle button1;
	Rectangle button2;
	Rectangle button3;
	Rectangle button4;

	void setButtons(Rectangle& rectangle, int sizeX, int sizeY, int difWidth, int difHeight);

public:

	void initMenu();
	void updateMenu();
	void drawMenu();
};

