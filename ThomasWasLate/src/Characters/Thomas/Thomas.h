#pragma once
#include "../../PlayableCharacter/PlayableCharacter.h"

// Inheritance from PlayableCharacter
class Thomas : public PlayableCharacter
{
public:
	// Constructor specific to only Thomas
	Thomas();

	// The overridden input handler for Thomas
	bool virtual handleInput();
};