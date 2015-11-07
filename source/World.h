//
// Created by Nils Daumann on 06.11.15.
//

#ifndef PROJECT_SACRIFICE_WORLD_H
#define PROJECT_SACRIFICE_WORLD_H

#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <Box2D/Box2D.h>
#include "TexturePool.h"
#include "EntityManager.h"

namespace PS
{
	class World
	{
	public:
		void Loop();

		b2World *GetPhysicsWorld()
		{
			return _physicsWorld;
		}

		float GetScaleFactor()
		{
			return _scaleFactor;
		}

		float GetAspectRatio()
		{
			return _scaleFactor;
		}

		sf::RenderWindow *GetWindow()
		{
			return _window;
		}

		static World *GetInstance();

	private:
		World();
		static World *_instance;

		b2World *_physicsWorld;
		sf::RenderWindow *_window;
		float _scaleFactor;
		float _aspectRatio;
	};
}


#endif //PROJECT_SACRIFICE_WORLD_H
