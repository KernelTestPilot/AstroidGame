#include "SFML/Graphics.hpp"
#include <string>
#include "AirPlane.h"
#include "LoadSprites.h"
#include "Objects.h"
#include <iostream>
#include <vector>
#include "LoadCoin.h"
#include <sstream>
#include <cstdlib>

using namespace sf;
using namespace std;



int main() {
	//Start settings
	srand(time(NULL));
	int LevelGUI = 0;
	int test = 3;
	int AstroidSpawntimer = 0;
	int Astroidspawntimderforcoin = 0;
	int CoinSpawntimer = 0;
	int score = 0;
	int coinscore = 0;
	int level =150;
	sf::Clock clock;
	//Game settings
	const string windowTitle = "SFML Console Application";
	const VideoMode videoMode = VideoMode(768, 1024);
	const Color backgroundColor = Color::Black;
	const unsigned int FRAMERATE_LIMIT = 60;
	RenderWindow window(videoMode, windowTitle, Style::Titlebar | Style::Close);
	window.setFramerateLimit(FRAMERATE_LIMIT);


	//Våra flygplan
	Airplane NewAirplane("PlaneSprite.psd");

	//Våra astroider
	sf::Texture AstroidTexture;
	AstroidTexture.loadFromFile("AsteroidSprite.psd");

	//vectorer
	std::vector<LoadSprites> AstroidVec;


	//checkin le memmory adress
	std::cout << &AstroidTexture << std::endl;
	LoadSprites Loadsprite(&AstroidTexture);
	LoadSprites Astroid3(&AstroidTexture);

	//AstroidVec.push_back(Loadsprite);
	//AstroidVec.push_back(Astroid3);
	//Vi gör en till Astroidvec som ramlar ner när man tar upp en coin
	std::vector<LoadSprites> AstroidForCoins;
	LoadSprites Astroid2(&AstroidTexture);
	std::cout << &AstroidTexture << std::endl;



	//AstroidVec.push_back(Loadsprite);




	//Vårat coin som ska ge lycka i spelet
	sf::Texture CoinTexture;
	CoinTexture.loadFromFile("CoinSprite.psd");
	std::vector<LoadCoin> CoinVec;

	std::cout << &CoinTexture << std::endl;
	LoadCoin Coin(&CoinTexture);
	//CoinVec.push_back(Coin);

	//Set font for GAME
	sf::Font August;
	August.loadFromFile("Hey August.ttf");
	
	//Header gui
	sf::Text text("Dahlbergs Astroid game", August);
	text.setCharacterSize(30);
	text.setPosition({10,10});

	//STrings som kan tas bort och ersättas
	std::ostringstream LiveScore;
	std::ostringstream SssCoinscore;
	//Start gui
	LiveScore << "Score:" << score;
	SssCoinscore << "Score:" << score;


	//Score settings
	sf::Text YourScore;
	YourScore.setCharacterSize(30);
	YourScore.setPosition({ 10,50 });
	YourScore.setFont(August);
	YourScore.setString(LiveScore.str());

	sf::Text Coinscore;
	Coinscore.setCharacterSize(30);
	Coinscore.setPosition({ 10,50 });
	Coinscore.setFont(August);


	//Använd int score för våran livescore.
	//Coinscore settings

	
	while (window.isOpen()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			//std::cout << "left key pressed" << std::endl;
			NewAirplane.Move("Left");
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			//std::cout << "Right key pressed" << std::endl;
			NewAirplane.Move("Right");
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{
			//std::cout << "Up key pressed" << std::endl;
			NewAirplane.Move("Up");
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			//std::cout << "Down key pressed" << std::endl;
			NewAirplane.Move("Down");
		}


		Event event;
		while (window.pollEvent(event)) {


			if (event.type == Event::Closed) {
				window.close();
			}
		}
		window.clear(backgroundColor);
		//coin SPAWNTIMER
		
		if (CoinSpawntimer < 250) CoinSpawntimer++;
		if (CoinSpawntimer >= 250){
			Coin.SetSpawnPos(window);
			CoinVec.push_back(Coin);
			CoinSpawntimer = 0;
		}


		//coin move
		for (size_t i = 0; i < CoinVec.size(); i++) {
			CoinVec[i].Move();
		}

		//Clock and tim>
		
		sf::Time elapsed = clock.getElapsedTime();
		if (elapsed.asSeconds() >= 10) {
			level = level - 30; 
			clock.restart();
		}
		
		//ASTROID SPAWNTIME
		if (AstroidSpawntimer < level) AstroidSpawntimer++;
		if (AstroidSpawntimer >= level) {
			Loadsprite.SetSpawnPos(window);

			AstroidVec.push_back(Loadsprite);
			
		
			
			AstroidSpawntimer = 0;
		}
		
		//Set movementspeed astroid.
		for (size_t i = 0; i < AstroidVec.size(); i++) {
			AstroidVec[i].Move(test);
			//std::cout <<test;
			
		}
		
		//Astroid coin movement
		for (size_t i = 0; i < AstroidForCoins.size(); i++) {
			AstroidForCoins[i].Move(1.f);
		}

		
		//check collide Astroids
		for (size_t i = 0; i < AstroidVec.size(); i++) {
			//AstroidVec[i].sprite.getGlobalBounds();
			if (NewAirplane.PlaneSprite.getGlobalBounds().intersects(AstroidVec[i].sprite.getGlobalBounds())) {
				//DU ÄR TRÄFFAD, DO UR CODE HERE:

				//std::cout << "LLOL DEAD";
				//vad ska vi göra när de är gameover
				//return 0;
			}
			//Still alive, do nothing..
		}
		
		
		
		//Check collide our astroids from coins
		for (size_t i = 0; i < AstroidForCoins.size(); i++) {
			//AstroidVec[i].sprite.getGlobalBounds();
			if (NewAirplane.PlaneSprite.getGlobalBounds().intersects(AstroidForCoins[i].sprite.getGlobalBounds())) {
				//DU ÄR TRÄFFAD, DO UR CODE HERE:

				//std::cout << "LLOL DEAD";
				//vad ska vi göra när de är gameover
				//return 0;
			}
			//Still alive, do nothing..
		}


		//check collide Coins
		for (size_t i = 0; i < CoinVec.size(); i++) {
			if (NewAirplane.PlaneSprite.getGlobalBounds().intersects(CoinVec[i].coinsprite.getGlobalBounds())) {
				Astroidspawntimderforcoin++;
				if (Astroidspawntimderforcoin > 0) {

					//tar bort coinsen som plockas upp
					CoinVec.erase(CoinVec.begin() + i);
					//coinscore + 10;
				

					//Hur många extra astroider vill vi spawna när vi tar en coin?
					Astroid2.SetSpawnPos(window);
					AstroidForCoins.push_back(Astroid2);
					Astroidspawntimderforcoin = 0;
				

					

				}
			
			}
		}
			//Still alive, do nothing..
		
		//Check coin passsing by
		for (size_t i = 0; i < CoinVec.size(); i++) {

			if (CoinVec[i].coinsprite.getPosition().y > window.getSize().y) {
				return 0;
			}
		}


		//Calc ur score
		for (size_t i = 0; i < AstroidVec.size(); i++) {

			if (AstroidVec[i].sprite.getPosition().y > window.getSize().y) {
				//Nu är dem utanför skärmen, då kan vi ta bort dem och calc score
				score++;
				//reset livescore, så vi inte tar upp hela skärmen
				LiveScore.str("");
				
				//Uppdaterar scoren i guin
				LiveScore << "Score:" << score;
				YourScore.setString(LiveScore.str());
				//std::cout << score;
				AstroidVec.erase(AstroidVec.begin() + i);

			}
		}

		


		// HERE WE DO THE DRAWING  OF OUR COOL MODELS
		window.clear();
		NewAirplane.CreateAirplane(window);
		for (size_t i = 0; i < AstroidVec.size(); i++) {
			AstroidVec[i].draw(window);
		}

		for (size_t i = 0; i < AstroidForCoins.size(); i++) {
			AstroidForCoins[i].draw(window);
		}

		for (size_t i = 0; i < CoinVec.size(); i++) {
			CoinVec[i].draw(window);
		}

		//Draw´gui
		window.draw(YourScore);
		window.draw(text);
		window.draw(Coinscore);
		window.display();
	}
	return 0;
}