#include "Credits.h"


void Credits::initCredits()
{
	AI = AssetsImporter::getAssetsImporter();
	background = AI->getCreditsBackground();
	font = AI->getFont();

	int sizeX = 150;
	int sizeY = 75;
	setButtons(button1, sizeX, sizeY, 0, GetScreenHeight() / 2 - sizeY / 2);
}

void Credits::updateCredits()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (CheckCollisionPointRec(GetMousePosition(), button1))
		{
			SceneManager::getSceneManager()->setCurrentScene(Scene::MENU);
		}
	}
}

void Credits::drawCredits()
{
	DrawTexture(background, 0, 0, WHITE);

	int fontSize = 15;

	float y = 250;

	DrawTextEx(font, "FROGGER GAME SPRITES: http://www.classicgaming.cc/classics/frogger/graphics" , { 0, y }, fontSize, 2.0f, RED);



	DrawRectangleRec(button1, ORANGE);
	DrawTextEx(font, "Menu", { button1.x + button1.width / 2 - MeasureText("Menu", fontSize) / 2, button1.y + button1.height / 2 - fontSize / 2 }, fontSize, 2.0f, RED);

}

void Credits::setButtons(Rectangle& rectangle, int sizeX, int sizeY, int difWidth, int difHeight)
{
	rectangle.width = sizeX;
	rectangle.height = sizeY;
	rectangle.x = (GetScreenWidth() / 2) - (sizeX / 2) + difWidth;
	rectangle.y = (GetScreenHeight() / 2) - (sizeY / 2) + difHeight;
}