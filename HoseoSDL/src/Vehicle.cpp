#include <math.h>
#include "Vector2D.h"
#include "Vehicle.h"
#include "main.h"
using namespace std;

Vehicle::Vehicle(float x, float y) {
	m_acc = new Vector2D(0, 0);
	m_vel = new Vector2D(0, 0);
	m_loc = new Vector2D(x, y);
	m_t1 = new Vector2D(x+6, y);
	m_t2 = new Vector2D(x-6, y-3);
	m_t3 = new Vector2D(x-6, y+3);
	m_maxSpeed = 8;
}
Vector2D Vehicle::Arrive(Vector2D* mouse) {
	Vector2D force = *mouse - *m_loc;
	const float dist = force.length();
	if (dist > 0) {
		float decel = 0.3;
		double speed = dist / Speed::slow * decel;//?
		speed = fmin(speed, m_maxSpeed);
		Vector2D desire = force * speed/dist;
		return desire - *m_vel;
	}
	return Vector2D(0, 0);
}
void Vehicle::Rotate(float seta) {
	//삼각형의 세 점의 좌표를 같은 값 만큼 이동
	*m_t1 = Vector2D(m_t1->getX() * cos(seta) - m_t1->getY() * sin(seta), m_t1->getX() * sin(seta) + m_t1->getY() * cos(seta));
	*m_t2 = Vector2D(m_t2->getX() * cos(seta) - m_t2->getY() * sin(seta), m_t2->getX() * sin(seta) + m_t2->getY() * cos(seta));
	*m_t3 = Vector2D(m_t3->getX() * cos(seta) - m_t3->getY() * sin(seta), m_t3->getX() * sin(seta) + m_t3->getY() * cos(seta));
}
void Vehicle::addForce(Vector2D* force) {
	*m_acc += *force;
}
void Vehicle::Update() {
	*m_vel += *m_acc;
	m_vel->limit(m_maxSpeed);
	*m_loc += *m_vel;
}
void Vehicle::Draw(SDL_Renderer* renderer) {
	//filledTrigonColor(renderer, /*세 점의 좌표값*/ 0xffffffff);
	filledCircleColor(renderer, m_loc->getX(), m_loc->getY(), 3, 0xffffffff);//임시
}