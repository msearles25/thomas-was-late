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

void ParticleSystem::update(float dt)
{
	m_Duration -= dt;
	std::vector<Particle>::iterator it;
	int currentVertex{ 0 };

	for (it = m_Particles.begin(); it < m_Particles.end(); it++)
	{
		// Move the particle
		(*it).update(dt);

		// Update the vertex array
		m_Vertices[currentVertex++].position = it->getPosition();
	}

	if (m_Duration < 0)
	{
		m_IsRunning = false;
	}
}

void ParticleSystem::emitParticles(sf::Vector2f startPosition)
{
	m_IsRunning = true;
	m_Duration = 2;

	int currentVertex{ 0 };

	for (auto it{ m_Particles.begin() }; it != m_Particles.end(); it++)
	{
		m_Vertices[currentVertex++].color = sf::Color::Yellow;
		it->setPosition(startPosition);
	}
}