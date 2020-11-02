#include "Engine.h"

Engine::Engine()
{
	// Get our screen resolution
	// and create an SFML window and a view
	sf::Vector2f resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;

	m_Window.create(sf::VideoMode(resolution.x, resolution.y), "Thomas was late");

	// Initialize the fullscreen view
	m_MainView.setSize(resolution);
	m_HudView.reset(sf::FloatRect(0, 0, resolution.x, resolution.y));

	// Initialize the split-screen view
	m_LeftView.setViewport(sf::FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_RightView.setViewport(sf::FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	m_BGLeftView.setViewport(sf::FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_BGRightView.setViewport(sf::FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	m_BackgroundTexture = TextureHolder::GetTexture("Content/graphics/background.png");

	// Associate our texture with the sprite
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	// Load the texture for the background vertex array
	m_tilesTexture = TextureHolder::GetTexture("Content/graphics/tiles_sheet.png");
}

void Engine::run()
{
	// Timing for everything
	sf::Clock clock;

	while (m_Window.isOpen())
	{
		sf::Time dt{ clock.restart() };
		// update the total game time
		m_GameTimeTotal += dt;
		// Make a decimal fraction from the delta time
		float dtAsSeconds{ dt.asSeconds() };

		// Call each part of the game loop
		input();
		update(dtAsSeconds);
		draw();
	}
}