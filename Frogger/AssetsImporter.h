#pragma once

#include "raylib.h"

class AssetsImporter
{
private:

	AssetsImporter();

	static AssetsImporter* assetsImporter;

	Font font;

	Texture backgroundGameplay;

	Texture blueCar;
	Texture yellowCar;
	Texture greenCar;
	Texture truck;
	Texture trunk;
	Texture frog;
	Texture victoryFrog;

	Music   gameplayMusic;
	Music   menuMusic;

	Sound   jumpSound;


public:

	~AssetsImporter();

	static AssetsImporter* getAssetsImporter();

	void initAssetsImporter();
	void deInitAssetImporter();
	Font getFont();

	Texture getBackgroundGameplay();
	Texture getBlueCar();
	Texture getYellowCar();
	Texture getGreenCar();
	Texture getTruck();
	Texture getTrunk();
	Texture getFrog();
	Texture getVictoryFrog();

	Music getGameplayMusic();
	Music getMenuMusic();

	Sound getJumpSound();


};

