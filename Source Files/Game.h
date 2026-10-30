// the genral structure of the game is gonna be same as we write the main.cpp file there is only going to be some little changes according to the game which we are going to make

#pragma once
/*
class that acts as the game engine
wrapper class
*/

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
using namespace sf;
using namespace std;


class Game
{
	//sensitive game logic are written here
private:

	// variable
	//windows
	RenderWindow* window; // pointer to the window object
	VideoMode videoMode;
	// Event ev; // event object to handle the events of the game

	// Game objects
	RectangleShape enemy;


	//Private functions
	void initVariable();
	void initWindow();
	void initEnemies();





	//general game logics are written here
public:


	// constructor/ distructor
	Game();
	virtual ~Game();



	// Accessor
	const bool running() const;
	




	// function
	void pollEvents();
	void update();
	void render()
	{
		/*
		@return void
		- clear old frame
		- render objects
		- Display frame in window
		Render the game objects
		*/
		this->window->clear(); // clear old frames // 1. color::blue give the game frame to a blue color i wanna any specific color then i can use the color rgb code)


		//Draw game objects
		this->window->draw(this->enemy);

		this->window->display(); // display the rendered frame
	}

};