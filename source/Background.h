//
// Created by Nils Daumann on 07.11.15.
//

#ifndef PROJECT_SACRIFICE_BACKGROUND_H
#define PROJECT_SACRIFICE_BACKGROUND_H

#include "Entity.h"

namespace PS
{
	class Background : public Entity
	{
	public:
		Background();
		~Background();

		void Update();
		void Draw(sf::RenderWindow *window);

	private:
		sf::Sprite *_mainBackground;
	};
}

#endif //PROJECT_SACRIFICE_BACKGROUND_H
