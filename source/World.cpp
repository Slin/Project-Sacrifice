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

	World::World() : _physicsWorld(nullptr), _background(nullptr)
	{
		_window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Project Sacrifice");
		_scaleFactor = _window->getSize().y/1080.0f;
	}

	void World::Reset()
	{
		EntityManager::GetInstance()->RemoveAllEntities();

		if(_physicsWorld)
			delete _physicsWorld;

		b2Vec2 gravity(0.0f, 9.81f);
		_physicsWorld = new b2World(gravity);

		_currentAnimal = nullptr;
		_spawnTime = 3.0f;
		_isKilling = false;
		_isGameOver = false;
		_fuckYeah = false;
		_isMenu = true;

		_background = new Background();
		_priest = new Priest();
		_keys = new Keys();
		_bloodParticles = new ParticleEmitter();
	}

	void World::Loop()
	{
		Reset();

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

				Update(1.0f/60.0f);
				EntityManager::GetInstance()->Update(1.0f/60.0f);

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
				case Animal::Type::Opfer:
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
						return true;
					break;
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
		if(_isMenu)
		{
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				if(!_keyWasPressed)
				{
					_isMenu = false;
					_keyWasPressed = true;
				}
			}
			else
			{
				_keyWasPressed = false;
			}
			return;
		}

		if(_isGameOver && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			Reset();
			_keyWasPressed = true;
			return;
		}

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

								_fuckYeah = false;
							}
							else
							{
								_fuckYeah = true;
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
			_currentAnimal->Kill(_fuckYeah);
			_currentAnimal = nullptr;
			_isKilling = false;
		}

		_spawnTimer += timeStep;

		if(_spawnTimer > _spawnTime || !_currentAnimal)
		{
			if(_currentAnimal)
			{
				_currentAnimal->Kill(false);
				_currentAnimal = nullptr;

				if(_background->RemoveLife())
				{
					_isGameOver = true;
				}
			}

			_spawnTimer = 0.0f;
			Animal::Type type = static_cast<Animal::Type>(rand()%4);
			_keys->SetType(type);
			_currentAnimal = new Animal(type);
		}

		_spawnTime -= timeStep*0.01f;
	}
}
