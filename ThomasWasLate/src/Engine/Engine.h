#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "../Characters/Bob/Bob.h"
#include "../HUD/HUD.h"
#include "../LevelManager/LevelManager.h"
#include "../ParticleSystem/ParticleSystem.h"
#include "../SoundManager/SoundManager.h"
#include "../TextureHolder/TextureHolder.h"
#include "../Characters/Thomas/Thomas.h"

class Engine
{
private:
	// The texture holder
	TextureHolder th;

	// Create a particle system
	ParticleSystem m_PS;

	// Thomas and bob
	Thomas m_Thomas;
	Bob m_Bob;

	// Our levelManager to manage all of are levels
	LevelManager m_LM;

	// Create a SoundManager
	SoundManager m_SM;

	// The HUD
	HUD m_Hud;
	int m_FrameSinceLastHUDUpdate{ 0 };
	int m_TargetFramesPerHUDUpdate{ 500 };

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

	// Declare a shader for the background
	sf::Shader m_RippleShader;

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

	// The vertex array for the level tiles
	sf::VertexArray m_VALevel;

	// The 2d array with the map of the level
	// Pointer to a pointer
	int **m_ArrayLevel{ nullptr };

	// Texture for the level tiles
	sf::Texture m_tilesTexture;

	std::vector<sf::Vector2f> m_FireEmitters;

	// Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();

	// Load a new level
	void loadLevel();

	bool detectCollisions(PlayableCharacter& character);

	// Make a vector of the best places to emit sounds from
	void populateEmitters(std::vector<sf::Vector2f>& vSoundEmitters, int** arrayLevel);
public:
	// The engine constructor
	Engine();

	// Run will call all the private functions
	void run();
};

