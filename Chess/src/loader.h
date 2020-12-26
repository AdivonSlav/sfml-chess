#pragma once

#include "chess.h"
#include "whiteblack.h"

using namespace chess;
using namespace whiteblack;

namespace chess { namespace loader {
	
	/*
	 * Kreira teksturu i sprite za sve figure bijelog i crnog
	 */
	void createPieces(White w_Figures[], Black b_Figures[]);

	/*
	 * Postavlja startnu poziciju bijelog i crnog na tabli
	 */
	void loadPieces(Chess& board, White w_Figures[], Black b_Figures[]);
	
}}