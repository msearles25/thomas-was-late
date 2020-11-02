#include <sstream>
#include "Engine.h"

void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired)
	{
		// Spawn Thomas and Bob
		m_Thomas.spawn(sf::Vector2f(0, 0), GRAVITY);
		m_Bob.spawn(sf::Vector2f(100, 0), GRAVITY);

		// Make sure our spawn is only called one time
		m_TimeRemaining = 10;
		m_NewLevelRequired = false;
	}

	if (m_Playing)
	{
		// Update Thomas each frame
		m_Thomas.update(dtAsSeconds);
		// Update Bob each frame
		m_Bob.update(dtAsSeconds);
		
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