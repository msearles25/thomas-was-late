#pragma once
#include "../../PlayableCharacter/PlayableCharacter.h"

class Bob : public PlayableCharacter
{
public:
	// A constructor specific to only bob
	Bob();

	// The overridden input handler for bob
	bool virtual handleInput();
};