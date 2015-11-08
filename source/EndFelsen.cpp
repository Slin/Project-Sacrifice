//
// Created by Nils Daumann on 08.11.15.
//

#include "EndFelsen.h"

namespace PS
{
	EndFelsen::EndFelsen() : _fallSpeed(20.0f), _BAM(nullptr)
	{
		_felsen = new sf::Sprite();
		_felsen->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/Fels.png"));
		_felsen->setOrigin(_felsen->getLocalBounds().width*0.5f, _felsen->getLocalBounds().height*0.5f);
		_felsen->setScale(World::GetInstance()->GetScaleFactor(), World::GetInstance()->GetScaleFactor());
		_felsen->setPosition(World::GetInstance()->GetWindow()->getSize().x*0.5f, -_felsen->getGlobalBounds().height*0.5f);
	}

	EndFelsen::~EndFelsen()
	{
		delete _felsen;

		if(_BAM)
			delete _BAM;
	}

	void EndFelsen::Update(float timeStep)
	{
		_felsen->move(0.0f, _fallSpeed);
		if(_felsen->getPosition().y > 350.0f)
		{
			_felsen->setPosition(_felsen->getPosition().x, 350.0f);

			if(!_BAM)
			{
				_BAM = new sf::Sprite();
				_BAM->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/Risse_Blut.png"));
				_BAM->setOrigin(_BAM->getLocalBounds().width*0.5f, _BAM->getLocalBounds().height*0.5f);
				_BAM->setScale(World::GetInstance()->GetScaleFactor(), World::GetInstance()->GetScaleFactor());
				_BAM->setPosition(World::GetInstance()->GetWindow()->getSize().x*0.5f, World::GetInstance()->GetWindow()->getSize().y*0.5f);
			}
		}
		else
		{
			_fallSpeed += timeStep*9.81f;
		}
	}

	void EndFelsen::Draw(sf::RenderWindow *window)
	{
	}

	void EndFelsen::DrawLate(sf::RenderWindow *window)
	{
		window->draw(*_felsen);

		if(_BAM)
			window->draw(*_BAM);
	}
}