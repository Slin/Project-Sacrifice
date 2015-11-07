//
// Created by Nils Daumann on 07.11.15.
//

#include "BloodParticle.h"

namespace PS
{
	BloodParticle::BloodParticle()
	{
		setFillColor(sf::Color::Red);
		setSize(sf::Vector2f(2.0f, 2.0f));
	}

	void BloodParticle::Update(float timeStep)
	{
		speed.y += timeStep*9.81f;

		move(speed);
	}
}
