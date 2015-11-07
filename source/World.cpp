//
// Created by Nils Daumann on 06.11.15.
//

#include "World.h"
#include "PhysicsEntity.h"
#include "Background.h"
#include "Ragdoll.h"

namespace PS
{
	World *World::_instance = 0;
	const float World::WORLD_TO_BOX2D = 0.01f;

	World *World::GetInstance()
	{
		if(!_instance)
			_instance = new World();

		return _instance;
	}

	World::World()
	{
		_window = new sf::RenderWindow(sf::VideoMode(720, 576), "Project Sacrifice");
		_scaleFactor = _window->getSize().y/1080.0f;
		_aspectRatio = _window->getSize().y/_window->getSize().x;

		b2Vec2 gravity(0.0f, 9.81f);
		_physicsWorld = new b2World(gravity);
	}

	void World::Loop()
	{
		new Background();
		new PhysicsEntity();
		new Ragdoll();

		sf::Time time = sf::Time::Zero;
		sf::Clock clock;

		while(_window->isOpen())
		{
			sf::Event Event;
			while(_window->pollEvent(Event))
			{
				if(Event.type == sf::Event::Closed)
					_window->close();
			}

			time += clock.getElapsedTime();
			clock.restart();
			while(time.asSeconds() > 1.0f / 60.0f)
			{
				_physicsWorld->Step(1.0f / 60.0f, 6, 2);

				EntityManager::GetInstance()->Update();

				time -= sf::seconds(1.0f / 60.0f);
			}

			_window->clear(sf::Color::Black);

			EntityManager::GetInstance()->Draw(_window);

			_window->display();
		}
	}
}
