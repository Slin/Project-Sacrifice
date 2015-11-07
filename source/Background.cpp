//
// Created by Nils Daumann on 07.11.15.
//

#include "Background.h"

namespace PS
{
	Background::Background()
	{
		_mainBackground = new sf::Sprite();
		_mainBackground->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/atsteken.png"));
		_mainBackground->setScale(World::GetInstance()->GetScaleFactor(), World::GetInstance()->GetScaleFactor());

		float offset = 1920.0f*World::GetInstance()->GetScaleFactor() - World::GetInstance()->GetWindow()->getSize().x;
		_mainBackground->setPosition(-offset*0.5f, 0.0f);
	}

	Background::~Background()
	{
		delete _mainBackground;
	}

	void Background::Update()
	{

	}

	void Background::Draw(sf::RenderWindow *window)
	{
		window->draw(*_mainBackground);
	}
}