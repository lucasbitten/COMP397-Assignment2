#pragma once
#ifndef __GAME__OVER_SCENE__
#define __GAME__OVER_SCENE__

#include "Scene.h"
#include "Label.h"

class GameOverScene final : public Scene
{
public:
	GameOverScene();
	~GameOverScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

private:
	Label* m_label{};
	Label* m_enemiesDestroyed;
	Label* m_score;
	Label* m_tryAgain;

};

#endif /* defined (__GAME__OVER_SCENE__) */