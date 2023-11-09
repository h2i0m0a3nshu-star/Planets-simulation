#pragma once
#include <raylib.h>
#include <cmath>

class source
{
	private:
		Vector2 pos;
		float strength;
	public:
		source(float pos_x, float pos_y, float strength);
		void draw_source();
		float get_strength() const;
		Vector2 get_pos() const;
};

class particle 
{
	private:
		Vector2 pos, vel;
	public:
		particle(float pos_x, float pos_y, float vel_x, float vel_y);
		void draw_particle();
		void update_physics(source &s);
};