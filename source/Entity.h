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
		Entity()
		{
			EntityManager::GetInstance()->AddEntity(this);
		}
		~Entity()
		{
			EntityManager::GetInstance()->RemoveEntity(this);
		}

		virtual void Update(float timeStep) = 0;
		virtual void Draw(sf::RenderWindow *window) = 0;
		virtual void DrawLate(sf::RenderWindow *window)
		{

		};
	};
}


#endif //PROJECT_SACRIFICE_ENTITY_H
