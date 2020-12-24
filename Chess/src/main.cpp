#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "chess.h"
#include "functions.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Chess");
	//window.setVerticalSyncEnabled(true);

	Chess board;
	board.create();
	board.scale(0.667f, 0.667f);

	White* w_Figures = new White[16];
	Black* b_Figures = new Black[16];
	createPieces(w_Figures, b_Figures);
	loadPieces(board, w_Figures, b_Figures);
	

	White bishop1;
	bishop1.create("textures/bishop_white.png");
	bishop1.scale(0.70f, 0.70f);

	bool isMoved = false;
	float dx = 0.0f;
	float dy = 0.0f;
	
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

			if (event.type == sf::Event::MouseButtonPressed)
				if (event.key.code == sf::Mouse::Left)
					if (bishop1.getSprite().getGlobalBounds().contains(position.x, position.y))
					{
						isMoved = true;
						dx = position.x - bishop1.getPosition().x;
						dy = position.y - bishop1.getPosition().y;
					}

			if (event.type == sf::Event::MouseButtonReleased)
				if (event.key.code == sf::Mouse::Left)
					isMoved = false;
		}

		if (isMoved)
		{
			bishop1.Move(position.x - dx, position.y - dy);
		}

		// Clear screen nakon zadnjeg izvršenja loop-a
		window.clear();

		window.draw(board.getSprite());

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