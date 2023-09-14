#include <assert.h>
#include "Board.h"


Board::Board(Graphics& gfx)
	: gfx(gfx)
{
}

void Board::DrawCell( const Location& loc, Color& c)
{
	assert(loc.x >= 0);
	assert(loc.x < m_width);
	assert(loc.y >= 0);
	assert(loc.y < m_height);
	gfx.DrawRectDim(loc.x * m_dimention, loc.y * m_dimention, m_dimention, m_dimention, c);
}

int Board::GetDimention()
{
	return m_dimention;
}

int Board::GetWidth()
{
	return m_width;
}

int Board::GetHeight()
{
	return m_height;
}
