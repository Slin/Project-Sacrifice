//
// Created by Nils Daumann on 07.11.15.
//

#include "Priest.h"

namespace PS
{
	Priest::Priest()
	{
		_animate = false;
		_animationTimer = 0.0f;

		_object = new sf::Sprite();
		_object->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/priester.png"));
		_object->setScale(World::GetInstance()->GetScaleFactor(), World::GetInstance()->GetScaleFactor());
		_object->setTextureRect(sf::IntRect(0.0f, 0.0f, 194, 361));
		_object->setOrigin(_object->getGlobalBounds().width*0.5f, _object->getGlobalBounds().height*0.5f);
		_object->setPosition(World::GetInstance()->GetWindow()->getSize().x*0.5f, 485.0f*World::GetInstance()->GetScaleFactor());
	}

	Priest::~Priest()
	{
		delete _object;
	}

	void Priest::Update(float timeStep)
	{
		if(_animate)
		{
			_animationTimer += timeStep;
			int image = _animationTimer/0.03f;
			if(image > 3)
			{
				image = 6-image;

				if(image == 0)
				{
					_animationTimer = 0.0f;
					_animate = false;
				}
			}

			_object->setTextureRect(sf::IntRect(image*194, 0.0f, 194, 361));
		}
	}

	void Priest::Animate()
	{
		_animate = true;
	}

	void Priest::Draw(sf::RenderWindow *window)
	{
		window->draw(*_object);
	}
}
