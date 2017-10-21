#include <DashObj.h>
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/text.h"
#include "cinder/Font.h"

using namespace ci;
using namespace ci::app;
using namespace std;

DashObj::DashObj()
{
}

DashObj::~DashObj()
{

}

void DashObj::setup()
{
	mFont = ci::Font("Calibri", mFontSize);
	mTextColor = Color::white();
	mBarColor = Color(1.f, 0, 0);
}

void DashObj::draw()
{
	gl::color(mBarColor);
	gl::lineWidth(5);
	gl::drawStrokedCircle(getWindowCenter(), 50);

	gl::color(mTextColor);
	glPushMatrix();
	glTranslatef(Vec3f( getWindowCenter().x-mFontSize/1.5f, 
						getWindowCenter().y-mFontSize/2.f, 
						0));
	ci::gl::draw(mTexture);
	glPopMatrix();
}

void DashObj::update(float input)
{
	mPercentage = input;
	ci::TextBox textBox;
	textBox = ci::TextBox().font(mFont)
							.size(ci::Vec2i(ci::TextBox::GROW, ci::TextBox::GROW))
							.text(to_string(int(ceil(mPercentage*100))))
							.premultiplied();
	mTexture = textBox.render();
}

