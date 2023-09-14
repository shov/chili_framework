#pragma once

#include "Graphics.h"
#include "Location.h"

class Board {
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color& c);
	int GetDimention();
	int GetWidth();
	int GetHeight();
private:
	static constexpr int m_dimention = 20;
	static constexpr int m_width = 25;
	static constexpr int m_height = 25;
	Graphics& gfx;
};