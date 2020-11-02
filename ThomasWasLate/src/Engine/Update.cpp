#include <sstream>
#include "Engine.h"

void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired)
	{
		// Spawn Thomas and Bob
		m_Thomas.spawn(sf::Vector2f(0, 0), GRAVITY);
		m_Bob.spawn(sf::Vector2f(0, 100), GRAVITY);

		// Make sure our spawn is only called one time
		m_TimeRemaining = 10;
		m_NewLevelRequired = false;
	}

	if (m_Playing)
	{
		// Count down the amount of time the player has left
		m_TimeRemaining -= dtAsSeconds;

		// Have Thomas and Bob run out of time?
		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = true;
		}
	}
}