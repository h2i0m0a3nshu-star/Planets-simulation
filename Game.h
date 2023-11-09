#pragma once
#include <raylib.h>
#include <iostream>
#include "Entity.h"
using namespace std;

class Game
{
public:
	Game(int width, int height, string title);
	bool should_close() const;
	void tick();
	~Game() noexcept;
private:
	source s;
	particle p,p1,p2;
	void draw();
	void update();
};