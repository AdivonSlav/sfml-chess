#pragma once

#include "whiteblack.h"

using namespace chess::whiteblack;

namespace chess { namespace logic {

	/*
	 * Kalkuliše poziciju figure u odnosu na ćeliju u koju se pomjerila
	 */
	sf::Vector2f calculatePos(int cell_size, White& piece);
	sf::Vector2f calculatePos(int cell_size, Black& piece);

	std::string chessNotate(sf::Vector2f pos, int cell_size);
	
}}
