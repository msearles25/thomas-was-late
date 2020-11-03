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

	// Can this GPU handle/use the shader?
	if (!sf::Shader::isAvailable())
	{
		// Can't, so we close the game
		m_Window.close();
	}
	else
	{
		// Load two shaders (1 vertex and 1 fragment)
		m_RippleShader.loadFromFile("Content/shaders/vertShader.vert", "Content/shaders/rippleShader.frag");
	}

	m_BackgroundTexture = TextureHolder::GetTexture("Content/graphics/background.png");

	// Associate our texture with the sprite
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	// Load the texture for the background vertex array
	m_tilesTexture = TextureHolder::GetTexture("Content/graphics/tiles_sheet.png");

	// Initialize the particle system
	m_PS.init(1000);
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