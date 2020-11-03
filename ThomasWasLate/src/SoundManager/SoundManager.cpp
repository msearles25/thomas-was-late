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

	// Loop all of the fire sounds
	m_Fire1Sound.setLoop(true);
	m_Fire2Sound.setLoop(true);
	m_Fire3Sound.setLoop(true);


}