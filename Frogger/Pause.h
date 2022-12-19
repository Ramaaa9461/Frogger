#pragma once

#include "raylib.h"

#include "SceneManager.h"
#include "AssetsImporter.h"

class Pause
{
private:

	AssetsImporter* AI;
	Texture background;
	Sound clickSound;
	Font font;

	Rectangle button1;
	Rectangle button2;

	void setButtons(Rectangle& rectangle, int sizeX, int sizeY, int difWidth, int difHeight);


public:

	void initPause();
	void updatePause(Music &gameplayMusic);
	void drawPause();
};

