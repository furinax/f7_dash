#pragma once

#include "cinder\Color.h"

class Tachometer
{
public:
	Tachometer();
	~Tachometer();

	void update(float input);
	void draw();

private:
	float mInput = 0.f;
	float mInnerRadius=80.f;
	float mOuterRadius=100.f;
	ci::Color mBarColor;
};

