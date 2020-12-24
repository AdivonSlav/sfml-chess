#pragma once

#include "chess.h"

//Kreira teksturu i sprite za sve figure bijelog i crnog
void createPieces(White w_Figures[], Black b_Figures[]);

//Postavlja startnu poziciju bijelog i crnog na tabli
void loadPieces(Chess& board, White w_Figures[], Black b_Figures[]);