#pragma once
#include "AirPlane.h"
#include "SFML/Graphics.hpp"
#include <string>
#include "objects.h"
#include "LoadSprites.h"

using namespace std;
class Airplane {

public:
	sf::Sprite PlaneSprite;

	Airplane(std::string imgDirectory) {
		if (!PlaneTexture.loadFromFile(imgDirectory)) {
		}
		PlaneSprite.setTexture(PlaneTexture);
		PlaneSprite.setPosition(768 / 2.0f, 1024 / 2.0f);
	}




	void CreateAirplane(sf::RenderWindow& window) {
		window.draw(PlaneSprite);
	}

	void Move(string direction) {
		if (direction == "Right") {
			PlaneSprite.move(50, 0);
		}
		else if (direction == "Left") {
			PlaneSprite.move(-50, 0);

		}
		else if (direction == "Up") {
			PlaneSprite.move(0, -50);

		}
		else if (direction == "Down") {
			PlaneSprite.move(0, 50);

		}
	}



	
	
private:
	sf::Texture PlaneTexture;
	
};
