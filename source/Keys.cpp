//
// Created by Nils Daumann on 07.11.15.
//

#include "Keys.h"
#include <iostream>
namespace PS
{
	Keys::Keys()
	{
		_object = new sf::Sprite();
		_object->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/arrow.png"));
		_object->setTextureRect(sf::IntRect(4.0f*208.0f, 0.0f, 208, 208));
		_object->setScale(World::GetInstance()->GetScaleFactor(), World::GetInstance()->GetScaleFactor());
		_object->setOrigin(_object->getLocalBounds().width/2.0f, _object->getLocalBounds().height/2.0f);
		_object->setPosition(World::GetInstance()->GetWindow()->getSize().x*0.5f, 850.0f*World::GetInstance()->GetScaleFactor());
		_object->setColor(sf::Color(255,255,255,0));
	}

	Keys::~Keys()
	{

	}

	void Keys::SetType(Animal::Type type)
	{
		switch(type){

			case Animal::Pig:
				_object->setTextureRect(sf::IntRect(208.0f, 0.0f, 208, 208));
				break;
			case Animal::Sheep:
				_object->setTextureRect(sf::IntRect(2.0f*208.0f, 0.0f, 208, 208));
				break;
			case Animal::Baby:
				_object->setTextureRect(sf::IntRect(3.0f*208.0f, 0.0f, 208, 208));
				break;
			case Animal::Opfer:
				_object->setTextureRect(sf::IntRect(0.0f, 0.0f, 208, 208));
				break;
			case Animal::Nothing:
				_object->setTextureRect(sf::IntRect(4.0f*208.0f, 0.0f, 208, 208));
				break;
		}

	}

	void Keys::Update(float timeStep)
	{
		if(_doFlash){
			if(_doFlashTime<.5f){
				_doFlashTime+=timeStep;
				float alpha = fabs(1-sin((_doFlashTime/.1f)));
				std::cout<<"value: "<<alpha<<std::endl;
				_object->setColor(sf::Color(255,255,255,alpha*255));
			} else {
				_doFlash=false;
				_doFlashTime=0;
				_object->setColor(sf::Color(255,255,255,255));
			}
		}

	}

	void Keys::Draw(sf::RenderWindow *window)
	{

	}

	void Keys::DrawLate(sf::RenderWindow *window)
	{
		window->draw(*_object);
	}
}
