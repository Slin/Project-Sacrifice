//
// Created by Nils Daumann on 07.11.15.
//

#include "Keys.h"

namespace PS
{
	Keys::Keys()
	{
		_object = new sf::Sprite();
		_object->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/arrow.png"));
		_object->setTextureRect(sf::IntRect(0.0f, 0.0f, 208, 208));
		_object->setScale(World::GetInstance()->GetScaleFactor(), World::GetInstance()->GetScaleFactor());
		_object->setOrigin(_object->getLocalBounds().width/2.0f, _object->getLocalBounds().height/2.0f);
		_object->setPosition(World::GetInstance()->GetWindow()->getSize().x*0.5f, 850.0f*World::GetInstance()->GetScaleFactor());
	}

	Keys::~Keys()
	{

	}

	void Keys::SetType(Animal::Type type)
	{
/*		if(type == Animal::Type::Mensch)
		{
			_object->setTextureRect(sf::IntRect(0.0f, 0.0f, 208, 208));
		}*/
		if(type == Animal::Type::Pig)
		{
			_object->setTextureRect(sf::IntRect(208.0f, 0.0f, 208, 208));
		}
		if(type == Animal::Type::Sheep)
		{
			_object->setTextureRect(sf::IntRect(2.0f*208.0f, 0.0f, 208, 208));
		}
		if(type == Animal::Type::Baby)
		{
			_object->setTextureRect(sf::IntRect(3.0f*208.0f, 0.0f, 208, 208));
		}
	}

	void Keys::Update(float timeStep)
	{

	}

	void Keys::Draw(sf::RenderWindow *window)
	{

	}

	void Keys::DrawLate(sf::RenderWindow *window)
	{
		window->draw(*_object);
	}
}
