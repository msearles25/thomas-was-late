#include "HUD.h"

HUD::HUD()
{
	sf::Vector2u resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;

	// Load our font
	m_Font.loadFromFile("Content/fonts/Roboto-Light.ttf");

	// When the game is paused
	m_StartText.setFont(m_Font);
	m_StartText.setCharacterSize(100);
	m_StartText.setFillColor(sf::Color::White);
	m_StartText.setString("Press Enter when ready!");

	// Position the text on screen
	sf::FloatRect textRect{ m_StartText.getLocalBounds() };

	m_StartText.setOrigin(
		textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	
	m_StartText.setPosition(resolution.x / 2.0f, resolution.y / 2.0f);

	// Time 
	m_TimeText.setFont(m_Font);
	m_TimeText.setCharacterSize(75);
	m_TimeText.setFillColor(sf::Color::White);
	m_TimeText.setPosition(resolution.x - 150, 0);
	m_TimeText.setString("------");

	// Level
	m_LevelText.setFont(m_Font);
	m_LevelText.setCharacterSize(75);
	m_LevelText.setFillColor(sf::Color::White);
	m_LevelText.setPosition(25, 0);
	m_LevelText.setString("1");
}