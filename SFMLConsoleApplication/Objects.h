#pragma once


#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include <string>
#include "Game.cpp"
#include <vector>
#include <iostream>
#include "LoadSprites.h"

using namespace sf;
using namespace std;




class Astroid {
public:
	Astroid() {
		

	}







/*
	void SetSpawnPos(sf::RenderWindow& window) {
		sf::Sprite(AstroidSprite).setPosition((rand() % int(window.getSize().x)), 0.f);

	}
		//for (size_t i = 0; i < sprites.size(); i++) {
			//sprites[i].setPosition((rand() % int(window.getSize().x)), 0.f);
		//}
	}
	
*/
	/*
void Move() {
	AstroidSprite.move(0.f, 5.f);


		}

*/
	


	// Return vart astroiden är, kolla om den krockar med intersect metoden
	sf::FloatRect GetGlobalBounce() {
		return AstroidSprite.getGlobalBounds();

	}
	
private:
	sf::Sprite AstroidSprite;
};

