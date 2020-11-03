#include <sstream>
#include "Engine.h"

void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired)
	{
		// Load a new level
		loadLevel();
	}

	if (m_Playing)
	{
		// Update Thomas each frame
		m_Thomas.update(dtAsSeconds);
		// Update Bob each frame
		m_Bob.update(dtAsSeconds);
		
		// Detect collisions and see if the characters have reached the 
		// goal tile. 
		if (detectCollisions(m_Thomas) && detectCollisions(m_Bob))
		{
			// New level is required, both reached the end
			m_NewLevelRequired = true;
			
		}
		else
		{
			// Run bobs collision detection 
			detectCollisions(m_Bob);
		}

		// Let Bob and Thomas jump on each others heads
		if (m_Bob.getFeet().intersects(m_Thomas.getHead()))
		{
			m_Bob.stopFalling(m_Thomas.getHead().top);
		}
		else if (m_Thomas.getFeet().intersects(m_Bob.getHead()))
		{
			m_Thomas.stopFalling(m_Bob.getHead().top);
		}

		// Count down the amount of time the player has left
		m_TimeRemaining -= dtAsSeconds;

		// Have Thomas and Bob run out of time?
		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = true;
		}
	}

	// Set the appropriate view around the appropriate character
	if (m_SplitScreen)
	{
		m_LeftView.setCenter(m_Thomas.getCenter());
		m_RightView.setCenter(m_Bob.getCenter());
	}
	else
	{
		// Center the fullscreen around the appropriate character
		if (m_Character1)
		{
			m_MainView.setCenter(m_Thomas.getCenter());
		}
		else
		{
			m_MainView.setCenter(m_Bob.getCenter());
		}
	}
}