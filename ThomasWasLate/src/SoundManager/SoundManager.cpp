#include "SoundManager.h"

SoundManager::SoundManager()
{
	// Loud the sounds into the buffers
	m_FireBuffer.loadFromFile("Content/sound/fire1.wav");
	m_FallInFireBuffer.loadFromFile("Content/sound/fallinfire.wav");
	m_FallInWaterBuffer.loadFromFile("Content/sound/fallinwater.wav");
	m_JumpBuffer.loadFromFile("Content/sound/jump.wav");
	m_ReachGoalBuffer.loadFromFile("Content/sound/reachgoal.wav");

	// Associate our sounds with the buffers
	m_Fire1Sound.setBuffer(m_FireBuffer);
	m_Fire2Sound.setBuffer(m_FireBuffer);
	m_Fire3Sound.setBuffer(m_FireBuffer);
	m_FallInFireSound.setBuffer(m_FallInFireBuffer);
	m_FallInWaterSound.setBuffer(m_FallInWaterBuffer);
	m_JumpSound.setBuffer(m_JumpBuffer);
	m_ReachGoalSound.setBuffer(m_ReachGoalBuffer);

	// When the player is 50 pixles away the sound will be full volume
	float minDistance{ 150 };
	float attenuation{ 15 };

	// Set all the attenuation levels
	m_Fire1Sound.setAttenuation(attenuation);
	m_Fire2Sound.setAttenuation(attenuation);
	m_Fire3Sound.setAttenuation(attenuation);

	// Set the minimum distance levels 
	m_Fire1Sound.setMinDistance(minDistance);
	m_Fire2Sound.setMinDistance(minDistance);
	m_Fire3Sound.setMinDistance(minDistance);

	// Loop all of the fire sounds when we call play()
	m_Fire1Sound.setLoop(true);
	m_Fire2Sound.setLoop(true);
	m_Fire3Sound.setLoop(true);
}

void SoundManager::playFire(sf::Vector2f emitterLocation, sf::Vector2f listenerLocation)
{
	// WHere is the Listener?
	sf::Listener::setPosition(emitterLocation.x, emitterLocation.y, 0.0f);

	switch (m_NextSound)
	{
	case 1:
		// Locate/move the source of the sound
		m_Fire1Sound.setPosition(emitterLocation.x, emitterLocation.y, 0.0f);

		if (m_Fire1Sound.getStatus() == sf::Sound::Status::Stopped)
		{
			// Play the sound if it's not already playing
			m_Fire1Sound.play();
		}
		break;
	case 2:
		// Do the exact same
		m_Fire2Sound.setPosition(emitterLocation.x, emitterLocation.y, 0.0f);
		
		if (m_Fire2Sound.getStatus() == sf::Sound::Status::Stopped)
		{
			m_Fire2Sound.play();
		}
		break;
	case 3:
		// Do the same, again
		m_Fire3Sound.setPosition(emitterLocation.x, emitterLocation.y, 0.0f);

		if (m_Fire1Sound.getStatus() == sf::Sound::Stopped)
		{
			m_Fire3Sound.play();
		}
		break;
	}

	// Increment to the next fire sound we need
	m_NextSound++;

	// Go back to the first sound when the third has stopped
	if (m_NextSound > 3)
	{
		m_NextSound = 1;
	}
}