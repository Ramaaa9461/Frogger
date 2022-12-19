#include "Pause.h"



void Pause::initPause()
{
	AI = AssetsImporter::getAssetsImporter();
	background = AI->getPauseBackground();
	clickSound = AI->getClickSound();
	font = AI->getFont();

	int sizeX = 250;
	int sizeY = 100;
	setButtons(button1, sizeX, sizeY, -150, 200);
	setButtons(button2, sizeX, sizeY, 150, 200);
}

void Pause::updatePause(Music& gameplayMusic)
{
	UpdateMusicStream(gameplayMusic);

	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (CheckCollisionPointRec(GetMousePosition(), button1))
		{
			SceneManager::getSceneManager()->setCurrentScene(Scene::GAME, false);
			PlaySound(clickSound);
		}
		else if (CheckCollisionPointRec(GetMousePosition(), button2))
		{
			StopMusicStream(gameplayMusic);
			SceneManager::getSceneManager()->setCurrentScene(Scene::MENU);
			PlaySound(clickSound);
		}
	}

}

void Pause::drawPause()
{
	DrawTexture(background, 0, 0, WHITE);

	int fontSize = 30;

	DrawRectangleRec(button1, ORANGE);
	DrawTextEx(font, "Resume", { button1.x + button1.width / 2 - MeasureText("Resume", fontSize) / 2, button1.y + button1.height / 2 - fontSize / 2 }, fontSize, 2.0f, RED);
	DrawRectangleRec(button2, ORANGE);
	DrawTextEx(font, "Menu", { button2.x + button2.width / 2 - MeasureText("Menu", fontSize) / 2, button2.y + button1.height / 2 - fontSize / 2 }, fontSize, 2.0f, RED);

}

void Pause::setButtons(Rectangle& rectangle, int sizeX, int sizeY, int difWidth, int difHeight)
{
	rectangle.width = sizeX;
	rectangle.height = sizeY;
	rectangle.x = (GetScreenWidth() / 2) - (sizeX / 2) + difWidth;
	rectangle.y = (GetScreenHeight() / 2) - (sizeY / 2) + difHeight;
}