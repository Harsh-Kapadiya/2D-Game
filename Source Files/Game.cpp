#include "Game.h"
using namespace sf;
using namespace std;

// Private functions
void Game::initVariable()
{
	this->window = nullptr;

}

void Game::initWindow()
{
	this->videoMode.size = { 1000, 800 }; // this is the default resolution of the game window
	// this give use the current resolution of the desktop and set it to my game window
	// this si used to make the game more dynamic
	// this->videoMode.getDesktopMode(); 
	this->window = new RenderWindow(this->videoMode, "My Game 1", Style::Titlebar | Style::Close | Style::Resize);

	this->window->setFramerateLimit(144);

}

void Game::initEnemies()
{
	// this->enemy.setPosition();  // the default position is (0,0)
	this->enemy.setSize(Vector2f(100.f, 100.f));
	this->enemy.setFillColor(Color::Cyan);
	this->enemy.setOutlineColor(Color::Green);
	this->enemy.setOutlineThickness(1.f);
}

// constructor/ destructor

Game::Game()
{
	this->initVariable();
	this->initWindow();
	this->initEnemies();
}
Game::~Game()
{
	delete this->window;

}


//accessor
const bool Game::running() const {
	return this->window->isOpen();
}


// functions
// these are going to update my game logic and render the game to the screen
// everything that does not have to do anything with the drawing of thr game goes there



void Game::pollEvents()
{

	// Event pooling
	while (const std::optional<Event> event = this->window->pollEvent())  // SFML 3: pollEvent() gives the next event, or nothing when there are no more events
	{
		if (event->is<Event::Closed>()) // event is called when we closed he windows
		{
			this->window->close();
		}
		else if (const auto* key = event->getIf<Event::KeyPressed>()) // event trigger when any key is pressed on the keyboard
		{
			if (key->code == Keyboard::Key::Escape)  // check whether the escape key is pressed or not if yes then close the window
			{
				this->window->close();
			}
		}
	}
}

void Game::update()
{
	this->pollEvents();
}