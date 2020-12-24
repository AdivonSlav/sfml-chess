#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

class Chess
{
private:
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;

public:
	// 8x8 tabla 
	int m_Board[8][8] =
					{ {-1,-2,-3,-4,-5,-3,-2,-1},
					  {-6,-6,-6,-6,-6,-6,-6,-6},
					  { 0, 0, 0, 0, 0, 0, 0, 0},
					  { 0, 0, 0, 0, 0, 0, 0, 0},
					  { 0, 0, 0, 0, 0, 0, 0, 0},
					  { 0, 0, 0, 0, 0, 0, 0, 0},
					  { 6, 6, 6, 6, 6, 6, 6, 6},
					  { 1, 2, 3, 4, 5, 3, 2, 1}
					};
	
	//Vraća sprite od objekta
	sf::Sprite& getSprite();

	// Kreira teksturu i dodijeli sprite-u
	void create();
	void create(std::string filename);
	
	// Skaliranje spritea
	void scale(float x, float y);
	
	// Postavlja apsolutnu poziciju sprite u float koordinatama
	void Move(float x, float y);
	
	// Vraća apsolutnu poziciju sprite kao 2float vektor
	sf::Vector2f getPosition();

};

// Klasa za bijeli
class White : public Chess
{
private:
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
public:

	White()
	{

	}


};

// Klasa za crni
class Black : public Chess
{
private:
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
	

public:

	Black()
	{
	}
	

};