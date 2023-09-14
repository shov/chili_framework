#include <assert.h>

#include "Snake.h"

Snake::Snake(const Location& loc)
{
	m_segmentList[0].InitHead(loc);
}

void Snake::Grow()
{
	if (m_usedSegmentAmount >= m_maxSegmentAmount) {
		return;
	}

	m_usedSegmentAmount += 1;
	m_segmentList[m_usedSegmentAmount - 1].InitBody();
}

void Snake::Draw(Board& brd)
{
	for (int i = 0; i < m_usedSegmentAmount; i++)
	{
		m_segmentList[i].Draw(brd);
	}
}

void Snake::MoveBy(Location& loc)
{
	for (int i = m_usedSegmentAmount - 1; i > 0; i--) 
	{
		m_segmentList[i].Follow(m_segmentList[i - 1]);
	}
	m_segmentList[0].MoveBy(loc);
}

void Snake::Segment::InitHead(const Location& loc)
{
	m_c = Snake::m_headColor;
	m_loc = loc;
}

void Snake::Segment::InitBody()
{
	m_c = Snake::m_bodyColor;
}

void Snake::Segment::Follow(const Segment& sgmt)
{
	m_loc = sgmt.m_loc;
}

void Snake::Segment::MoveBy(const Location& loc)
{
	assert((abs(loc.x) + abs(loc.y)) == 1);
	m_loc.Add(loc);
}

void Snake::Segment::Draw(Board& brd)
{
	brd.DrawCell(m_loc, m_c);
}
