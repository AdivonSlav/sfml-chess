#pragma once

#include <SFML/Graphics.hpp>

#include "chess.h"

namespace chess { namespace whiteblack {

	// Klasa za bijeli
	class White : public Chess
	{
	private:
		sf::Texture m_Texture;
		sf::Sprite m_Sprite;
		
	public:

		White();

	};

	// Klasa za crni
	class Black : public Chess
	{
	private:
		sf::Texture m_Texture;
		sf::Sprite m_Sprite;

	public:

		Black();

	};	
}}