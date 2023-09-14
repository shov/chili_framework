#pragma once

#include "Board.h"

class Snake {
private:
	class Segment {
	public:
		void InitHead(const Location& loc);
		void InitBody();
		void Follow(const Segment& sgmt);
		void MoveBy(const Location& loc);
		void Draw(Board& brd);
	private:
		Color m_c;
		Location m_loc;
	};

public:
	Snake(const Location& loc);
	void Grow();
	void Draw(Board& brd);
	void MoveBy(Location& loc);

private:
	static constexpr int m_maxSegmentAmount = 100;
	static constexpr Color m_headColor = Colors::Yellow;
	static constexpr Color m_bodyColor = Colors::Green;

	int m_usedSegmentAmount = 1;
	Segment m_segmentList[m_maxSegmentAmount];
};