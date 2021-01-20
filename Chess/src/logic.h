#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#include "pieces.h"

using namespace chess::pieces;

namespace chess { namespace logic {

	/*
	 * Kalkuliše poziciju figure u odnosu na ćeliju u koju se pomjerila
	 */
	sf::Vector2f calculatePos(int cell_size, Pieces& piece);

	/*
	 * Notacija za šah
	 */
	std::string chessNotate(sf::Vector2f pos, int cell_size);

	/*
	 * Provjera da li je figura uzeta
	 */
	void checkCapture(Pieces* figures, sf::Vector2f pos);

	/*
	 * Graficki prikaze zadnji potez
	 */
	void displayLastMove(int cell_size, sf::Vector2f& old_position, sf::Vector2f& new_position, sf::RectangleShape last_move[2]);
}}
