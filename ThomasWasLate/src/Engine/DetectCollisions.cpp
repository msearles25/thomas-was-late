#include "Engine.h"

bool Engine::detectCollisions(PlayableCharacter& character)
{
	bool reachedGoal{ false };
	// Make a rect for all the limbs
	sf::FloatRect detectionZone{ character.getPosition() };

	// Make a FloatRect to test each block
	sf::FloatRect block;

	block.width = TILE_SIZE;
	block.height = TILE_SIZE;

	// Build a zone around thomas to detect collisions
	int startX{ (int)(detectionZone.left / TILE_SIZE) - 1 };
	int startY{ (int)(detectionZone.top / TILE_SIZE) - 1 };
	int endX{ (int)(detectionZone.left / TILE_SIZE) + 2 };

	// Thomas is tall so check a few tiles vertically;
	int endY{ (int)(detectionZone.top / TILE_SIZE) + 3 };

	// Make sure to not test positions lower than 0 or higher than the end of the array
	if (startX < 0) startX = 0;
	if (startY < 0)startY = 0;
	if (endX >= m_LM.getLevelSize().x)
		endX = m_LM.getLevelSize().x;
	if (endY >= m_LM.getLevelSize().y)
		endY = m_LM.getLevelSize().y;

	// Has the player fallen out of the map?
	sf::FloatRect level(0, 0,
		m_LM.getLevelSize().x * TILE_SIZE,
		m_LM.getLevelSize().y * TILE_SIZE);

	if (!character.getPosition().intersects(level))
	{
		// Respawn the character
		character.spawn(m_LM.getStartPosition(), GRAVITY);
	}

	for (int x{ startX }; x < endX; x++)
	{
		for (int y{ startY }; y < endY; y++)
		{
			// Initialize the starting position of the current block
			block.left = x * TILE_SIZE;
			block.top = y * TILE_SIZE;

			// Has the character been burnt or drowned?
			// Use head as this allows him to sink some
			if (m_ArrayLevel[y][x] == 2 || m_ArrayLevel[y][x] == 3)
			{
				if (character.getHead().intersects(block))
				{
					character.spawn(m_LM.getStartPosition(), GRAVITY);
					// Which sound do we play?
					if (m_ArrayLevel[y][x] == 2) // fire
					{

					}
					else // water
					{

					}
				}
			}

			// Is the character colliding with a normal block?
			if (m_ArrayLevel[y][x] == 1)
			{
				if (character.getRight().intersects(block))
				{
					character.stopRight(block.left);
				}
				else if (character.getLeft().intersects(block))
				{
					character.stopLeft(block.left);
				}

				if (character.getFeet().intersects(block))
				{
					character.stopFalling(block.top);
				}
				else if (character.getHead().intersects(block))
				{
					character.stopJump();
				}
			}

			// Has the players character rerached the goal?
			if (m_ArrayLevel[y][x] == 4)
			{
				// Character reached the goal
				reachedGoal = true;
			}
		}
	}

	return reachedGoal;
}