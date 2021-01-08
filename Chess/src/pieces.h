#pragma once

#include <SFML/Graphics.hpp>

#include "chess.h"

namespace chess { namespace pieces {

	// Klasa za figure
	class Pieces : public Chess
	{
	private:
		sf::Texture m_Texture;
		sf::Sprite m_Sprite;

		char m_Name;
	public:
		Pieces() = default;
			
		Pieces(char name);

		// Postavlja ime figure
		void setName(char name);
	};
}}