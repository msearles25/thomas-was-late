#include <fstream>
#include <sstream>
#include <string>
#include <SFML/Audio.hpp>
#include "LevelManager.h"
#include "../TextureHolder/TextureHolder.h"

int** LevelManager::nextLevel(sf::VertexArray& rVaLevel)
{
	m_LevelSize.x = 0;
	m_LevelSize.y = 0;

	// Get the next level
	m_CurrentLevel++;

	if (m_CurrentLevel > NUM_LEVELS)
	{
		m_CurrentLevel = 1;
		m_TimeModifier -= .1f;
	}

	// Load the appropriate level from a text file
	std::string levelToLoad;
	switch (m_CurrentLevel)
	{
	case 1:
		levelToLoad = "Content/levels/level1.txt";
		m_StartPosition.x = 100;
		m_StartPosition.y = 100;
		m_BaseTimeLimit = 30.0f;
		break;
	case 2:
		levelToLoad = "Content/levels/level2.txt";
		m_StartPosition.x = 100;
		m_StartPosition.y = 3600;
		m_BaseTimeLimit = 100.0f;
		break;
	case 3:
		levelToLoad = "Content/levels/level3.txt";
		m_StartPosition.x = 1250;
		m_StartPosition.y = 0;
		m_BaseTimeLimit = 30.0f;
		break;
	case 4:
		levelToLoad = "Content/levels/level4.txt";
		m_StartPosition.x = 50;
		m_StartPosition.y = 200;
		m_BaseTimeLimit = 50.0f;
		break;
	default:
		break;
	}

	// Loading the file based on the switch
	std::ifstream inputFile(levelToLoad);
	std::string s;

	// Count the number of rows in the file
	while (std::getline(inputFile, s))
	{
		++m_LevelSize.y;
	}
	// store the length of rows
	m_LevelSize.x = s.length();

	// Go back to the start of the file 
	inputFile.clear();
	inputFile.seekg(0, std::ios::beg);

	// Prepare the 2d array to hold the int vlaues from our file
	int **arrayLevel{ new int *[m_LevelSize.y] };
	for (int i{ 0 }; i < m_LevelSize.y; ++i)
	{
		// Add a new array into each array element
		arrayLevel[i] = new int[m_LevelSize.x];
	}

	// Loop through the file and store all the values 
	// into the 2d array
	std::string row;
	int y{ 0 };
	while (inputFile >> row)
	{
		for (int x{ 0 }; x < row.length(); x++)
		{
			const char val{ row[x] };
			arrayLevel[y][x] = atoi(&val);
		}
		y++;
	}

	inputFile.close();

	// What kind of primitive are we using?
	rVaLevel.setPrimitiveType(sf::Quads);

	// Set the size of the vertex array
	rVaLevel.resize(m_LevelSize.x * m_LevelSize.y * VERTS_IN_QUAD);

	// Start at the beginning of our vertexArray
	int currentVertex{ 0 };

	for (int x{ 0 }; x < m_LevelSize.x; x++)
	{
		for (int y{ 0 }; y < m_LevelSize.y; y++)
		{
			// Position each vertex in the current quad
			rVaLevel[currentVertex + 0].position = sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE);
			rVaLevel[currentVertex + 1].position = sf::Vector2f((x * TILE_SIZE) + TILE_SIZE, y * TILE_SIZE);
			rVaLevel[currentVertex + 2].position = sf::Vector2f((x * TILE_SIZE), (y * TILE_SIZE) + TILE_SIZE);
			rVaLevel[currentVertex + 3].position = sf::Vector2f(x * TILE_SIZE, (y * TILE_SIZE) + TILE_SIZE);

			// Which tile from the sprite sheet are we using?
			int  verticalOffset = arrayLevel[y][x] * TILE_SIZE;

			rVaLevel[currentVertex + 0].texCoords = sf::Vector2f(0, 0 + verticalOffset);
			rVaLevel[currentVertex + 1].texCoords = sf::Vector2f(TILE_SIZE, 0 + verticalOffset);
			rVaLevel[currentVertex + 2].texCoords = sf::Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);
			rVaLevel[currentVertex + 3].texCoords = sf::Vector2f(0, TILE_SIZE + verticalOffset);

			// Position ready for the next four verticies
			currentVertex = currentVertex + VERTS_IN_QUAD;
		}
	}

	return arrayLevel;
}

sf::Vector2i LevelManager::getLevelSize()
{
	return m_LevelSize;
}

int LevelManager::getCurrentLevel()
{
	return m_CurrentLevel;
}

float LevelManager::getTImeLimit()
{
	return m_BaseTimeLimit * m_TimeModifier;
}

sf::Vector2f LevelManager::getStartPosition()
{
	return m_StartPosition;
}
