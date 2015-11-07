//
// Created by Nils Daumann on 06.11.15.
//

#ifndef PROJECT_SACRIFICE_WORLD_H
#define PROJECT_SACRIFICE_WORLD_H

#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>
#include "TexturePool.h"
#include "SoundPool.h"
#include "EntityManager.h"

namespace PS
{
	class Priest;
	class Animal;
	class ParticleEmitter;
	class Background;

	class World
	{
	public:
		void Loop();
		void Update(float timeStep);

		b2World *GetPhysicsWorld()
		{
			return _physicsWorld;
		}

		float GetScaleFactor()
		{
			return _scaleFactor;
		}

		sf::RenderWindow *GetWindow()
		{
			return _window;
		}

		static World *GetInstance();

		static const float WORLD_TO_BOX2D;

	private:
		World();
		static World *_instance;

		b2World *_physicsWorld;
		sf::RenderWindow *_window;
		float _scaleFactor;

		Priest *_priest;
		Animal *_currentAnimal;
		ParticleEmitter *_bloodParticles;
		Background *_background;

		float _spawnTimer;
		bool _isKilling;
		bool _keyWasPressed;

		float _spawnTime;

		sf::Sound _splatSound;
		sf::Sound _stabSound;
		sf::Music _music;
	};
}


#endif //PROJECT_SACRIFICE_WORLD_H
