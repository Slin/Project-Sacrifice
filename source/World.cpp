//
// Created by Nils Daumann on 06.11.15.
//

#include "World.h"
#include "Entity.h"

namespace PS
{
	World *World::_instance = 0;

	World *World::GetInstance()
	{
		if (!_instance)
			_instance = new World();

		return _instance;
	}


	World::World()
	{
		_window = new sf::RenderWindow(sf::VideoMode(800, 600), "Project Sacrifice");

		b2Vec2 gravity(0.0f, 9.81f);
		_physicsWorld = new b2World(gravity);
	}

	void World::Loop()
	{
		Entity box;
		box.setPosition(sf::Vector2<float>(50.0f, 50.0f));
		box.setSize(sf::Vector2<float>(50.0f, 50.0f));

		b2BodyDef groundBodyDef;
		groundBodyDef.position.Set(0.0f, 500.0f);
		b2Body *groundBody = _physicsWorld->CreateBody(&groundBodyDef);
		b2PolygonShape groundBox;
		groundBox.SetAsBox(1000.0f, 10.0f);
		groundBody->CreateFixture(&groundBox, 0.0f);

		sf::Time time = sf::Time::Zero;
		sf::Clock clock;

		while(_window->isOpen())
		{
			sf::Event Event;
			while(_window->pollEvent(Event))
			{
				if (Event.type == sf::Event::Closed)
					_window->close();
			}

			time += clock.getElapsedTime();
			clock.restart();
			while(time.asSeconds() > 1.0f / 60.0f)
			{
				_physicsWorld->Step(1.0f / 60.0f, 6, 2);

				box.Update();

				time -= sf::seconds(1.0f / 60.0f);
			}

			_window->clear(sf::Color::Black);
			_window->draw(box);

			_window->display();
		}
	}
}