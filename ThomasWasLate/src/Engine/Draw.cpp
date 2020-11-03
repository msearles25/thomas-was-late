#include "Engine.h"

void Engine::draw()
{
	// Clear the last frame (so yo don't draw ontop of the previous frame)
	m_Window.clear(sf::Color::White);

	if (!m_SplitScreen)
	{
		// Switch to our background view
		m_Window.setView(m_BGMainView);
		// Draw the backgroun onto that view
		m_Window.draw(m_BackgroundSprite);
		// Switch to the main view
		m_Window.setView(m_MainView);

		// Draw the level
		m_Window.draw(m_VALevel, &m_tilesTexture);

		// Draw Thomas and Bob
		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());

		// Draw the particle system
		if (m_PS.running())
		{
			m_Window.draw(m_PS);
		}
	}
	else
	{
		// Our split-screen view is active
		// First we draw Thomas' side of the view.
		
		// Switch to the left's background view
		m_Window.setView(m_BGLeftView);
		// Draw the background
		m_Window.draw(m_BackgroundSprite);
		// Switch to the left view
		m_Window.setView(m_LeftView);

		// Draw the level 
		m_Window.draw(m_VALevel, &m_tilesTexture);

		// Draw Thomas and Bob
		m_Window.draw(m_Bob.getSprite());
		m_Window.draw(m_Thomas.getSprite());

		// Draw the particle system
		if (m_PS.running())
		{
			m_Window.draw(m_PS);
		}

		// Now draw Bob's side

		// Switch to the right's background view
		m_Window.setView(m_BGRightView);
		// Draw the background for the right view
		m_Window.draw(m_BackgroundSprite);
		// Switch to the right view
		m_Window.setView(m_RightView);

		// Draw the level 
		m_Window.draw(m_VALevel, &m_tilesTexture);

		// Draw Thomas and Bob
		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());

		// Draw the particle system
		if (m_PS.running())
		{
			m_Window.draw(m_PS);
		}
	}

	// Draw our HUD
	// Switch to the HUD View
	m_Window.setView(m_HudView);
	m_Window.draw(m_Hud.getLevel());
	m_Window.draw(m_Hud.getTime());
	if (!m_Playing)
	{
		m_Window.draw(m_Hud.getMessage());
	}

	// Now display everything to the screen
	m_Window.display();
}