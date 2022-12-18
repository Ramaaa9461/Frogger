#include "SceneManager.h"

SceneManager* SceneManager::sceneManager = nullptr;

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{

}

SceneManager* SceneManager::getSceneManager()
{
	if (sceneManager == nullptr) {
		sceneManager = new SceneManager();
	}

	return sceneManager;
}

Scene SceneManager::getCurrentScene()
{
	return scene;
}

void SceneManager::setCurrentScene(Scene _scene)
{
	resetValues = true;
	scene = _scene;
}

void SceneManager::setCurrentScene(Scene _scene, bool resetValues)
{
	this->resetValues = resetValues;
	scene = _scene;
}

void SceneManager::setPlayerHaveWon(bool haveWon)
{
	playerHaveWon = haveWon;
}

bool SceneManager::getPlayerHaveWon()
{
	return playerHaveWon;
}

void SceneManager::setResetValues(bool reset)
{
	resetValues = reset;
}

bool SceneManager::getResetValues()
{
	return resetValues;
}



