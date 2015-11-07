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

		void addEntity(Entity *entity);

		void removeEntity(Entity *entity);

		void update();

		void draw(sf::RenderWindow *windows);

	};
}

#endif //PROJECT_SACRIFICE_ENTITIEMANAGER_H
