#include "Walker.h"
#include "Vehicle.h"
#include "SteeringBehavior.h"
#include <random>


Vehicle* ship = new Vehicle(300, 200);
enum Speed
{
	slow = 3, 
	normal = 2,
	fast = 1
};
Walker::Walker(int x, int y) 
{
  _x = x;
  _y = y;
  
}

void Walker::update() 
{
	Vector2D* mouse = new Vector2D(0, 0);

	ship->Arrive(mouse, 0);

	Vector2D* force = new Vector2D(0, 0);

	ship->addForce(force);
	ship->Update();

	delete(mouse);
	delete(force);
}

void Walker::draw(SDL_Renderer* renderer)
{
	ship->Draw(renderer);
}
