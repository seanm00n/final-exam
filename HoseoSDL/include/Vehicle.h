#pragma once
#include "Vector2D.h"
#include "main.h"
using namespace std;
class Vehicle {
public:
	Vector2D* m_acc;
	Vector2D* m_vel;
	Vector2D* m_loc;
	Vector2D* m_t1;
	Vector2D* m_t2;
	Vector2D* m_t3;
	float m_maxSpeed;

	Vehicle(float x, float y);
	Vector2D Arrive(Vector2D* mouse, float num);
	Vector2D Evade();
	void addForce(Vector2D* force);
	void Update();
	void Draw(SDL_Renderer* renderer);
};