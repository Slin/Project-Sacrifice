//
// Created by gclmini-06 on 07.11.2015.
//

#ifndef PROJECT_SACRIFICE_ENTITIEMANAGER_H
#define PROJECT_SACRIFICE_ENTITIEMANAGER_H

#include <SFML/Main.hpp>
#include <list>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace std;
namespace PS
{
	class Entity;
	class EntityManager
	{
	private:
		EntityManager();
		static EntityManager *_instance;

		list<Entity*> _entities;
		list<Entity*> _entitiesToAdd;
		list<Entity*> _entitiesToRemove;

	public:
		void AddEntity(Entity *entity);
		void RemoveEntity(Entity *entity);
		void Update(float timeStep);
		void Draw(sf::RenderWindow *windows);
		void RemoveAllEntities();

		static EntityManager *GetInstance();
	};
}

#endif //PROJECT_SACRIFICE_ENTITIEMANAGER_H
