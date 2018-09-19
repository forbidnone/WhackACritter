//---------------------------------------------------------------------------------------
// Project Includes
//---------------------------------------------------------------------------------------


#include  "Critter.h"


//---------------------------------------------------------------------------------------
// End Project Includes
//---------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------
// Included Libraries
//---------------------------------------------------------------------------------------
#include <cstdlib>
//---------------------------------------------------------------------------------------
// End Libraries
//---------------------------------------------------------------------------------------





Critter::Critter()
// Initialisation list
	: m_sprite()
	, m_texture()
	, m_alive(true)
	, m_deathSound()
	, m_deathBuffer()
	, m_pendingScore(0)
	, m_scoreValue(1)
{

	
	// Set up the death sound
	m_deathBuffer.loadFromFile("audio/buttonclick.ogg");
	m_deathSound.setBuffer(m_deathBuffer);


}	// Close Critter function




void Critter::Draw(sf::RenderTarget& _target)
{

	if (m_alive)
	{

		// Only draw sprites if they are alive
		_target.draw(m_sprite);
	
	}
}



void Critter::Input(sf::Event _gameEvent)
{

	//Only handle input if alive
	if (m_alive)
	{


		// Check if this event is a click
		if (_gameEvent.type == sf::Event::MouseButtonPressed)
		{

			// Did they click on this Critter?
			if (m_sprite.getGlobalBounds().contains(_gameEvent.mouseButton.x, _gameEvent.mouseButton.y))
			{

				//They Clicker it!

				//Critter dies
				m_alive = false;



				// Play the death sound
				m_deathSound.play();


				
				//Add to pending score
				m_pendingScore += m_scoreValue;


			}


		} // End event if statement

	} // End if Alive statement

}


int Critter::GetPendingScore()
{
	return m_pendingScore;
}


void Critter::ClearPendingScore()
{
	m_pendingScore = 0;
}


void Critter::Setup(std::string _texturefile, int _pointValue)
{

	// Set up the sprite
	m_texture.loadFromFile(_texturefile);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(rand() % sf::VideoMode::getDesktopMode().width,
		rand() % sf::VideoMode::getDesktopMode().height);



	m_scoreValue = _pointValue;
}