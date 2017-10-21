#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include <DashObj.h>
#include "cinder/audio/MonitorNode.h"
#include "cinder/audio/Context.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class f7_dashApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
private:
	void setupInput();

	DashObj mDash;
	ci::audio::InputDeviceNodeRef mInput;
	shared_ptr<ci::audio::MonitorNode> mMonitor;
};

void f7_dashApp::setup()
{
	setupInput();
	mDash.setup();
}

void f7_dashApp::setupInput()
{
	auto ctx = audio::Context::master();
	mInput = ctx->createInputDeviceNode();
	auto format = audio::MonitorSpectralNode::Format().windowSize(4096);
	mMonitor = ctx->makeNode(new audio::MonitorNode(format));
	mInput >> mMonitor;
	//Microphone (Realtek High Definition Audio)
	mInput->enable();
	ctx->enable();

	
}

void f7_dashApp::mouseDown( MouseEvent event )
{
}

void f7_dashApp::update()
{
	console() << mMonitor->getVolume() << endl;
	mDash.update(mMonitor->getVolume());
}

void f7_dashApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
	mDash.draw();
}

CINDER_APP_NATIVE( f7_dashApp, RendererGl )
