#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>


using namespace std;
using namespace sf;

int main() {

	// windows rules / windows stuff
	RenderWindow window(VideoMode({640, 480}), "My first 2D - Game ", Style::Titlebar | Style::Close | Style::Resize);

	// Game loops / Game rules
	//game loop is always a while loop but the loop is not gonna be true as we also wanna quit the game so
	while (window.isOpen()) // check whether my game windows is still open or not
	{
		// Event pooling
		while (const optional ev = window.pollEvent())  // SFML 3: pollEvent() gives the next event, or nothing when there are no more events
		{
			if (ev->is<Event::Closed>()) // event is called when we closed he windows
			{
				window.close();
			}
			else if (const auto* key = ev->getIf<Event::KeyPressed>()) // event trigger when any key is pressed on the keyboard
			{
				if (key->code == Keyboard::Key::Escape)  // check whether the escape key is pressed or not if yes then close the window
				{
					window.close();
				}
			}
		}

		//Update the game

		// Render States 
		// between clear and display all the drawing or the gui part comes under these 2 sections only
		window.clear(Color::Blue); // clear old frames // 1. color::blue give the game frame to a blue color i wanna any specific color then i can use the color rgb code


		// Draw the game


		window.display(); // tell app that windows done drawing 

	}
	// End of application/ game
	return 0;
}