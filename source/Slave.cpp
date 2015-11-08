//
// Created by Nils Daumann on 08.11.15.
//

#include "Slave.h"

namespace PS
{
	Slave::Slave() : _animationTimer(0.0f)
	{
		_object = new sf::Sprite();
		_object->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/slave.png"));
		_object->setTextureRect(sf::IntRect(0.0f, 0.0f, 199, 318));
		_object->setOrigin(_object->getLocalBounds().width*0.5f, _object->getLocalBounds().height*0.5f);
		_object->setScale(World::GetInstance()->GetScaleFactor(), World::GetInstance()->GetScaleFactor());
		_object->setPosition(World::GetInstance()->GetWindow()->getSize().x*0.5f+200.0f*World::GetInstance()->GetScaleFactor(), 600.0f*World::GetInstance()->GetScaleFactor());

		_object2 = new sf::Sprite();
		_object2->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/slave.png"));
		_object2->setTextureRect(sf::IntRect(0.0f, 0.0f, 199, 318));
		_object2->setOrigin(_object->getLocalBounds().width*0.5f, _object->getLocalBounds().height*0.5f);
		_object2->setScale(-World::GetInstance()->GetScaleFactor(), World::GetInstance()->GetScaleFactor());
		_object2->setPosition(World::GetInstance()->GetWindow()->getSize().x*0.5f-200.0f*World::GetInstance()->GetScaleFactor(), 600.0f*World::GetInstance()->GetScaleFactor());
	}

	Slave::~Slave()
	{
		delete _object;
	}

	void Slave::Draw(sf::RenderWindow *window)
	{

	}

	void Slave::DrawLate(sf::RenderWindow *window)
	{
		window->draw(*_object);
		window->draw(*_object2);
	}

	void Slave::Update(float timeStep)
	{
		_animationTimer += timeStep;

		int image = ((int)(_animationTimer/0.1f))%5;
		if(image > 2)
		{
			image = 5-image;
		}

		_object->setTextureRect(sf::IntRect(image*199, 0.0f, 199, 318));
		_object2->setTextureRect(sf::IntRect(image*199, 0.0f, 199, 318));
	}
}
