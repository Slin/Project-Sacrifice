//
// Created by Nils Daumann on 07.11.15.
//

#ifndef PROJECT_SACRIFICE_ANIMAL_H
#define PROJECT_SACRIFICE_ANIMAL_H

#include "Entity.h"

namespace PS
{
	class Animal : public Entity
	{
	public:
		enum Type
		{
			Pig,
			Sheep,
			Baby,
			Opfer
		};

		Animal(Type type);
		~Animal();

		void Update(float timeStep);
		void Draw(sf::RenderWindow *window);

		void Kill(bool fuckYeah);
		Type GetType()
		{
			return _type;
		}

	private:
		enum State
		{
			Alive,
			Waiting,
			Dead
		};

		State _state;
		Type _type;

		bool _isMovingUp;

		sf::Sprite *_object;
		sf::Sprite *_leftHalf;
		sf::Sprite *_rightHalf;

		b2Body *_leftHalfBody;
		b2Body *_rightHalfBody;
	};
}


#endif //PROJECT_SACRIFICE_ANIMAL_H
