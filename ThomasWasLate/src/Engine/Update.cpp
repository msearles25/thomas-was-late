#include <sstream>
#include "Engine.h"

void Engine::update(float dtAsSeconds)
{
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