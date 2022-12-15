#include "AssetsImporter.h"

AssetsImporter* AssetsImporter::assetsImporter = nullptr;


AssetsImporter::AssetsImporter()
{
	initAssetsImporter();
}

AssetsImporter::~AssetsImporter() {}


AssetsImporter* AssetsImporter::getAssetsImporter()
{
	if (assetsImporter == nullptr)
	{
		assetsImporter = new AssetsImporter();
	}

	return assetsImporter;
}

void AssetsImporter::initAssetsImporter()
{
	font = LoadFont("res/Fonts/JungleAdventurer.ttf");

	backgroundGameplay = LoadTexture("res/Images/gameplayBackground.png");

	blueCar = LoadTexture("res/Images/blueCar.png");
	yellowCar = LoadTexture("res/Images/yellowCar.png");
	greenCar = LoadTexture("res/Images/greenCar.png");
	truck = LoadTexture("res/Images/truck.png");
	trunk = LoadTexture("res/Images/trunk.png");
	frog = LoadTexture("res/Images/frog.png");
	victoryFrog = LoadTexture("res/Images/CollectedFrog.png");

	gameplayMusic = LoadMusicStream("res/Music/gameplayMusic.wav");

	jumpSound = LoadSound("res/Sfx/jump.ogg");
}

void AssetsImporter::deInitAssetImporter()
{
	UnloadFont(font);

	UnloadTexture(backgroundGameplay);

	UnloadTexture(blueCar);
	UnloadTexture(yellowCar);
	UnloadTexture(greenCar);
	UnloadTexture(truck);
	UnloadTexture(trunk);
	UnloadTexture(frog);
	UnloadTexture(victoryFrog);

	UnloadMusicStream(gameplayMusic);
	UnloadMusicStream(menuMusic);

	UnloadSound(jumpSound);


}

Font AssetsImporter::getFont()
{
	return font;
}

Texture AssetsImporter::getBackgroundGameplay()
{
	return backgroundGameplay;
}

Texture AssetsImporter::getBlueCar()
{
	return blueCar;
}

Texture AssetsImporter::getYellowCar()
{
	return yellowCar;
}

Texture AssetsImporter::getGreenCar()
{
	return greenCar;
}

Texture AssetsImporter::getTruck()
{
	return truck;
}

Texture AssetsImporter::getTrunk()
{
	return trunk;
}

Texture AssetsImporter::getFrog()
{
	return frog;
}

Texture AssetsImporter::getVictoryFrog()
{
	return victoryFrog;
}

Music AssetsImporter::getGameplayMusic()
{
	return gameplayMusic;
}

Music AssetsImporter::getMenuMusic()
{
	return menuMusic;
}

Sound AssetsImporter::getJumpSound()
{
	return jumpSound;
}










