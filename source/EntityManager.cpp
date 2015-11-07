//
// Created by gclmini-06 on 07.11.2015.
//

#include "EntityManager.h"

void PS::EntityManager::Draw(sf::RenderWindow *window)
{


	//draw entities
	for (Entity *entity:entities){
		entity->Draw(window);
	}


}

void PS::EntityManager::RemoveEntity(PS::Entity *entity)
{
		if(entity){
			entitiesToRemove.push_front(entity);
		}
}

void PS::EntityManager::AddEntity(PS::Entity *entity)
{
		if(entity){
			entitiesToAdd.push_back(entity);
		}
}

void PS::EntityManager::Update()
{
	//add queued entities
	for (Entity *entity:entitiesToAdd){
		entities.push_back(entity);
	}

	//update entities
	for (Entity *entity:entities){
		entity->Update();
	}

	//remove queued entities
	for (Entity *entity:entitiesToRemove){
		entities.remove(entity);
	}

}
