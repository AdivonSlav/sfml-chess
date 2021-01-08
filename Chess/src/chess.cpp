#include <iostream>

#include "chess.h"

namespace chess {

	Chess::Chess()
	{
		m_Sprite.scale(0.667f, 0.667f);
	}
	
	sf::Sprite& Chess::getSprite()
	{
		return m_Sprite;
	}

	void Chess::create(const std::string& filename)
	{
		if (!m_Texture.loadFromFile(filename))
		{
			std::cout << "Can't load texture!" << std::endl;
		}

		m_Sprite.setTexture(m_Texture);
	}

	void Chess::scale(const float x, const float y)
	{
		m_Sprite.scale(sf::Vector2f(x, y));
	}


	void Chess::move(const float x, const float y)
	{
		m_Sprite.setPosition(x, y);
	}

	int Chess::getBoardValue(const int i, const int j)
	{
		return m_Board[i][j];
	}

	sf::Vector2f Chess::getPosition() const
	{
		return m_Sprite.getPosition();
	}

	sf::Vector2f Chess::getRelativePos(int cell_size) const
	{
		const sf::Vector2f position = m_Sprite.getPosition() + sf::Vector2f(cell_size / 2, cell_size / 2);

		return position;
	}
}