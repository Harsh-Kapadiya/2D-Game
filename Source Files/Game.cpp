#include "Game.h"

// Private functions
void Game::initVariable()
{
	this->window = nullptr;

}

void Game::initWindow()
{
	this->videoMode.height = 900;
	this->videoMode.width = 1000;
	// this give use the current resolution of the desktop and set it to my game window
	// this si used to make the game more dynamic
	// this->videoMode.getDesktopMode(); 
	this ->window = new RenderWindow(this->videoMode,"My Game 1", Style::Titlebar | Style::Close | Style::Resize);
}

as
// constructor/ destructor

Game::Game()
{
	this->initVariable();
	this->initWindow();
}
Game::~Game()
{
	 delete this->window;

}


//accessor
const bool Game::running() const
{
	return this->window->isOpen();
}


// functions
// these are going to update my game logic and render the game to the screen
// everything that does not have to do anything with the drawing of thr game goes there



void Game::pollEvents()
{

	// Event pooling
	while (this->window->pollEvent(this->ev))  // SFML 3: pollEvent() gives the next event, or nothing when there are no more events
	{
		if (this->ev.is<Event::Closed>()) // event is called when we closed he windows
		{
			this->window->close();
		}
		else if (const auto* key = ev->getIf<Event::KeyPressed>()) // event trigger when any key is pressed on the keyboard
		{
			if (key->code == Keyboard::Key::Escape)  // check whether the escape key is pressed or not if yes then close the window
			{
				window.close();
			}
		}
	}
}

void Game::update()
{
	this->pollEvents();
}

void Game::render()
{
	/*
	   @return void
				- clear old frame
				- render objects
				- Display frame in window
		Render the game objects
	*/
	this->window->clear(Color::Blue); // clear old frames // 1. color::blue give the game frame to a blue color i wanna any specific color then i can use the color rgb code)
	
	
	//Drwa game objects



	this->window->display(); // display the rendered frame
}
