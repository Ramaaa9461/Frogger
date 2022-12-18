#pragma once

#include "raylib.h"

#include "AssetsImporter.h"
#include "SceneManager.h"

class Credits
{
private:

	AssetsImporter* AI;
	Texture background;
	Font font;

	Rectangle button1;

	void setButtons(Rectangle& rectangle, int sizeX, int sizeY, int difWidth, int difHeight);



public:

	void initCredits();
	void updateCredits();
	void drawCredits();
};

