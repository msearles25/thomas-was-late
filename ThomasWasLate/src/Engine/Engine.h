#pragma once
#include <SFML/Graphics.hpp>
#include "../Characters//Bob/Bob.h"
#include "../TextureHolder/TextureHolder.h"
#include "../Characters/Thomas/Thomas.h"

class Engine
{
private:
	// The texture holder
	TextureHolder th;

	// Thomas and bob
	Thomas m_Thomas;
	Bob m_Bob;

	const int TILE_SIZE{ 50 };
	const int VERTS_IN_QUAD{ 4 };

	// Gravity for charcters
	const int GRAVITY{ 300 };

	// A regular RenderWindow
	sf::RenderWindow m_Window;

	// The main views for the game
	sf::View m_MainView;
	sf::View m_LeftView;
	sf::View m_RightView;

	// Three views for the background
	sf::View m_BGMainView;
	sf::View m_BGLeftView;
	sf::View m_BGRightView;

	sf::View m_HudView;

	// Declare a sprite and a Texture
	// for the bakcground
	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;

	// is the game currently playing?
	bool m_Playing{ false };

	// Is character 1 or 2, for the current focus
	bool m_Character1{ true };

	// Start in full screen (not split) mode
	bool m_SplitScreen{ false };

	// Time in the current level (seconds)
	float m_TimeRemaining{ 10 };
	sf::Time m_GameTimeTotal;

	// Is it time for new/first level?
	bool m_NewLevelRequired{ true };

	// Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();
public:
	// The engine constructor
	Engine();

	// Run will call all the private functions
	void run();
};

