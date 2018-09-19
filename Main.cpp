//---------------------------------------------------------------------------------------
// Included Libraries
//---------------------------------------------------------------------------------------
#include <SFML/Graphics.hpp>
#include <cstdlib> // Gives access to seed functions
#include <ctime> // Gives access to time functions
#include <string> // Gives access to string functions
//---------------------------------------------------------------------------------------
// End Libraries
//---------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------
// Project Includes
//---------------------------------------------------------------------------------------

#include "Critter.h"

//---------------------------------------------------------------------------------------
// End Project Includes
//---------------------------------------------------------------------------------------


int main()
{


	//-----------------------------------------------------------------------------------
	// Game Setup
	// ----------------------------------------------------------------------------------


	// Make a variable called gameWindow of type RenderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Whack-A-Critter",
		sf::Style::Titlebar | sf::Style::Close);



	//Timer functionallity
	sf::Clock gameClock;


	// Seed out random number generator
	srand(time(NULL));


	// Create an instance of our Critter class
	Critter hippo;


	//Game Font
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainFont.ttf");


	// Score tracking
	int score = 0;
	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setCharacterSize(50);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(50, 50);

	//----------------------------------------------------------------------------------
	//End game Setup
	//----------------------------------------------------------------------------------





	//-----------------------------------------------------------------------------------
	// Game Loop
	//-----------------------------------------------------------------------------------
	// Runs every frame until the game window is closed


	while (gameWindow.isOpen())
	{


		//-------------------------------------------------------------------------------
		//Input
		//-------------------------------------------------------------------------------


		sf::Event gameEvent;

		while (gameWindow.pollEvent(gameEvent))
		{

			// Process input on critters
			hippo.Input(gameEvent);

			if (gameEvent.type == sf::Event::Closed)
			{
				gameWindow.close();
			}// end if(closed)


		} // End while 



		//-------------------------------------------------------------------------------
		// End Input
		//-------------------------------------------------------------------------------




		//-------------------------------------------------------------------------------
		// Update
		//-------------------------------------------------------------------------------



		sf::Time frameTime = gameClock.restart();


		//See if there is any pending score
		score += hippo.GetPendingScore();
		hippo.ClearPendingScore();
		scoreText.setString("Score: " + std::to_string(score));


		//-------------------------------------------------------------------------------
		// End Update
		//-------------------------------------------------------------------------------




		//-------------------------------------------------------------------------------
		// Draw
		//-------------------------------------------------------------------------------


		// Clear the window to a single colour
		gameWindow.clear(sf::Color::Black);



		// Draw Everything

		hippo.Draw(gameWindow);
		gameWindow.draw(scoreText);




		// Display the window contents on the screen
		gameWindow.display();




		//-------------------------------------------------------------------------------
		//End Draw
		//-------------------------------------------------------------------------------



	} //End game while loop

	//-----------------------------------------------------------------------------------
	// End Game Loop
	//-----------------------------------------------------------------------------------

	return 0;
} // End main function
