//
// Created by Nils Daumann on 06.11.15.
//

#ifndef PROJECT_SACRIFICE_ENTITY_H
#define PROJECT_SACRIFICE_ENTITY_H

#include "World.h"

namespace PS
{
	class Entity
	{
	public:
		virtual void Update() = 0;
		virtual void Draw(sf::RenderWindow *window) = 0;
	};
}


#endif //PROJECT_SACRIFICE_ENTITY_H
