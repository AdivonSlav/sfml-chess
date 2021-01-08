#include "pieces.h"

namespace chess { namespace pieces {

	Pieces::Pieces(char name)
	{
		m_Name = name;
	}

	void Pieces::setName(char name)
	{
		m_Name = name;
	}
}}