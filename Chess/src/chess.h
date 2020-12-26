#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace chess
{
	class Chess
	{
	private:
		sf::Texture m_Texture;
		sf::Sprite m_Sprite;

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
	public:

		Chess();

		/*
		* Vraća sprite od objekta kao sf::Sprite
		*/
		sf::Sprite& getSprite();

		/*
		* Kreira teksturu od unesene slike preko parametra filename i dodijeli ga ga objektu preko sprite
		*/
		void create(const std::string& filename);

		/*
		* Skalira veličinu sprite od objekta preko Vector2f koji prima float vrijednosti kao x i y
		*/
		void scale(float x, float y);

		/*
		* Postavlja apsolutnu poziciju sprite od objekta uzimajući koordinate x i y kao float vrijednosti
		*/
		void move(float x, float y);

		/*
		* Vraća vrijednost 8x8 table na unesenim indeksima i, j
		*/
		int getBoardValue(int i, int j);

		/*
		* Vraća apsolutnu poziciju objekta preko njegovog sprita kao Vector2f
		 */
		sf::Vector2f getPosition();

		/*
		 * Vraća relativnu poziciju objekta u odnosu na ćeliju table
		 */
		sf::Vector2f getRelativePos(int cell_size) const;

	};
}
