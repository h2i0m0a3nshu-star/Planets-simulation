#include "Game.h"

Game::Game(int width, int height, string title)
	:s(400, 400, 2),
	p(300, 600, 1, 10),
	p1(200, 300, 5, 20),
	p2(300, 400, 5, 30)
{
	InitWindow(width, height, title.c_str());
	SetTargetFPS(60);
}

bool Game::should_close() const
{
	return WindowShouldClose();
}

void Game::tick()
{
	BeginDrawing();
	update();
	draw();
	EndDrawing();
}

Game::~Game()
{
	CloseWindow();
}

void Game::draw()
{
	ClearBackground(BLACK);
	DrawRectangleLines(20, 20, 740, 740, BLUE);
	s.draw_source();
	p.draw_particle();
	p1.draw_particle();
	p2.draw_particle();
}

void Game::update()
{
	p.update_physics(s);
	p1.update_physics(s);
	p2.update_physics(s);
}