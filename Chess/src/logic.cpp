#include "logic.h"

namespace chess { namespace logic {

	sf::Vector2f calculatePos(int cell_size, White& piece)
	{
		sf::Vector2f pos = piece.getRelativePos(cell_size);
		sf::Vector2f newPos = sf::Vector2f(cell_size * int(pos.x / cell_size) + 10.0f, cell_size * int(pos.y / cell_size) + 10.0f);

		return newPos;
	}
	
	sf::Vector2f calculatePos(int cell_size, Black& piece)
	{
		sf::Vector2f pos = piece.getRelativePos(cell_size);
		sf::Vector2f newPos = sf::Vector2f(cell_size * int(pos.x / cell_size) + 10.0f, cell_size * int(pos.y / cell_size) + 10.0f);

		return newPos;
	}

	std::string chessNotate(sf::Vector2f pos, int cell_size)
	{
		std::string notation = "";

		notation += char(pos.x / cell_size + 97);
		notation += char(8 - pos.y / cell_size + 49);

		return notation;
	}

}}