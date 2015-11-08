//
// Created by Nils Daumann on 07.11.15.
//

#ifndef PROJECT_SACRIFICE_KEYS_H
#define PROJECT_SACRIFICE_KEYS_H

#include "Entity.h"
#include "Animal.h"

namespace PS
{
	class Keys : public Entity
	{
	public:
		Keys();
		~Keys();

		void Update(float timeStep);
		void Draw(sf::RenderWindow *window);
		void DrawLate(sf::RenderWindow *window);

		void SetType(Animal::Type type);

		bool _doFlash=false;
		float _doFlashTime=0;
		float _doFlashDuration=0;
	private:
		sf::Sprite *_object;

	};
}

#endif //PROJECT_SACRIFICE_KEYS_H
