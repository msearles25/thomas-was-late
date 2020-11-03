#include <stdlib.h>
#include <time.h>
#include "ParticleSystem.h"

void ParticleSystem::init(int numParticles)
{
	m_Vertices.setPrimitiveType(sf::Points);
	m_Vertices.resize(numParticles);

	// Create the particles
	for (int i{ 0 }; i < numParticles; i++)
	{
		srand(time(0) + i);
		float angle{ (rand() % 360) * 3.14f / 180.0f };
		float speed{ (rand() & 600) + 600.0f };

		sf::Vector2f direction;
		direction = sf::Vector2f(cos(angle) * speed, sin(angle) * speed);

		m_Particles.push_back(Particle(direction));
	}
}