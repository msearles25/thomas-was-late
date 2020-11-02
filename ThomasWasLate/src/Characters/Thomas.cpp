#include "../TextureHolder/TextureHolder.h"
#include "Thomas.h"

Thomas::Thomas()
{
	// Associate a texture with our sprite
	m_Sprite = sf::Sprite(TextureHolder::GetTexture("Content/graphics/thomas.png"));

	m_JumpDuration = .45;
}

bool Thomas::handleInput()
{
	m_JustJumped = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		// Start a jump if not already jumping
		// but only if standing ona block (so not falling)
		if (!m_IsJumping && !m_IsFalling)
		{
			m_IsJumping = true;
			m_TimeThisJump = 0;
			m_JustJumped = true;
		}
	}
	else
	{
		m_IsJumping = false;
		m_IsFalling = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_LeftPressed = true;
	}
	else
	{
		m_LeftPressed = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_RightPressed = true;
	}
	else
	{
		m_RightPressed = false;
	}

	return m_JustJumped;
}