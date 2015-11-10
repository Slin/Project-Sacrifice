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
#include "Slave.h"
#include "EndFelsen.h"
#include <iostream>

#if __APPLE__
#include <CoreFoundation/CoreFoundation.h>
#endif

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
#if __APPLE__ && NDEBUG
		CFBundleRef bundle = CFBundleGetMainBundle();
		CFURLRef url = CFBundleCopyBundleURL(bundle);

		CFStringRef urlString = CFURLCopyPath(url);

		const char *file = CFStringGetCStringPtr(urlString, kCFStringEncodingUTF8);
		_bundlePath = file;
		_bundlePath += "Contents/Resources/";
#else
		_bundlePath = "";
#endif

		_window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Project Sacrifice");//, sf::Style::Fullscreen);
		_scaleFactor = _window->getSize().y / 1080.0f;

		_menuFont.loadFromFile(GetBundlePath()+"assets/fonts/troika.otf");

		_menuText.setFont(_menuFont);
		_menuText.setString("Press SPACE to start the game.");
		_menuText.setColor(sf::Color::White);
		_menuText.setCharacterSize(60.0f);
		_menuText.setOrigin(_menuText.getLocalBounds().width * 0.5f, _menuText.getLocalBounds().height * 0.5f);
		_menuText.setScale(_scaleFactor, _scaleFactor);
		_menuText.setPosition(_window->getSize().x * 0.5f, 970.0f * _scaleFactor);

		_gameOverText.setFont(_menuFont);
		_gameOverText.setString("GAME OVER.");
		_gameOverText.setColor(sf::Color::White);
		_gameOverText.setCharacterSize(100.0f);
		_gameOverText.setOrigin(_gameOverText.getLocalBounds().width * 0.5f,
								_gameOverText.getLocalBounds().height * 0.5f);
		_gameOverText.setScale(_scaleFactor, _scaleFactor);
		_gameOverText.setPosition(_window->getSize().x * 0.5f, _window->getSize().y * 0.2f);

		_gameOverScoreText.setFont(_menuFont);
		_gameOverScoreText.setString("Score: 000000");
		_gameOverScoreText.setColor(sf::Color::White);
		_gameOverScoreText.setCharacterSize(60.0f);
		_gameOverScoreText.setOrigin(_gameOverScoreText.getLocalBounds().width*.5f, _gameOverScoreText.getLocalBounds().height * 0.5f);
		_gameOverScoreText.setScale(_scaleFactor, _scaleFactor);
		_gameOverScoreText.setPosition(_window->getSize().x*.5f, _gameOverText.getPosition().y + _gameOverText.getLocalBounds().height * 1.5f);
		
		_gameOverSuccessText.setFont(_menuFont);
		_gameOverSuccessText.setString("Successful sacrifices: ");
		_gameOverSuccessText.setColor(sf::Color::White);
		_gameOverSuccessText.setCharacterSize(60.0f);
		_gameOverSuccessText.setOrigin(_gameOverSuccessText.getLocalBounds().width*.5f, _gameOverSuccessText.getLocalBounds().height * 0.5f);
		_gameOverSuccessText.setScale(_scaleFactor, _scaleFactor);
		_gameOverSuccessText.setPosition(_window->getSize().x*.5f, _gameOverScoreText.getPosition().y + _gameOverScoreText.getLocalBounds().height* 1.5f);
		
		_gameOverFailText.setFont(_menuFont);
		_gameOverFailText.setString("Failed sacrifices: ");
		_gameOverFailText.setColor(sf::Color::White);
		_gameOverFailText.setCharacterSize(60.0f);
		_gameOverFailText.setOrigin(_gameOverFailText.getLocalBounds().width*.5f, _gameOverFailText.getLocalBounds().height * 0.5f);
		_gameOverFailText.setScale(_scaleFactor, _scaleFactor);
		_gameOverFailText.setPosition(_window->getSize().x*.5f, _gameOverSuccessText.getPosition().y + _gameOverScoreText.getLocalBounds().height*1.5f);
		
		
		_scoreText.setFont(_menuFont);
		_scoreText.setString("Score: 000000");
		_scoreText.setColor(sf::Color::White);
		_scoreText.setCharacterSize(60.0f);
		_scoreText.setOrigin(_scoreText.getLocalBounds().width * 0.5f, _scoreText.getLocalBounds().height * 0.5f);
		_scoreText.setScale(_scaleFactor, _scaleFactor);
		_scoreText.setPosition((_scoreText.getLocalBounds().width/2.f)+_scoreText.getLocalBounds().height*.5f, _scoreText.getLocalBounds().height);

		_stageText.setFont(_menuFont);
		_stageText.setString("Stage: 0");
		_stageText.setColor(sf::Color::White);
		_stageText.setCharacterSize(60.0f);
		_stageText.setOrigin(_stageText.getLocalBounds().width * 0.5f, _stageText.getLocalBounds().height * 0.5f);
		_stageText.setScale(_scaleFactor, _scaleFactor);
		_stageText.setPosition(_window->getSize().x-(_stageText.getLocalBounds().width*.5f)-_stageText.getLocalBounds().height*.5f, _stageText.getLocalBounds().height);

		_popupText.setFont(_menuFont);
		_popupText.setString("100 Points");
		_popupText.setColor(sf::Color::White);
		_popupText.setCharacterSize(60.0f);
		_popupText.setOrigin(_popupText.getLocalBounds().width*.5f, _popupText.getLocalBounds().height * 0.5f);
		_popupText.setScale(_scaleFactor, _scaleFactor);
		_popupText.setPosition(_window->getSize().x*.5f, _window->getSize().y*.5f);
	}

	void World::Reset()
	{
		EntityManager::GetInstance()->RemoveAllEntities();

		if(_physicsWorld)
			delete _physicsWorld;

		b2Vec2 gravity(0.0f, 9.81f);
		_physicsWorld = new b2World(gravity);

		_currentAnimal = nullptr;
		_isKilling = false;
		_isGameOver = false;
		_fuckYeah = false;
		_isMenu = true;

		_background = new Background();
		_priest = new Priest();
		_slave = new Slave();
		_keys = new Keys();
		_bloodParticles = new ParticleEmitter();

		_music.play();
		_music.setPitch(1);
		_musicStep = _music.getDuration().asMilliseconds() / 8.f;
		_nextMusicStep = _musicStep;
		_nextSpawnStep = _nextMusicStep - _musicStep / 4.f;

		_stage=1;
		_score=0;
		_sacrificeCount=0;
		_sacrificeFailCount=0;

		_showPopup=false;
		_popupTimer=0;
	}

	void World::Loop()
	{
		_titleSprite.setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/Logo.png"));
		_titleSprite.setOrigin(_titleSprite.getLocalBounds().width/2.0f, _titleSprite.getLocalBounds().height/2.0f);
		_titleSprite.setScale(_scaleFactor, _scaleFactor);
		_titleSprite.setPosition(_window->getSize().x*0.5f, _window->getSize().y*0.5f);

		_lostSound.setBuffer(*SoundPool::GetInstance()->GetSound("assets/sounds/end.ogg"));

		_music.openFromFile(GetBundlePath()+"assets/sounds/Song15.ogg");
		//_music.setLoop(true);

		Reset();
		sf::Time deltaTime = sf::Time::Zero;
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

			deltaTime = clock.getElapsedTime();
			time += deltaTime;
			clock.restart();
			int counter = 0;
			while(time.asSeconds() > 1.0f / 60.0f && counter < 4)
			{
				_physicsWorld->Step(1.0f / 60.0f, 2, 1);

				EntityManager::GetInstance()->Update(1.0f / 60.0f);

				time -= sf::seconds(1.0f / 60.0f);
				counter += 1;
			}
			Update(deltaTime.asMilliseconds());
			_window->clear(sf::Color::Black);
			EntityManager::GetInstance()->Draw(_window);

			if(_isMenu)
			{
				_window->draw(_menuText);
				_window->draw(_titleSprite);
			}

			if(_isGameOver)
			{
				_window->draw(_gameOverText);
				char t[32];
				sprintf(t, "Score: %06d", _score);
				_gameOverScoreText.setString(t);
				_gameOverScoreText.setOrigin(_gameOverScoreText.getLocalBounds().width*.5f, _gameOverScoreText.getLocalBounds().height * 0.5f);
				_window->draw(_gameOverScoreText);

				sprintf(t, "Successful sacrifices: %03d", _sacrificeCount);
				_gameOverSuccessText.setString(t);
				_gameOverSuccessText.setOrigin(_gameOverSuccessText.getLocalBounds().width*.5f, _gameOverSuccessText.getLocalBounds().height * 0.5f);
				_window->draw(_gameOverSuccessText);

				sprintf(t, "Failed sacrifices: %03d", _sacrificeFailCount);
				_gameOverFailText.setString(t);
				_gameOverFailText.setOrigin(_gameOverFailText.getLocalBounds().width*.5f, _gameOverFailText.getLocalBounds().height * 0.5f);
				_window->draw(_gameOverFailText);
			}

			if(!_isGameOver && !_isMenu)
			{
				char t[32];
				sprintf(t, "Score: %06d", _score);
				_scoreText.setString(t);
				_window->draw(_scoreText);
				//char st[32];
				sprintf(t, "Stage: %d", _stage);
				_stageText.setString(t);
				_window->draw(_stageText);

				if(_showPopup){
					if(_popupTimer<.75f){
						_popupTimer+=deltaTime.asSeconds();

						float value = fabs(sin(_popupTimer/.25f));

						_popupText.setScale(_scaleFactor*value,_scaleFactor*value);
						_popupText.setOrigin(_popupText.getLocalBounds().width*.5f, _popupText.getLocalBounds().height * 0.5f);
						_window->draw(_popupText);
					} else {
						_showPopup=false;
						_popupTimer=0;
					}

				}

			}

			_window->display();
		}
	}

	bool World::AnyKeyPressed()
	{
		return (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
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
							_keys->SetType(Animal::Type::Nothing);
							_isKilling = true;
							_bloodParticles->Bleed();

							_splatSound.setBuffer(*SoundPool::GetInstance()->PlaySplat());
							_splatSound.play();

							_stabSound.setBuffer(*SoundPool::GetInstance()->PlayStab());
							_stabSound.play();

							_slave->_playAnimation=true;

							if(!IsCorrectKeyPressed())
							{
								
								if(_background->RemoveLife())
								{
									_music.stop();
									_lostSound.play();
									_isGameOver = true;
								}

								_fuckYeah = false;
								if(_currentAnimal->GetType()==Animal::Type::Baby){
									AddScore(-500*_stage);
								} else {
									AddScore(-100*_stage);
								}
							}
							else
							{
								switch(_currentAnimal->GetType()){

									case Animal::Pig:
									case Animal::Sheep:
									case Animal::Opfer:
										AddScore(100*_stage);
										break;
									case Animal::Baby:
										AddScore(250*_stage);
										//_background->AddLife();
										break;
									case Animal::Nothing:break;
								}
								_fuckYeah = true;
							}
						}
						else
						{
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

		if(!_isGameOver && !_isMenu)
		{

			//std::cout << "music time: " << _music.getPlayingOffset().asMilliseconds() << " nextstep:" <<
			//_nextMusicStep << " show Step: " << _nextMusicStep - _musicStep / 2.f << std::endl;
			if(_music.getPlayingOffset().asMilliseconds() >= _nextSpawnStep)
			{
				_nextSpawnStep += _musicStep;
				if(_currentAnimal)
				{
					//_currentAnimal->Kill(false);
					//delete _currentAnimal;
					EntityManager::GetInstance()->RemoveEntity(_currentAnimal);
					_currentAnimal = nullptr;

					if(_background->RemoveLife())
					{
						_music.stop();
						_lostSound.play();
						_isGameOver = true;

					}
				}

				Animal::Type type = static_cast<Animal::Type>(rand() % 4);
				_keys->SetType(type);
				_currentAnimal = new Animal(type);
			}
			if(_music.getPlayingOffset().asMilliseconds() >= _nextMusicStep)
			{
				_keys->_doFlash = true;
				_keys->_doFlashDuration = _musicStep/4.f;
				_nextMusicStep += _musicStep;

			}

			if(_music.getStatus() == sf::SoundSource::Status::Stopped)
			{
				_stage++;
				_music.setPitch(_music.getPitch() + .1f);
				_musicStep = (_music.getDuration().asMilliseconds() / _music.getPitch()) / 8;
				_nextMusicStep = _musicStep;
				_nextSpawnStep = _nextMusicStep - _musicStep / 2.f;
				_music.play();

			}
		}

		if(_isGameOver)
		{

			new EndFelsen();
		}
	}

	void World::AddScore(int scoreToAdd)
	{
		if(scoreToAdd<0){
			_sacrificeFailCount++;
		} else {
			_sacrificeCount++;
		}
		_score += scoreToAdd;
		char t[32];
		sprintf(t, "%d", scoreToAdd);
		ShowPopup(t);
	}
	void World::ShowPopup(std::string text)
	{
		_popupText.setScale(0,0);
		_popupText.setString(text);
		_showPopup=true;
	}

	const std::string &World::GetBundlePath() const
	{
		return _bundlePath;
	}
}
