#pragma once
#include <SFML/Graphics.hpp>

class PlayableCharacter
{
protected:
	// The sprite for the charcter
	sf::Sprite m_Sprite;

	// How long will the players jump last?
	float m_JumpDuration;

	// Is a character currently jumping or falling?
	bool m_IsJumping;
	bool m_IsFalling;

	// Which direction is the character currently moving?
	bool m_LeftPressed;
	bool m_RightPressed;

	// How long has the jump lasted for?
	float m_TimeThisJump;

	// Has the player just jumped
	bool m_JustJumped{ false };
private:
	// Gravity
	float m_Gravity;

	// How fast can the character move
	float m_Speed{ 400 };

	// Players current position
	sf::Vector2f m_Position;

	// Where are the characters various body parts?
	sf::FloatRect m_Feet;
	sf::FloatRect m_Head;
	sf::FloatRect m_Right;
	sf::FloatRect m_Left;

	// Players texture
	sf::Texture m_Texture;
public:
	void spawn(sf::Vector2f startPosition, float gravity);

	// This is a pure virtual function
	bool virtual handleInput() = 0;
	// The class is now abstract and cannot be instantiated

	// Where is the palyers current position in the world?
	sf::FloatRect getPosition();

	// A rectangle representing the position
	// of the different parts of the sprite
	sf::FloatRect getFeet();
	sf::FloatRect getHead();
	sf::FloatRect getRight();
	sf::FloatRect getLeft();

	// Send a copy of the sprite to main
	sf::Sprite getSprite();

	// Make the character stand still
	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();

	// Where is the center of our character?
	sf::Vector2f getCenter();

	// Update the player once every frame
	void update(float elapsedTime);
};