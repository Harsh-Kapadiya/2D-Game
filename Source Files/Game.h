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

class Game
{
	//sensitive game logic are written here
private:

	// variable
	//windows
	RenderWindow* window; // pointer to the window object
	VideoMode videoMode;
	Event ev; // event object to handle the events of the game

	void initVariable();
	void initWindow();



	//general game logics are written here
public:


	// constructor/ distructor
	Game();
	virtual ~Game();



	// Accessor
	const bool running() const;
	const bool Game :: running() const {
		return this->window->isOpen();
	}




	// function
	void pollEvents();
	void update();
	void render();
		
};