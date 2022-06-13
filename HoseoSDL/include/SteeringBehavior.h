#pragma once
#include "Vector2D.h"
#include "BaseGameEntity.h"

class SteeringBehavior {
public:
	SteeringBehavior();
	void Hide(const Vehicle* hunter, const vector<BaseGameEntity*>& obstacles);
	void GetHidePos(const Vector2D& posOb, const double radiusOb, const Vector2D& posHunter);
};