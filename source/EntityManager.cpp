//
// Created by gclmini-06 on 07.11.2015.
//

#include "EntityManager.h"

void PS::EntityManager::draw(sf::RenderWindow *window)
{


	//draw entities
	for (Entity *entity:entities){
		//entity->draw(window);
	}


}

void PS::EntityManager::removeEntity(PS::Entity *entity)
{
		if(entity){
			entitiesToRemove.push_front(entity);
		}
}

void PS::EntityManager::addEntity(PS::Entity *entity)
{
		if(entity){
			entitiesToAdd.push_back(entity);
		}
}

void PS::EntityManager::update()
{
	//add queued entities
	for (Entity *entity:entitiesToAdd){
		entities.push_back(entity);
	}

	//update entities
	for (Entity *entity:entities){
		//entity->update();
	}

	//remove queued entities
	for (Entity *entity:entitiesToRemove){
		entities.remove(entity);
	}

}
