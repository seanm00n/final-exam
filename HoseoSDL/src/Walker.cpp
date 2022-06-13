#include "Walker.h"
#include "Vehicle.h"
#include "SteeringBehavior.h"
#include "InputHandler.h"
#include <random>
#include <iostream>

using namespace std;

Vehicle* ship = new Vehicle(300, 200);
Vector2D* mouse;
Walker::Walker(int x, int y) 
{
  _x = x;
  _y = y;
}

void Walker::update() 
{
	mouse = TheInputHandler::Instance()->getMousePosition();
	Vector2D force = ship->Arrive(mouse);
	ship->addForce(&force);
	//ship->Rotate(seta);
	ship->Update();
}

void Walker::draw(SDL_Renderer* renderer)
{
	ship->Draw(renderer);
}
