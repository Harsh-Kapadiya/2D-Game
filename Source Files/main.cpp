#include<iostream>
#include "Game.h" 
// all the include files present in the first git commit is now moved to the game.h

using namespace std;
using namespace sf;

int main() {

	//init game engine
	Game game;

	// Game loops / Game rules
	//game loop is always a while loop but the loop is not gonna be true as we also wanna quit the game so
	while (game.running()) // check whether my game windows is still open or not
	{

		//Update the game
		game.update();

		// Render States
		game.render();

	}
	// End of application/ game-Logic
	return 0;
}