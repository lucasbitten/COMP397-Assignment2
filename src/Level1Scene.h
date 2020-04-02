#pragma once
#ifndef __LEVEL1_SCENE__
#define __LEVEL1_SCENE__

#include "Background.h"
#include "Scene.h"


#include "Player.h"
#include "ExplosionManager.h"
#include "BulletManager.h"



class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();

	// Scene LifeCycle Functions
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;
private:
	glm::vec2 m_mousePosition;

	Player* m_pPlayer;
	Background* m_pBackground;
};

#endif /* defined (__LEVEL1_SCENE__) */