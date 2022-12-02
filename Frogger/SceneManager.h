#pragma once

enum class Scene { MENU = 1, GAME, RULES, CREDITS, EXIT, ENDGAME };

class SceneManager
{
private:
	Scene scene;

public:
	SceneManager();
	~SceneManager();

	Scene getCurrentScene();

	void setCurrentScene(Scene _scene);
};

