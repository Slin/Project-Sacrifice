//
// Created by Nils Daumann on 06.11.15.
//

#include "World.h"
#include "PhysicsEntity.h"
#include "Background.h"
#include "Ragdoll.h"
#include "Animal.h"
#include "Priest.h"
#include "ParticleEmitter.h"
#include "Background.h"
#include "Keys.h"

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

	World::World() : _currentAnimal(nullptr), _spawnTime(3.0f), _isKilling(false), _isGameOver(false)
	{
		_window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Project Sacrifice");
		_scaleFactor = _window->getSize().y/1080.0f;

		b2Vec2 gravity(0.0f, 9.81f);
		_physicsWorld = new b2World(gravity);
	}

	void World::Loop()
	{
		_background = new Background();
		_priest = new Priest();
		_keys = new Keys();
		_bloodParticles = new ParticleEmitter();
		sf::Vector2f vec;
		vec.x=600;
		vec.y=0;
		new Ragdoll(vec);
		sf::Time deltaTime = sf::Time::Zero;
		sf::Time time = sf::Time::Zero;
		sf::Clock clock;

		_music.openFromFile("assets/sounds/Rite_of_Passage.ogg");
		_music.play();

		while(_window->isOpen())
		{
			sf::Event Event;
			while(_window->pollEvent(Event))
			{
				if(Event.type == sf::Event::Closed)
					_window->close();
			}

			deltaTime = clock.getElapsedTime();
			time += deltaTime;
			clock.restart();
			int counter = 0;
			while(time.asSeconds() > 1.0f / 60.0f && counter < 4)
			{
				_physicsWorld->Step(1.0f / 60.0f, 2, 1);

				EntityManager::GetInstance()->Update(1.0f/60.0f);
				Update(1.0f/60.0f);

				time -= sf::seconds(1.0f / 60.0f);
				counter += 1;
			}

			_window->clear(sf::Color::Black);

			EntityManager::GetInstance()->Draw(_window);

			_window->display();
		}
	}

	bool World::AnyKeyPressed()
	{
		return (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
	}

	bool World::IsCorrectKeyPressed()
	{
		if(_currentAnimal)
		{
			switch(_currentAnimal->GetType())
			{
				case Animal::Type::Pig:
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
						return true;
					break;
				case Animal::Type::Sheep:
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
						return true;
					break;
				case Animal::Type::Baby:
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
						return true;
					break;
			}
		}

		return false;
	}

	void World::Update(float timeStep)
	{
		if(_isGameOver)
			return;

		if(AnyKeyPressed())
		{
			if(!_keyWasPressed)
			{
				if(!_isKilling)
				{
					if(_priest->GetAnimationTimer() <= 0.0001f)
					{
						_priest->Animate();

						if(_currentAnimal)
						{
							_isKilling = true;
							_bloodParticles->Bleed();

							_splatSound.setBuffer(*SoundPool::GetInstance()->PlaySplat());
							_splatSound.play();

							_stabSound.setBuffer(*SoundPool::GetInstance()->PlayStab());
							_stabSound.play();

							if(!IsCorrectKeyPressed())
							{
								if(_background->RemoveLife())
								{
									_isGameOver = true;
								}
							}
						} else {
							_stabSound.setBuffer(*SoundPool::GetInstance()->PlayStab());
							_stabSound.play();
						}
					}
				}
			}
			_keyWasPressed = true;
		}
		else
		{
			_keyWasPressed = false;
		}

		if(_priest->GetAnimationTimer() > 0.09 && _currentAnimal && _isKilling)
		{
			_currentAnimal->Kill();
			_currentAnimal = nullptr;
			_isKilling = false;
		}

		_spawnTimer += timeStep;

		if(_spawnTimer > _spawnTime || !_currentAnimal)
		{
			if(_currentAnimal)
			{
				_currentAnimal->Kill();
				_currentAnimal = nullptr;

				if(_background->RemoveLife())
				{
					_isGameOver = true;
				}
			}

			_spawnTimer = 0.0f;
			Animal::Type type = static_cast<Animal::Type>(rand()%3);
			_keys->SetType(type);
			_currentAnimal = new Animal(type);
		}

		_spawnTime -= timeStep*0.01f;
	}
}
