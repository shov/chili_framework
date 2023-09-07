#include "Player.h"

void Player::Update(const Keyboard& kbd, const Mouse& mouse)
{
	auto lmb = mouse.LeftIsPressed();
	
	int mx = mouse.GetPosX();
	int my = mouse.GetPosY();
	bool mouseOverPlayer = mx >= x && mx <= x + width && my >= y && my <= y + height;

	if (!dragging && lmb && mouseOverPlayer) {
		mdx = mx - x;
		mdy = my - y;
		dragging = true;
	}

	if (dragging && !lmb) {
		dragging = false;
	}

	if (dragging) {
		x = mx - mdx;
		y = my - mdy;
	}

	if (x + width >= Graphics::ScreenWidth - 1) {
		x = Graphics::ScreenWidth - 1 - width;
	}

	if (x < 0) {
		x = 0;
	}

	if (y + height >= Graphics::ScreenHeight - 1) {
		y = Graphics::ScreenHeight - 1 - height;
	}

	if (y < 0) {
		y = 0;
	}
}

Player::Player()
	: color(255, 100, 140)
{
}

void Player::Render(Graphics& gfx) const
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			gfx.PutPixel(x + i, y + j, color);
		}
	}
}
