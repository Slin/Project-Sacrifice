//
// Created by Nils Daumann on 08.11.15.
//

#include "EndFelsen.h"

namespace PS
{
	EndFelsen::EndFelsen()
	{
		_felsen = new sf::Sprite();
		_felsen->setTexture(*TexturePool::GetInstance()->GetTexture("Fels.png"));
		_felsen->setOrigin(_felsen->getLocalBounds().width*0.5f, _felsen->getLocalBounds().height*0.5f);
		_felsen->setScale(World::GetInstance()->GetScaleFactor(), World::GetInstance()->GetScaleFactor());
		_felsen->setPosition(World::GetInstance()->GetWindow()->getSize().x*0.5f, -_felsen->getGlobalBounds().height*0.5f);
	}

	EndFelsen::~EndFelsen()
	{
		delete _felsen;
	}

	void EndFelsen::Update(float timeStep)
	{
		_felsen->move(0.0f, _fallSpeed);
		if(_felsen->getPosition().y > 800.0f)
		{
			_felsen->setPosition(_felsen->getPosition().x, 800.0f);
		}
		else
		{
			_fallSpeed += timeStep;
		}
	}

	void EndFelsen::Draw(sf::RenderWindow *window)
	{
		window->draw(*_felsen);
	}
}