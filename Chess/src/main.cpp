#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "chess.h"
#include "loader.h"
#include "logic.h"

using namespace chess;
using namespace loader;
using namespace logic;

// Velicina celije za kalkulacije
const int c_size = 100;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Chess");

	Chess board;
	board.create("textures/chess_board4.png");

	Pieces* w_Figures = new Pieces[16];
	Pieces* b_Figures = new Pieces[16];
	createPieces(w_Figures, b_Figures);
	loadPieces(board, w_Figures, b_Figures);

	bool w_isMoved = false;
	bool b_isMoved = false;
	float dx = 0.0f;
	float dy = 0.0f;
	int moved_Piece = 0;
	sf::Vector2f old_position;

	// Oblik za pokazivanje zadnjeg poteza
	sf::RectangleShape last_move[2];
	for (int i = 0; i < 2; i++)
	{
		last_move[i].setSize(sf::Vector2f(100.0f, 100.0f));
		last_move[i].setPosition(-100.0f, -100.0f);
		last_move[i].setFillColor(sf::Color(186, 184, 108, 128));
	}
	// Glavni game loop
	while (window.isOpen()) 
	{
		sf::Event event;

		//Pozicija miša u integer vektoru
		sf::Vector2i position = sf::Mouse::getPosition(window);
		
		// Provjerava promjene u stanju igre
		while (window.pollEvent(event)) 
		{
			
			// Ako se prozor zatvori, terminiraj program
			if (event.type == sf::Event::Closed) 
			{
				window.close();
			}

			// Provjerava da li se je pritisnuo lijevi klik na mišu
			if (event.type == sf::Event::MouseButtonPressed)
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					// Pomjeri sprite od objekta za onoliko koliko se miš pomjerio
					for (int i = 0; i < 16; i++)
					{
						if (w_Figures[i].getSprite().getGlobalBounds().contains(position.x, position.y))
						{
							w_isMoved = true;
							moved_Piece = i;
							
							dx = position.x - w_Figures[i].getPosition().x;
							dy = position.y - w_Figures[i].getPosition().y;
							 
							old_position = w_Figures[i].getPosition();
						}
					}
					
					for (int i = 0; i < 16; i++)
					{
						if (b_Figures[i].getSprite().getGlobalBounds().contains(position.x, position.y))
						{
							b_isMoved = true;
							moved_Piece = i;
							
							dx = position.x - b_Figures[i].getPosition().x;
							dy = position.y - b_Figures[i].getPosition().y;
							
							old_position = b_Figures[i].getPosition();
						}
					}					
				}

			// Nakon prestanka klika, kalkuliše poziciju objekta unutar ćelije table
			if (event.type == sf::Event::MouseButtonReleased)
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					if (w_isMoved)
					{
						w_isMoved = false;
						
						sf::Vector2f new_position = calculatePos(c_size, w_Figures[moved_Piece]);
						w_Figures[moved_Piece].move(new_position.x, new_position.y);
						
						displayLastMove(c_size, old_position, new_position, last_move);

						checkCapture(b_Figures, new_position);

						std::cout << chessNotate(old_position, c_size) + chessNotate(new_position, c_size) << std::endl;
					}

					else if (b_isMoved)
					{
						b_isMoved = false;
						

						sf::Vector2f new_position = calculatePos(c_size, b_Figures[moved_Piece]);
						b_Figures[moved_Piece].move(new_position.x, new_position.y);

						displayLastMove(c_size, old_position, new_position, last_move);

						checkCapture(w_Figures, new_position);
						
						std::cout << chessNotate(old_position, c_size) + chessNotate(new_position, c_size) << std::endl;
					}
				}
		}

		if (w_isMoved)
		{
			w_Figures[moved_Piece].move(position.x - dx, position.y - dy);
		}

		else if (b_isMoved)
		{
			b_Figures[moved_Piece].move(position.x - dx, position.y - dy);
		}

		// Clear screen nakon zadnjeg izvršenja loop-a
		window.clear();

		window.draw(board.getSprite());

		for (int i = 0; i < 2; i++) window.draw(last_move[i]);

		for (int i = 0; i < 16; i++)
		{
			window.draw(w_Figures[i].getSprite());
		}

		for (int i = 0; i < 16; i++)
		{
			window.draw(b_Figures[i].getSprite());
		}

		window.display();
	}
	
	return 0;
}