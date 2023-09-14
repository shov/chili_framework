/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

#include <cmath>
#include <algorithm>
#include <random>
#include <chrono>


Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	rng(std::random_device()()),
	snk(nullptr)
{
	std::uniform_int_distribution<int> yDist(0, brd.GetHeight() - 1);
	std::uniform_int_distribution<int> xDist(0, brd.GetWidth() - 1);

	Location snakeInit = { xDist(rng), yDist(rng) };
	snk = new Snake(snakeInit);
	snk->Grow();
	Location l = { 1, 1 };
	snk->MoveBy(l);
}

Game::~Game()
{
	delete snk;
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_LEFT) == true)
	{
		Location loc = { -1, 0 };
		snk->MoveBy(loc);
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT) == true)
	{
		Location loc = { 1, 0 };
		snk->MoveBy(loc);
	}
	else if (wnd.kbd.KeyIsPressed(VK_UP) == true)
	{
		Location loc = { 0, -1 };
		snk->MoveBy(loc);
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN) == true)
	{
		Location loc = { 0, 1 };
		snk->MoveBy(loc);
	}

}

void Game::ComposeFrame()
{
	snk->Draw(brd);

}

