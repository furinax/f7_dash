#include "cinder/gl/Texture.h"
#include "cinder/Font.h"

class DashObj
{
public:
	DashObj();
	~DashObj();

	void setup();
	void draw();
	void update(float input);

private:
	float mPercentage; // value from 0 to 1, where 1 is the maximum microphone input
	ci::Font mFont;
	ci::gl::Texture mTexture;
	float mFontSize = 50;

	ci::Color mBarColor;
	ci::Color mTextColor;
};