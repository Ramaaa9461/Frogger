#pragma once

enum class Scene { MENU = 1, GAME, RULES, CREDITS, EXIT, ENDGAME };

class SceneManager
{
private:

	SceneManager();
	Scene scene = Scene::GAME;
	static SceneManager* sceneManager;
	bool playerHaveWon;

public:
	~SceneManager();

	static SceneManager* getSceneManager();

	Scene getCurrentScene();

	void setCurrentScene(Scene _scene);


	 void setPlayerHaveWon(bool haveWon);
	 bool getPlayerHaveWon();
};

