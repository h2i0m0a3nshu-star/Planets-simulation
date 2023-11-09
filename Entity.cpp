#include "Entity.h"

source::source(float pos_x, float pos_y, float strength)
{
	pos.x = pos_x;
	pos.y = pos_y;
	this->strength = strength;
}

void source::draw_source()
{
	DrawCircle(pos.x, pos.y, 20, WHITE);
}

float source::get_strength() const
{
	return strength;
}

Vector2 source::get_pos() const
{
	return pos;
}

particle::particle(float pos_x, float pos_y, float vel_x, float vel_y)
{
	pos.x = pos_x;
	pos.y = pos_y;
	vel.x = vel_x;
	vel.y = vel_y;
	
}

void particle::draw_particle()
{
	DrawCircle(pos.x, pos.y, 10, WHITE);
	
}

void particle::update_physics(source& s)
{
	float dist_x = s.get_pos().x - pos.x;
	float dist_y = s.get_pos().y - pos.y;

	float dist = sqrt(pow(dist_x,2)+pow(dist_y,2));
	float inverse = 1.0f / dist;
	
	float sqrd_inv = pow(inverse, 2);

	float normalize_x = dist_x / inverse;
	float normalize_y = dist_y / inverse;

	float acc_x = normalize_x * s.get_strength() * sqrd_inv;
	float acc_y = normalize_y * s.get_strength() * sqrd_inv;

	vel.x += acc_x;
	vel.y += acc_y;

	pos.x += vel.x;
	pos.y += vel.y;

}


