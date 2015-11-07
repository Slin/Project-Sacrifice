//
// Created by Nils Daumann on 07.11.15.
//

#ifndef PROJECT_SACRIFICE_BLOODPARTICLE_H
#define PROJECT_SACRIFICE_BLOODPARTICLE_H

#include "Entity.h"

namespace PS
{
	class BloodParticle : public sf::RectangleShape
	{
	public:
		BloodParticle();
		void Update(float timeStep);

		sf::Vector2f speed;
	};
}

#endif //PROJECT_SACRIFICE_BLOODPARTICLE_H
