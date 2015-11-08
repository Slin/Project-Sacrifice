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
	class Keys;
	class Slave;

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

		void Reset();

		static const float WORLD_TO_BOX2D;

	private:
		World();
		static World *_instance;

		bool AnyKeyPressed();
		bool IsCorrectKeyPressed();

		b2World *_physicsWorld;
		sf::RenderWindow *_window;
		float _scaleFactor;

		Priest *_priest;
		Animal *_currentAnimal;
		ParticleEmitter *_bloodParticles;
		Background *_background;
		Keys *_keys;


		bool _isKilling;
		bool _keyWasPressed;
		bool _isGameOver;
		bool _isMenu;
		bool _fuckYeah;



		sf::Sound _splatSound;
		sf::Sound _stabSound;
		sf::Sound _lostSound;
		sf::Music _music;

		sf::Font _menuFont;
		sf::Text _menuText;
		sf::Text _gameOverText;
		sf::Text _gameOverScoreText;
		sf::Text _gameOverSuccessText;
		sf::Text _gameOverFailText;

		sf::Sprite _titleSprite;

		sf::Text _scoreText;

		sf::Text _stageText;

		sf::Text _popupText;
		bool _showPopup=false;
		float _popupTimer=0;
		std::string _currentPopupString;

		void ShowPopup(std::string text);

		float _musicStep=0;
		float _nextMusicStep=0;
		float _nextSpawnStep=0;

		int _stage=1;

		int _score;
		int _sacrificeCount;
		int _sacrificeFailCount;
		void AddScore(int scoreToAdd);

		Slave* _slave;

	};
}


#endif //PROJECT_SACRIFICE_WORLD_H
