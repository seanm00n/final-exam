#include <math.h>
#include "Vector2D.h"
#include "Vehicle.h"
#include "main.h"
using namespace std;
class Vehicle {
public:
	Vector2D* m_acc = new Vector2D(0, 0);
	Vector2D* m_vel = new Vector2D(0, 0);
	Vector2D* m_loc = new Vector2D(0, 0);
	double m_maxSpeed = 8;
	
	Vector2D Arrive(Vector2D* mouse, int num) {
		Vector2D force = *mouse - *m_loc;
		const float dist = force.length();
		if (dist > 0) {
			float decel = 0.3;
			double speed = dist /num*decel;
			speed = fmin(speed, m_maxSpeed);
			Vector2D desire = force * speed/dist;
			return desire - *m_vel;
		}
		return Vector2D(0, 0);
	}
	void addForce(Vector2D* force) {
		*m_acc += *force;
	}
	void Update() {
		*m_vel += *m_acc;
		m_vel->limit(m_maxSpeed);
		*m_loc += *m_vel;
	}
	void Draw(SDL_Renderer* renderer) {
		filledTrigonColor(renderer, /*세 점의 좌표값*/ 0xffffffff);
	}
};