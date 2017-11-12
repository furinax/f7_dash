#include "..\include\Tachometer.h"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Tachometer::Tachometer()
{
}


Tachometer::~Tachometer()
{
}

void Tachometer::draw()
{
	gl::lineWidth(1);
	gl::color(mBarColor);

	gl::pushMatrices();
	gl::translate(Vec3f(getWindowCenter().x,
		getWindowCenter().y,
		0));
	gl::begin(GL_TRIANGLE_STRIP);
	for (float i = 0; i < mInput * 2*M_PI; i += 2*M_PI/360)
	{
		gl::vertex(mOuterRadius * sin(i), -mOuterRadius * cos(i));
		gl::vertex(mInnerRadius * sin(i), -mInnerRadius * cos(i));
	}
	gl::end();

	if (mInput >= 1.f && sin(getElapsedSeconds()*10) > 0)
	{
		gl::lineWidth(5);
		gl::drawStrokedCircle(Vec2f(0,0), 1.1f * mOuterRadius, 100);

		gl::lineWidth(3);
		gl::drawStrokedCircle(Vec2f(0, 0), 1.2f * mOuterRadius, 100);
	}
	gl::popMatrices();
}

void Tachometer::update(float input)
{
	mInput = 3 * input;
	if (mInput < .3f)
		mBarColor = Color(.25f, 1.f, .25f);
	else if (mInput < .6f)
		mBarColor = Color(.9f, 1.f, .1f);
	else
		mBarColor = Color(1.f, 0.f, 0.f);
	
}
