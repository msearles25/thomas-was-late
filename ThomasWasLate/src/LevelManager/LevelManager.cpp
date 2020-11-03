#include <fstream>
#include <sstream>
#include <string>
#include <SFML/Audio.hpp>
#include "LevelManager.h"
#include "../TextureHolder/TextureHolder.h"

int **LevelManager::nextLevel(sf::VertexArray &rVaLevel)
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


}