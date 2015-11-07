//
// Created by gclmini-06 on 07.11.2015.
//

#ifndef PROJECT_SACRIFICE_ENTITIEMANAGER_H
#define PROJECT_SACRIFICE_ENTITIEMANAGER_H

#include <SFML/Main.hpp>
#include "Entity.h"
#include <list>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace std;
namespace PS
{
	class EntityManager
	{
	private:
		list<Entity*> entities;
		list<Entity*> entitiesToAdd;
		list<Entity*> entitiesToRemove;
	public:
		EntityManager();

		void AddEntity(Entity *entity);

		void RemoveEntity(Entity *entity);

		void Update();

		void Draw(sf::RenderWindow *windows);

	};
}

#endif //PROJECT_SACRIFICE_ENTITIEMANAGER_H
