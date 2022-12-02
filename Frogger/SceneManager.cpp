#include "SceneManager.h"

SceneManager::SceneManager()
{
	scene = Scene::GAME;
}

SceneManager::~SceneManager()
{

}

Scene SceneManager::getCurrentScene()
{
	return scene;
}

void SceneManager::setCurrentScene(Scene scene)
{
	this->scene = scene;
}

