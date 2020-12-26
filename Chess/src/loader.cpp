#include "loader.h"
#include "whiteblack.h"

using namespace chess;
using namespace whiteblack;

namespace chess { namespace loader {

	const int c_size = 100;

	void createPieces(White w_Figures[], Black b_Figures[])
	{
		for (int i = 0; i < 16; i++)
		{
			switch (i)
			{
			case 0:
				w_Figures[i].create("textures/rook_white.png");
				break;
			case 1:
				w_Figures[i].create("textures/knight_white.png");
				break;
			case 2:
				w_Figures[i].create("textures/bishop_white.png");
				break;
			case 3:
				w_Figures[i].create("textures/king_white.png");
				break;
			case 4:
				w_Figures[i].create("textures/queen_white.png");
				break;
			case 5:
				w_Figures[i].create("textures/bishop_white.png");
				break;
			case 6:
				w_Figures[i].create("textures/knight_white.png");
				break;
			case 7:
				w_Figures[i].create("textures/rook_white.png");
				break;
			case 8:
			case 9:
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:
			case 15:
				w_Figures[i].create("textures/pawn_white.png");
				break;
			}

			w_Figures[i].scale(0.35f, 0.35f);
		}

		for (int i = 0; i < 16; i++)
		{
			switch (i)
			{
			case 0:
				b_Figures[i].create("textures/rook_black.png");
				break;
			case 1:
				b_Figures[i].create("textures/knight_black.png");
				break;
			case 2:
				b_Figures[i].create("textures/bishop_black.png");
				break;
			case 3:
				b_Figures[i].create("textures/queen_black.png");
				break;
			case 4:
				b_Figures[i].create("textures/king_black.png");
				break;
			case 5:
				b_Figures[i].create("textures/bishop_black.png");
				break;
			case 6:
				b_Figures[i].create("textures/knight_black.png");
				break;
			case 7:
				b_Figures[i].create("textures/rook_black.png");
				break;
			case 8:
			case 9:
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:
			case 15:
				b_Figures[i].create("textures/pawn_black.png");
				break;
			}

			b_Figures[i].scale(0.35f, 0.35f);
		}

	}

	void loadPieces(Chess& board, White w_Figures[], Black b_Figures[])
	{
		int k = 0;

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				const int n = board.getBoardValue(i, j);

				if (!n)
					continue;


				if (n < 0 && n != -6)
				{
					b_Figures[k].move(c_size * j + 10, c_size * i + 10);
				}

				else if (n == -6)
				{
					b_Figures[k].move(c_size * j + 10, c_size * i + 10);
				}

				if (k == 15)
				{
					k = 0;
				}
				else
					k++;

			}
		}

		k = 0;

		for (int i = 7; i >= 0; i--)
		{
			for (int j = 7; j >= 0; j--)
			{
				const int n = board.getBoardValue(i, j);

				if (!n)
					continue;

				if (n == 6)
				{
					w_Figures[k].move(c_size * j + 10, c_size * i + 10);
				}

				else if (n > 0 && n != 6)
				{
					w_Figures[k].move(c_size * j + 10, c_size * i + 10);
				}

				if (k == 15)
				{
					k = 0;
				}
				else
					k++;

			}
		}
	}
}}