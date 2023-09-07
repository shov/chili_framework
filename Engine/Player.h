#pragma once

#include "Colors.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "Mouse.h"

class Player {
public:
	int x = Graphics::ScreenWidth / 2 - width / 2;
	int y= Graphics::ScreenHeight / 2 - height / 2;
	static constexpr int width = 50;
	static constexpr int height = 50;
	Color color;
public:
	Player();
	void Update(const Keyboard& kbd, const Mouse& mouse);
	void Render(Graphics& gfx) const;
private:
	bool dragging = false;
	int mdx = 0;
	int mdy = 0;
};