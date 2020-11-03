#include "Engine.h"

void Engine::populateEmitters(std::vector<sf::Vector2f>& vSoundEmitters, int** arrayLevel)
{
	// Make surer the vector is empty
	vSoundEmitters.empty();

	// Keep track of the previous emitter so we don't make too many
	sf::FloatRect previousEmitter;

	// Search for fire tiles in the current level
	for (int x{ 0 }; x < (int)m_LM.getLevelSize().x; x++)
	{
		for (int y{ 0 }; y < (int)m_LM.getLevelSize().y; y++)
		{
			if (arrayLevel[y][x] == 2) // fire is present
			{
				// Skip over any fire tiles that are 
				// next to previous emitters
				if (!sf::FloatRect(
					x * TILE_SIZE,
					y * TILE_SIZE,
					TILE_SIZE,
					TILE_SIZE).intersects(previousEmitter))
				{
					// Add the coordinates of this fire block to our sound emitter vector
					vSoundEmitters.push_back(sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE));

					// Make a rectangle of 6 blocks x 6 blocks,
					// so we don't make anymore emitters that are too close to this 
					// current one
					previousEmitter.left = x * TILE_SIZE;
					previousEmitter.top = y * TILE_SIZE;
					previousEmitter.width = TILE_SIZE * 6;
					previousEmitter.height = TILE_SIZE * 6;
				}
			}
		}
	}
}