//
// Created by Nils Daumann on 07.11.15.
//

#include "Background.h"

namespace PS
{
	Background::Background()
	{
		_mainBackground = new sf::Sprite();
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