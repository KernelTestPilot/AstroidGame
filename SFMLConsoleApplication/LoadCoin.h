#pragma once
#include "AirPlane.h"
#include "SFML/Graphics.hpp"
#include <string>
#include "objects.h"
#include "Objects.h"
#include "Airplane.h"
class LoadCoin
{
public:
	sf::Sprite coinsprite;

	LoadCoin(sf::Texture* CoinTexture) {
		coinsprite.setTexture(*CoinTexture);


	}

	void draw(sf::RenderWindow& window) {
		window.draw(coinsprite);
	}

	void SetSpawnPos(sf::RenderWindow& window) {
		coinsprite.setPosition((rand() % int(window.getSize().x)), 0.f);

	}

	void Move() {
		coinsprite.move(0.f, 5.f);

	}

private:

};

