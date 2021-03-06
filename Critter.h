#pragma once


//---------------------------------------------------------------------------------------
// Included Libraries
//---------------------------------------------------------------------------------------
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
//---------------------------------------------------------------------------------------
// End Libraries
//---------------------------------------------------------------------------------------



class Critter
{

	//---------------------------------------------------------------------------------------
	// Behaviour
	//---------------------------------------------------------------------------------------

public:

	// Constuctor
	Critter();

	// Render the Critter to the target
	void Draw(sf::RenderTarget& _target);


	//Process input on the Critter
	void Input(sf::Event _gameEvent);

	//getter for pending score
	int GetPendingScore();

	//Clear the pending score
	void ClearPendingScore();

	// Set the critter type
	void Setup(std::string _texturefile, int _pointValue);


	//---------------------------------------------------------------------------------------
	// End Behaviour
	//---------------------------------------------------------------------------------------





	//---------------------------------------------------------------------------------------
	// Data
	//---------------------------------------------------------------------------------------

private:

	sf::Sprite m_sprite;
	sf::Texture m_texture;
	bool m_alive;
	sf::Sound m_deathSound;
	sf::SoundBuffer m_deathBuffer;
	int m_pendingScore;
	int m_scoreValue;


	//---------------------------------------------------------------------------------------
	// End Data
	//---------------------------------------------------------------------------------------


};    // End Critter class