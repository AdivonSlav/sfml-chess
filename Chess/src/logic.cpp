#include "logic.h"

namespace chess { namespace logic {

	sf::Vector2f calculatePos(int cell_size, Pieces& piece)
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

	void checkCapture(Pieces* figures, sf::Vector2f pos)
	{
		for (int i = 0; i < 16; i++)
		{
			if (figures[i].getPosition() == pos)
			{
				figures[i].move(-100.0f, -100.0f);
			}
		}
	}

	void displayLastMove(int cell_size, sf::Vector2f& old_position, sf::Vector2f& new_position, sf::RectangleShape last_move[2])
	{
		last_move[0].setPosition(cell_size * int(old_position.x / cell_size), cell_size * int(old_position.y / cell_size));

		last_move[1].setPosition(cell_size * int(new_position.x / cell_size), cell_size * int(new_position.y / cell_size));
	}
}}