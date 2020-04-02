#include "Level1Scene.h"
#include "Game.h"

Level1Scene::Level1Scene()
{
	Level1Scene::start();
}

Level1Scene::~Level1Scene()
= default;

void Level1Scene::draw()
{
	m_pBackground->draw();
	BulletManager::Instance()->draw();

	drawDisplayList();
	ExplosionManager::Instance()->draw();
}

void Level1Scene::update()
{

	m_pBackground->update();

	updateDisplayList();
	ExplosionManager::Instance()->update();
	BulletManager::Instance()->update();

}

void Level1Scene::clean()
{

	removeAllChildren();
}

void Level1Scene::handleEvents()
{
	auto wheel = 0;

	SDL_Keycode keyPressed;
	SDL_Keycode keyReleased;
	
	SDL_Event event;

	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_SPACE]) {
		if (m_pPlayer->getShootTime() <= 0)
		{
			m_pPlayer->setShootTime(m_pPlayer->getShootRate());
			auto bullet = BulletManager::Instance()->getBullet();
			bullet->activate();
			bullet->setPosition(glm::vec2(m_pPlayer->getPosition().x + 15, m_pPlayer->getPosition().y + 18));

		}
	}

	if (state[SDL_SCANCODE_S]) {
		m_pPlayer->move(DOWN);
		m_pPlayer->yBrakeDirection = EMPTY;
	}

	if (state[SDL_SCANCODE_W]) {
		m_pPlayer->move(UP);
		m_pPlayer->yBrakeDirection = EMPTY;
	}

	if (state[SDL_SCANCODE_A]) {
		m_pPlayer->move(LEFT);
		m_pPlayer->xBrakeDirection = EMPTY;
	}

	if (state[SDL_SCANCODE_D]) {
		m_pPlayer->move(RIGHT);
		m_pPlayer->xBrakeDirection = EMPTY;
	}
	
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			keyPressed = event.key.keysym.sym;
			switch (keyPressed)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				//TheGame::Instance()->changeSceneState(SceneState::PLAY_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;

			}
			// movement keys
			/*{
				if(keyPressed == SDLK_w)
				{
					if (!state[SDL_SCANCODE_S]) {
						m_pPlayer->move(UP);
						m_pPlayer->yBrakeDirection = EMPTY;
					}

				}

				if (keyPressed == SDLK_a)
				{
					m_pPlayer->move(LEFT);
					m_pPlayer->xBrakeDirection = EMPTY;

				}

				if (keyPressed == SDLK_s)
				{
					m_pPlayer->move(DOWN);
					m_pPlayer->yBrakeDirection = EMPTY;

				}

				if (keyPressed == SDLK_d)
				{
					m_pPlayer->move(RIGHT);
					m_pPlayer->xBrakeDirection = EMPTY;

				}
			}*/
			
			break;
		case SDL_KEYUP:
			keyReleased = event.key.keysym.sym;

			
			if (keyReleased == SDLK_w)
			{
				m_pPlayer->yBrakeDirection = UP;

			}

			if (keyReleased == SDLK_s)
			{
				m_pPlayer->yBrakeDirection = DOWN;

			}
			if (keyReleased == SDLK_a)
			{
				m_pPlayer->xBrakeDirection = LEFT;
			}

			if (keyReleased == SDLK_d)
			{
				m_pPlayer->xBrakeDirection = RIGHT;

			}

			if(keyReleased == SDLK_SPACE)
			{
				m_pPlayer->setShootTime(0);

			}
			
			break;
			
		}
	}
}

void Level1Scene::start()
{

	m_pBackground = new Background();
	
	m_pPlayer = new Player();
	m_pPlayer->setPosition(glm::vec2(70.0f, Config::SCREEN_HEIGHT * 0.5f));
	addChild(m_pPlayer);


	
}
