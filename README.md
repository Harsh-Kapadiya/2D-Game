# 2D-Game

precompiler header -> in this we already add the header so that we dont have to include them again in the main.cpp file as the slows down your game

	// this give use the current resolution of the desktop and set it to my game window
	// this si used to make the game more dynamic
	// this->videoMode.getDesktopMode(); 

RenderWindow window(VideoMode({1000, 900}), " GAME - 1 ", Style::Titlebar | Style::Close | Style::Resize);
this line is not required to write in the main file as well write this in the game.cpp file



		// between clear and display all the drawing or the gui part comes under these 2 sections only
		//window.clear(Color::Blue); // clear old frames // 1. color::blue give the game frame to a blue color i wanna any specific color then i can use the color rgb code

window.display(); // tell app that windows done drawing 


in winodw.clear() black is the default color