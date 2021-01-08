#pragma once

#include "pieces.h"
#include "chess.h"

using namespace chess;
using namespace pieces;

namespace chess { namespace loader {
	
	/*
	 * Kreira teksturu i sprite za sve figure bijelog i crnog
	 */
	void createPieces(Pieces w_Figures[], Pieces b_Figures[]);

	/*
	 * Postavlja startnu poziciju bijelog i crnog na tabli
	 */
	void loadPieces(Chess& board, Pieces w_Figures[], Pieces b_Figures[]);
	
}}