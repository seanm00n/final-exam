#pragma once
#include "Vector2D.h"
#include "main.h"
using namespace std;
class Vehicle {
public:
	Vector2D* m_acc;
	Vector2D* m_vel;
	Vector2D* m_loc;
	float m_maxSpeed;

	Vector2D Arrive(Vector2D* mouse, int num) {}
	Vector2D Evade() {}
	void addForce(Vector2D* force) {}
	void Update() {}
	void Draw(SDL_Renderer* renderer) {}
};