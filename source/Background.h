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

		void Update(float timeStep);
		void Draw(sf::RenderWindow *window);
		void DrawLate(sf::RenderWindow *window);

	private:
		sf::Sprite *_mainBackground;
		sf::Sprite *_altar;
	};
}

#endif //PROJECT_SACRIFICE_BACKGROUND_H
