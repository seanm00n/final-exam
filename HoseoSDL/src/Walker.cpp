#include "Walker.h"
#include "Vehicle.h"
#include "SteeringBehavior.h"
#include <random>
#include <iostream>

using namespace std;

Vehicle* ship = new Vehicle(300, 200);
Walker::Walker(int x, int y) 
{
  _x = x;
  _y = y;
}

void Walker::update() 
{
	Vector2D* mouse = new Vector2D(0, 0);

	ship->Arrive(mouse);

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
