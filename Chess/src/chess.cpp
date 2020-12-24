#include "chess.h"

sf::Sprite& Chess::getSprite()
{
	return m_Sprite;
}

void Chess::create()
{
	if (!m_Texture.loadFromFile("textures/chess_board4.png"))
	{
		std::cout << "Can't load texture!" << std::endl;
	}

	m_Sprite.setTexture(m_Texture);

}

void Chess::create(std::string filename)
{
	if (!m_Texture.loadFromFile(filename))
	{
		std::cout << "Can't load texture!" << std::endl;
	}

	m_Sprite.setTexture(m_Texture);
}

void Chess::scale(float x, float y)
{
	m_Sprite.scale(sf::Vector2f(x, y));
}

void Chess::Move(float x, float y)
{
	m_Sprite.setPosition(x, y);
}

sf::Vector2f Chess::getPosition()
{
	return m_Sprite.getPosition();
}
