#pragma once
#include "AirPlane.h"
#include "SFML/Graphics.hpp"
#include <string>
#include "objects.h"
#include "Objects.h"
#include "Airplane.h"
using namespace std;

class LoadSprites{

public:
	sf::Sprite sprite;


	LoadSprites(sf::Texture* texture) {
		
		sprite.setTexture(*texture);
		

	}

	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}

	void SetSpawnPos(sf::RenderWindow& window) {
		sprite.setPosition((rand() % int(window.getSize().x)), 0.f);
		
	}
	//int speed=5
	void Move(float movespeed) {
		
		sprite.move(0.f, movespeed);
	}
	

	
	
private:
	float movespeed;
};

