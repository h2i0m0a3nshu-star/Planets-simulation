#include "Game.h"
int main()
{
	const int h = 800,w = 1000;
	Game g(w,h,"Gravity");
	while (!g.should_close())
	{
		g.tick();
	}
	return 0;
}