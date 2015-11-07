//
// Created by Nils Daumann on 07.11.15.
//

#include "ParticleEmitter.h"

namespace PS
{
	ParticleEmitter::ParticleEmitter()
	{
		_currentParticle = 0;
		memset(_particles, 0, sizeof(_particles));
	}

	ParticleEmitter::~ParticleEmitter()
	{

	}

	void ParticleEmitter::Update(float timeStep)
	{
		for(int i = 0; i < 100; i++)
		{
			_particles[_currentParticle] = new BloodParticle();
			_particles[_currentParticle]->setPosition(World::GetInstance()->GetWindow()->getSize().x*0.5f-100.0f, 200.0f*World::GetInstance()->GetScaleFactor());
			_particles[_currentParticle]->speed = sf::Vector2f((rand()/(float)RAND_MAX)*10.0f-5.0f, -(rand()/(float)RAND_MAX)*10.0f+5.0f);

			_currentParticle += 1;
			if(_currentParticle >= 10000)
				_currentParticle = 0;
		}

		for(int i = 0; i < 10000; i++)
		{
			if(!_particles[i])
				continue;

			_particles[i]->Update(timeStep);
		}
	}

	void ParticleEmitter::Draw(sf::RenderWindow *window)
	{
		for(int i = 0; i < 10000; i++)
		{
			if(!_particles[i])
				continue;

			window->draw(*_particles[i]);
		}
	}
}
